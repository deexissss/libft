/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:55:54 by tjehaes           #+#    #+#             */
/*   Updated: 2024/02/27 12:21:36 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbemb, size_t size)
{
	void	*memory;

	if (nbemb && size && nbemb > UINT_MAX / size)
		return (NULL);
	memory = malloc(nbemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, size * nbemb);
	return (memory);
}
