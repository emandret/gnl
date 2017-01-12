/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:23:11 by emandret          #+#    #+#             */
/*   Updated: 2017/01/12 21:36:34 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bool	has_newline(char **line, char **left, char **concat)
{
	char	*cut;

	if (*left != NULL && (cut = ft_strchr(*left, '\n')))
	{
		*cut = '\0';
		*line = *left;
		*left = ft_strdup(cut + 1);
		return (true);
	}
	*concat = ft_strnew(0);
	if (*left != NULL)
	{
		*concat = ft_strjoin_free(*concat, *left);
		ft_memdel((void**)left);
	}
	return (false);
}

char	*cut_after_endl(char *buffer, char **concat)
{
	char	*cut;

	if ((cut = ft_strchr(buffer, '\n')))
	{
		*cut = '\0';
		*concat = ft_strjoin_free(*concat, buffer);
		return (ft_strdup(cut + 1));
	}
	*concat = ft_strjoin_free(*concat, buffer);
	return (NULL);
}

int		read_until_endl(const int fd, char **line, char **left)
{
	char	*buffer;
	char	*concat;
	int		ret;

	if (has_newline(line, left, &concat))
		return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((*left = cut_after_endl(buffer, &concat)))
			break;
	}
	ft_memdel((void**)&buffer);
	if (ret > 0 || *concat != '\0')
	{
		*line = concat;
		return (1);
	}
	ft_memdel((void**)&concat);
	if (ret < 0)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*left = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	return (read_until_endl(fd, line, &left));
}
