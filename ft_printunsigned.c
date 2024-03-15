/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:55:49 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/15 14:27:22 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse(char *str, int length)
{
	int		start;
	int		end;
	char	temps;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temps = str[start];
		str[start] = str[end];
		str[end] = temps;
		start++;
		end--;
	}
}

int	ft_get_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_printunsigned(unsigned int nb)
{
	int		index;
	int		digit;
	char	res[20];

	index = 0;
	digit = 0;
	if (nb == 0)
	{
		ft_printchar('0');
		return (1);
	}
	while (nb > 0)
	{
		digit = nb % 10;
		res[index++] = digit + '0';
		nb /= 10;
	}
	ft_reverse(res, index);
	write(1, res, index);
	return (index);
}
