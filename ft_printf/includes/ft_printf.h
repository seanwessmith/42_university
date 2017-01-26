/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:05:36 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/24 15:33:15 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

typedef struct		s_algo {
	char			*in;
	char			flag;
	char			flagh;
	int				flagm;
	int				width;
	int				precision;
	char			*length;
	char			spec;
	char			*arg_str;
	int				null_terminator;
	int				in_i;
	char			*out_str;
	va_list			ap;
}					t_algo;

int				ft_printf(const char *format, ...);

#endif
