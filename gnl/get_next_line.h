/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:59:18 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/06 10:20:52 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 555
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct	s_gnl{
	int			r;
	int			newline;
	int			buffnl;
	int			buffsize;
	char		*buffsave;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
