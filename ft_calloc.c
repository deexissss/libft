/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:55:54 by tjehaes           #+#    #+#             */
/*   Updated: 2024/02/26 17:13:31 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*addr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	addr = malloc(nitems * size);
	if (!addr)
	{
		return (NULL);
	}
	ft_bzero(addr, size * nitems);
	return (addr);
}
