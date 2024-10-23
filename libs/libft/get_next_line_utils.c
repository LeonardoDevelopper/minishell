/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:50:32 by lleodev           #+#    #+#             */
/*   Updated: 2024/06/20 13:50:35 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_custom(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen_custom(s);
	if (start >= s_len)
		return (ft_strdup_custom(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strlen_custom(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_custom(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup_custom(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen_custom(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_custom(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_str = (char *)malloc(sizeof(char) * (ft_strlen_custom(s1)
				+ ft_strlen_custom(s2) + 1));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined_str[ft_strlen_custom(s1) + i] = s2[i];
		i++;
	}
	joined_str[ft_strlen_custom(s1) + ft_strlen_custom(s2)] = '\0';
	return (joined_str);
}
