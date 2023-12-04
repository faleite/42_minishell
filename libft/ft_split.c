/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:46:06 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:29:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count how many substrings (words) are in a string
 * @param s String to be counted
 * @param c Separator of substrings
 * @return Amount of substrings
*/
static int	count_wrds(char const *s, char c)
{
	size_t	i;
	size_t	n_wrds;

	n_wrds = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n_wrds++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n_wrds);
}

/**
 * @brief Copy substrings (words) of the a string, before copy, is created 
 * memory for each word.
 * @param s String to be copy
 * @param start Start of substring
 * @param end End of substring
 * @param len Length of substring
 * @return Copy of substring
*/
static char	*cpy_word(const char *s, int start, int end, int len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter
 * The array must end with a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 * allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	init;
	size_t	end;
	size_t	word;

	arr = (char **)malloc(sizeof(char *) * (count_wrds((char *)s, c) + 1));
	if (!(arr) || !(s))
		return (NULL);
	init = 0;
	word = 0;
	while (s[init])
	{
		if (s[init] != c && s[init] != '\0')
		{
			end = init;
			while (s[end] && s[end] != c)
				end++;
			arr[word++] = cpy_word(s, init, end, (end - init));
			init = end;
		}
		else
			init++;
	}
	arr[word] = NULL;
	return (arr);
}
