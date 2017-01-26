/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:58:53 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/26 10:03:50 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoau(unsigned long long int n)
{
	int						len;
	unsigned long long int	temp;
	char					*str;

	len = 2;
	temp = n;
	while (temp /= 10)
		len++;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	len--;
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
