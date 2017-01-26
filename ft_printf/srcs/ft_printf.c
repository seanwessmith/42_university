/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:10:43 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/26 15:46:28 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>

int		debuff(t_algo *algo)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (algo->arg_str[i] != '0' && algo->arg_str[i] != ' '
			&& algo->arg_str[i] != '-' && algo->arg_str[i] != '+')
		return (0);
	while (algo->arg_str[i] != '0'
			&& algo->arg_str[i] != ' ' && algo->arg_str[i])
		i++;
	if (algo->arg_str[i] == '\0')
		return (0);
	while (algo->arg_str[i + 1] != '\0')
	{
		algo->arg_str[i] = algo->arg_str[i + 1];
		i++;
	}
	algo->arg_str[i] = '\0';
	return (1);
}

char	*ft_pad(char *str, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(0);
	while (i + (int)ft_strlen(str) < size)
	{
		ft_strcat(temp, "0");
		i++;
	}
	str = ft_strcat(temp, str);
	free(temp);
	return (str);
}

char	*ft_padend(char *str, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(0);
	str = ft_strcat(temp, str);
	while (i + (int)ft_strlen(str) < size)
	{
		ft_strcat(temp, "0");
		i++;
	}
	free(temp);
	return (str);
}

void	flipflag(t_algo *algo)
{
	int		i;

	i = 0;
	while (algo->arg_str[i])
	{
		if (algo->arg_str[i] == '0')
			algo->arg_str[i] = ' ';
		i++;
	}
}

void	arg_int(t_algo *algo)
{
	int						d;
	short int				h;
	signed char				hh;
	long					l;
	long long				ll;
	unsigned long long int	u;
	intmax_t				j;
	ssize_t					z;
	int						subtract;

	subtract = 0;
	if (algo->spec == 'u' || algo->spec == 'U')
	{
		if (algo->precision > algo->width
				|| (algo->precision == 0 && algo->width == 0))
			while ((int)ft_strlen(algo->arg_str)
					> algo->precision && debuff(algo))
				;
		if (algo->width > algo->precision)
			while ((int)ft_strlen(algo->arg_str)
					> algo->width && debuff(algo))
				;
		if (ft_findchr("jlh", algo->length[0]) || algo->spec == 'U')
			u = va_arg(algo->ap, unsigned long long int);
		else
			u = va_arg(algo->ap, unsigned int);
		ft_strcat(algo->arg_str, ft_itoau(u));
	}
	else if (ft_strequ(algo->length, "h"))
	{
		h = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoa(h));
	}
	else if (ft_strequ(algo->length, "hh"))
	{
		hh = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoa(hh));
	}
	else if (ft_strequ(algo->length, "l"))
	{
		l = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoal(l));
	}
	else if (ft_strequ(algo->length, "ll"))
	{
		ll = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoal(ll));
	}
	else if (ft_strequ(algo->length, "j"))
	{
		j = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoal(j));
	}
	else if (ft_strequ(algo->length, "z"))
	{
		z = va_arg(algo->ap, long long);
		ft_strcat(algo->arg_str, ft_itoal(z));
	}
	else
	{
		d = va_arg(algo->ap, int);
		if (algo->precision == -1 && d == 0)
			return ;
		if (algo->flag == '+' && d >= 0)
			ft_strncat(algo->arg_str, "+", 1);
		if (d < 0 && d >= -2147483647)
		{
			if (algo->arg_str[0] == '+' && algo->width == 0)
				algo->arg_str = ft_strnew(0);
			if (ft_lastchr(algo->arg_str) == ' ')
				algo->arg_str[ft_strlen(algo->arg_str) - 1] = '-';
			else if (algo->flag != '0')
			{
				ft_strcat(algo->arg_str, "-");
				algo->precision++;
			}
			else
				algo->arg_str[0] = '-';
			d *= -1;
		}
		if (algo->precision > (int)ft_strlen(ft_itoa(d)))
			flipflag(algo);
		ft_strcat(algo->arg_str, ft_pad(ft_itoal(d), algo->precision));
	}
	if (algo->precision > algo->width)
		while ((int)ft_strlen(algo->arg_str) > algo->precision && debuff(algo))
	;
	if (algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) > algo->width && debuff(algo))
			;
}

void	arg_str(t_algo *algo)
{
	wchar_t		*str;

	str = NULL;
	str = va_arg(algo->ap, wchar_t*);
	if (str && (algo->spec == 's' || algo->spec == 'S'))
	{
		if (algo->precision > 0)
			ft_strncat(algo->arg_str, (char*)str, algo->precision);
		else
			ft_strcat(algo->arg_str, (char*)str);
		if (algo->width > algo->precision)
			while ((int)ft_strlen(algo->arg_str)
					> algo->width && debuff(algo))
				;
		if (algo->precision > algo->width)
			while ((int)ft_strlen(algo->arg_str)
					> algo->precision && debuff(algo))
				;
		while (algo->precision-- > 0 && algo->arg_str[0] == '0')
			debuff(algo);
	}
	else
		ft_strcat(algo->arg_str, "(null)");
}

