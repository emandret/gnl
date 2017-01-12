/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:23:11 by emandret          #+#    #+#             */
/*   Updated: 2017/01/12 22:00:18 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_this
{
	int				fd;
	char			*left;
	struct s_this	*next;
}					t_this;

int					get_next_line(const int fd, char **line);
t_bool				has_newline(t_this *this, char **line, char **concat);
char				*cut_after_endl(char *buffer, char **concat);
int					read_until_endl(t_this *this, char **line);
t_this				*load_new_fd(const int fd, t_this *first);

#endif
