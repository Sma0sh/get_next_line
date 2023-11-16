/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:32:41 by diteixei          #+#    #+#             */
/*   Updated: 2023/11/14 17:05:39 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*new;
	size_t			i;
	unsigned int	total;

	i = 0;
	total = nmemb * size;
	new = malloc(total);
	if (!new)
		return (NULL);
	while (total > 0)
	{
		new[i] = 0;
		total--;
		i++;
	}
	return ((void *)new);
}
