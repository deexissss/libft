/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimalint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:12:25 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/15 10:56:47 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(int nb)
{
	int	count;
	int	num;

	num = nb;
	count = 0;
	if (nb < 0)
	{
		count += 1;
		num *= -1;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

int	ft_printdecimal(int nb)
{
	int	num;

	num = nb;
	if (nb == INT_MIN)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		ft_printchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		ft_printdecimal(num / 10);
		ft_printdecimal(num % 10);
	}
	else
		ft_printchar(num + '0');
	return (count_digit(nb));
}

int	ft_printint(int nb)
{
	int	num;

	num = nb;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_printchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		ft_printint(num / 10);
		ft_printint(num % 10);
	}
	else
		ft_printchar(num + '0');
	return (count_digit(nb));
}
