/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:01:35 by tjehaes           #+#    #+#             */
/*   Updated: 2024/02/27 12:36:58 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, *(s1 + (end - 1))))
		end--;
	trim = str_new(end - start);
	if (!trim)
		return (NULL);
	i = 0;
	while ((start + i) < end)
	{
		*(trim + i) = *(s1 + (start + i));
		i++;
	}
	*(trim + i) = '\0';
	return (trim);
}