void	arg_char(t_algo *algo)
{
	char	c;

	c = va_arg(algo->ap, int);
	ft_chrcat(algo->arg_str, c);
	if (c == 0)
	{
		debuff(algo);
		algo->null_terminator = 1;
	}
	while (algo->precision-- > 0)
		debuff(algo);
	if (algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) > algo->width && debuff(algo))
			;
	if (algo->precision > algo->width)
		while ((int)ft_strlen(algo->arg_str) > algo->precision && debuff(algo))
			;
}

void	ft_strbeg(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strdup(s1);
	ft_strcpy(s1, s2);
	ft_strcat(s1, temp);
}

void	arg_hex(t_algo *algo)
{
	uintmax_t		j;
	unsigned long	l;
	unsigned int	ui;

	if (ft_strequ(algo->length, "j"))
	{
		j = va_arg(algo->ap, uintmax_t);
		ft_strcat(algo->arg_str, ft_strlower((ft_itoa_basel(j, 16))));
	}
	else if (ft_strequ(algo->length, "l") || ft_strequ(algo->length, "ll"))
	{
		l = va_arg(algo->ap, long);
		if (l != 0 && algo->flagh == '#')
			ft_strcat(algo->arg_str, "0x");
		ft_strcat(algo->arg_str, ft_strlower((ft_itoa_basel(l, 16))));
	}
	else
	{
		ui = va_arg(algo->ap, long long);
		if (algo->precision > (int)ft_strlen(ft_itoa(ui)))
			ft_pad(algo->arg_str, algo->precision);
		if (ui != 0 && algo->flagh == '#'
				&& algo->flag != '0')
			ft_strcat(algo->arg_str, "0x");
		if (ui == 0 && ft_lastchr(algo->arg_str) == 'x')
			algo->arg_str = "0\0";
		else if (algo->precision != -1)
			ft_strcat(algo->arg_str,
					ft_pad(ft_itoa_basel(ui, 16), algo->precision));
		if (ui != 0 && algo->flagh == '#' && algo->flag == '0')
		{
			algo->precision -= 2;
			algo->width -= 2;
		}
	}
	if (algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) > algo->width && debuff(algo))
			;
	if (algo->precision > algo->width)
		while ((int)ft_strlen(algo->arg_str) > algo->precision && debuff(algo))
			;
	if (ui != 0 && algo->flagh == '#' && algo->flag == '0')
		ft_strbeg(algo->arg_str, "0x");
	if (algo->spec == 'X')
		ft_strupper(algo->arg_str);
	else if (algo->spec == 'x')
		ft_strlower(algo->arg_str);
}

void	arg_octal(t_algo *algo)
{
	unsigned long	l;

	l = va_arg(algo->ap, long);
	if (algo->flagh == '#')
		ft_strcat(algo->arg_str, "0");
	if (algo->precision > (int)ft_strlen(ft_itoa(l)))
		ft_pad(algo->arg_str, algo->precision);
	if (algo->precision != -1)
		ft_strcat(algo->arg_str, ft_pad(ft_itoa_base(l, 8), algo->precision));
	if (algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) > algo->width && debuff(algo))
			;
	if (algo->precision > algo->width)
		while ((int)ft_strlen(algo->arg_str) > algo->precision && debuff(algo))
			;
	if (ft_strlen(algo->arg_str) == 0 && algo->flagh == '#')
		ft_strcat(algo->arg_str, "0");
}

void	find_width(t_algo *algo)
{
	if (ft_isdigit(algo->in[algo->in_i - 1]))
		algo->in_i--;
	while (ft_isdigit(algo->in[algo->in_i]))
	{
		algo->width *= 10;
		algo->width += algo->in[algo->in_i] - '0';
		algo->in_i++;
	}
	if (algo->in[algo->in_i] == '.')
	{
		algo->in_i++;
		while (ft_isdigit(algo->in[algo->in_i]))
		{
			algo->precision *= 10;
			algo->precision += algo->in[algo->in_i] - '0';
			algo->in_i++;
		}
		if (algo->precision == 0)
			algo->precision = -1;
	}
}

void	find_flag(t_algo *algo)
{
	algo->in_i++;
	while (ft_findchr(" +#0-*+", algo->in[algo->in_i])
			&& algo->in[algo->in_i] != '\0')
	{
		if (algo->in[algo->in_i + 1] == '+' && algo->flag == '+')
			ft_strcat(algo->arg_str, "+");
		if (algo->in[algo->in_i] == '#')
			algo->flagh = algo->in[algo->in_i];
		if (algo->in[algo->in_i] == '+' && algo->flag == '0')
			ft_strcat(algo->arg_str, "+");
		if (algo->in[algo->in_i] == '+' && algo->flag == '-')
			ft_strcat(algo->arg_str, "+");
		else if (!(algo->in[algo->in_i] == '0' && algo->flag == '-') &&
				(!(algo->in[algo->in_i] == ' ' && algo->flag == '+')) &&
				(!(algo->in[algo->in_i] == '+' && algo->flag == '0')) &&
				(algo->in[algo->in_i] != '#'))
			algo->flag = algo->in[algo->in_i];
		algo->in_i++;
	}
}

