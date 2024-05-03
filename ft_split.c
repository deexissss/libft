/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:25:56 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/01 14:12:39 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static size_t	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static void	ft_free(char **ptr, size_t size)
{
	while (size > 0)
		free(ptr[--size]);
	free(ptr);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**split(char const *s, char c, size_t words)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	while (i < words)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		ptr[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!ptr[i])
		{
			ft_free(ptr, i);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count(s, c);
	array = split(s, c, words);
	return (array);
}*/

int	count(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*str)
	{
		if (*str != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == c)
			i = 0;
		str++;
	}
	return (count);
}

char	*new_strdup(const char *str, int start, int finish)
{
	char	*new_word;
	int		i;

	i = 0;
	new_word = malloc(sizeof(char) * ((finish - start) + 1));
	while (start < finish)
	{
		new_word[i] = str[start];
		i++;
		start++;
	}
	new_word[i] = '\0';
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc(sizeof(char *) * (count(s, c) + 1));
	if (!split || !s)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = new_strdup(s, index, i);
			j++;
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *input_str = "Hello World! This is a test.";
    char **result;

    result = ft_split(input_str, ' ');

    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]); // Don't forget to free each word
        }

        free(result); // Free the array of words
    }
    else
    {
        printf("Memory allocation error or empty input string.\n");
    }

    return 0;
}
*/
