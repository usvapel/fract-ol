/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:22:23 by jpelline          #+#    #+#             */
/*   Updated: 2025/04/28 17:22:56 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_word_len(const char *str, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0' && str[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static size_t	ft_words_in_s(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (c == '\0')
	{
		if (*s != '\0')
			return (1);
		else
			return (0);
	}
	count = 0;
	i = 0;
	if (s[i] && s[i] != c)
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*ft_find_charset(const char **str, char c)
{
	char	*buffer;
	size_t	i;

	while (**str != '\0' && **str == c)
		(*str)++;
	buffer = (char *) malloc(ft_get_word_len(*str, c) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (**str != '\0' && **str != c)
	{
		buffer[i] = **str;
		i++;
		(*str)++;
	}
	buffer[i] = '\0';
	while (**str != '\0' && **str == c)
		(*str)++;
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_strs;
	size_t	i;

	if (!s)
		return (NULL);
	splitted_strs = malloc((ft_words_in_s(s, c) + 1) * sizeof(char *));
	if (!splitted_strs)
		return (NULL);
	i = 0;
	if (!*s || (c == '\0' && *s == '\0') || ft_words_in_s(s, c) == 0)
		return ((splitted_strs[0] = NULL), splitted_strs);
	while (*s)
	{
		splitted_strs[i] = ft_find_charset(&s, c);
		if (!splitted_strs[i])
		{
			ft_free(splitted_strs);
			return (NULL);
		}
		if (*s == '\0')
			break ;
		i++;
	}
	splitted_strs[i + 1] = NULL;
	return (splitted_strs);
}