void	find_length(t_algo *algo)
{
	while (algo->in[algo->in_i] == 'h' && ++algo->in_i)
		ft_strcat(algo->length, "h");
	while (algo->in[algo->in_i] == 'l' && ++algo->in_i)
		ft_strcat(algo->length, "l");
	if (algo->in[algo->in_i] == 'j')
		ft_strcat(algo->length, "j");
	if (algo->in[algo->in_i] == 'z')
		ft_strcat(algo->length, "z");
	if (algo->in[algo->in_i] == 't')
		ft_strcat(algo->length, "t");
	if (ft_findchr("jzt", *(algo->length)))
		algo->in_i++;
}

void	run_width(t_algo *algo)
{
	if ((algo->flag == 0 || algo->flag == ' ' ||
				algo->flag == '+' ||
				algo->flag == '#') && algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) < algo->width)
			ft_strcat(algo->arg_str, " ");
	if (algo->flag == '0' && algo->width > algo->precision)
		while ((int)ft_strlen(algo->arg_str) < algo->width)
			ft_strcat(algo->arg_str, "0");
	if (algo->precision != 0 && algo->precision > algo->width)
		while ((int)ft_strlen(algo->arg_str) < algo->precision)
			ft_strcat(algo->arg_str, "0");
}

void	find_spec(t_algo *algo)
{
	while (algo->in[algo->in_i] == ' ')
		algo->in_i++;
	if (algo->in[algo->in_i] == '%')
	{
		run_width(algo);
		ft_strrcat(algo->arg_str, "%", algo->width - 1);
	}
	if (algo->in[algo->in_i] == 's'
			|| algo->in[algo->in_i] == 'S')
		algo->spec = algo->in[algo->in_i];
	if (algo->in[algo->in_i] == 'd' || algo->in[algo->in_i] == 'D'
			|| algo->in[algo->in_i] == 'i' ||
			algo->in[algo->in_i] == 'u' || algo->in[algo->in_i] == 'U')
		algo->spec = algo->in[algo->in_i];
	if (algo->in[algo->in_i] == 'c')
		algo->spec = algo->in[algo->in_i];
	if (algo->in[algo->in_i] == 'x'
			|| algo->in[algo->in_i] == 'X')
		algo->spec = algo->in[algo->in_i];
	if (algo->in[algo->in_i] == 'o'
			|| algo->in[algo->in_i] == 'O')
		algo->spec = algo->in[algo->in_i];
}

void	run_flag(t_algo *algo)
{
	if (algo->flag == ' ' && algo->spec != 0)
		ft_strncat(algo->arg_str, " ", 1);
}

void	run_spec(t_algo *algo)
{
	if (algo->spec == 's' || algo->spec == 'S')
		arg_str(algo);
	if (algo->spec == 'd' || algo->spec == 'D' ||
			algo->spec == 'i' || algo->spec == 'u' || algo->spec == 'U')
		arg_int(algo);
	if (algo->spec == 'c')
		arg_char(algo);
	if (algo->spec == 'x' || algo->spec == 'X')
		arg_hex(algo);
	if (algo->spec == 'o' || algo->spec == 'O')
		arg_octal(algo);
}

void	integrate(t_algo *algo)
{
	if (algo->flag != 0)
		run_flag(algo);
	if (algo->width != 0 || algo->precision != 0)
		run_width(algo);
	if (algo->spec != 0)
		run_spec(algo);
	algo->width -= ft_strlen(algo->arg_str);
	while (algo->flag == '-' && (algo->width)-- > 0)
		ft_strncat(algo->arg_str, " ", 1);
}

void	nucleus(t_algo *algo)
{
	while (algo->in[algo->in_i] != '\0')
	{
		if (algo->in[algo->in_i] != '%')
		{
			ft_strncat(algo->out_str, &(algo->in[algo->in_i]), 1);
			ft_putchar(algo->in[algo->in_i]);
		}
		if (algo->in[algo->in_i] == '%')
		{
			find_flag(algo);
			find_width(algo);
			find_length(algo);
			find_spec(algo);
			integrate(algo);
			ft_putstr(algo->arg_str);
			if (algo->spec == 'c' && algo->null_terminator == 1)
			{
				ft_putchar('\0');
				ft_strcat(algo->arg_str, "0");
			}
			ft_strcat(algo->out_str, algo->arg_str);
			algo->null_terminator = 0;
			algo->flag = 0;
			algo->width = 0;
			algo->precision = 0;
			algo->spec = 0;
			algo->length = ft_strnew(0);
			algo->arg_str = ft_strnew(0);
		}
		algo->in_i++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	t_algo	algo;

	va_start(algo.ap, fmt);
	algo.in = (char *)fmt;
	algo.out_str = ft_strnew(0);
	algo.arg_str = ft_strnew(0);
	algo.length = ft_strnew(0);
	algo.null_terminator = 0;
	algo.in_i = 0;
	algo.flag = 0;
	algo.width = 0;
	algo.precision = 0;
	algo.spec = 0;
	nucleus(&algo);
	return (ft_strlen(algo.out_str));
}
