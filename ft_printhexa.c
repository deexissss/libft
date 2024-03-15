/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:35:55 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/15 14:29:55 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_print_hexa(unsigned long nb, char type)
{
	char			*base;
	unsigned int	num;
	unsigned int	base_len;
	int				i;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)nb;
	base_len = ft_strlen(base);
	if (num > (base_len - 1))
		i += ft_print_hexa(num / base_len, type);
	i += ft_printchar(*(base + (num % base_len)));
	return (i);
}
