/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:23:11 by emandret          #+#    #+#             */
/*   Updated: 2017/01/12 21:36:28 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

int				get_next_line(const int fd, char **line);
t_bool			has_newline(char **line, char **left, char **concat);
char			*cut_after_endl(char *buffer, char **concat);
int				read_until_endl(const int fd, char **line, char **left);


#endif
