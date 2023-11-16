/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:44:41 by diteixei          #+#    #+#             */
/*   Updated: 2023/11/15 14:39:31 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_lines(int fd, char *text);
char	*get_lines(char *text);
char	*get_rests(char *text);

char	*get_next_line(int fd)
{
	static char	*text[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	text[fd] = read_lines(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = get_lines(text[fd]);
	text[fd] = get_rests(text[fd]); 
	return (line);
}

char	*read_lines(int fd, char *text)
{
	char	*guar;
	int		i; 

	guar = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (!ft_strchr(text, '\n') && (i > 0))
	{
		i = read(fd, guar, BUFFER_SIZE);
		if (i == -1)
			return (free(guar), free(text), NULL);
		guar[i] = '\0';
		text = ft_strjoin(text, guar);
	}
	free(guar);
	return (text);
}

char	*get_lines(char *text)
{
	int		i;
	char	*line;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_rests(char *text)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		return (free(text), NULL);
	rest = ft_calloc((ft_strlen(text) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (text[i])
		rest[j++] = text[i++];
	rest[j] = '\0';
	free(text);
	return (rest);
}

/*#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		ret = get_next_line(fd);
		printf("!LINE!-> %s\n", ret);
		free(ret);
		i++;
	}
	close(fd);
	return (0);
}*/
