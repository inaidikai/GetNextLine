/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:25:16 by inkahar           #+#    #+#             */
/*   Updated: 2023/12/17 11:38:06 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ps1;
	char	*ptr;
	int		tlen;

	if (!s1 && !s2)
		return (0);
	tlen = ft_strlen(s1) + ft_strlen(s2);
	ps1 = malloc(sizeof(char) * (tlen + 1));
	if (!ps1)
		return (NULL);
	ptr = ps1;
	if (s1)
		while (*s1)
			*ptr++ = *s1++;
	if (s2)
		while (*s2)
			*ptr++ = *s2++;
	*ptr = '\0';
	return (ps1);
}
