/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:00:25 by inkahar           #+#    #+#             */
/*   Updated: 2023/12/19 17:07:41 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *file, char *buffer)
{
	int		reading;
	char	*tmp;

	reading = 1;
	while (!ft_strchr(file, '\n') && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
		{
			free(buffer);
			if (reading == 0)
				return (file);
			free(file);
			return (NULL);
		}
		buffer[reading] = '\0';
		tmp = file;
		file = ft_strjoin(file, buffer);
		free(tmp);
	}
	free(buffer);
	return (file);
}

char	*bufmalloc(int fd, char *file)
{
	char	*buffer;

	buffer = (malloc(BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	file = reader(fd, file, buffer);
	return (file);
}

char	*drain(char *file)
{
	int		i;
	char	*drained;

	i = 0;
	while (file[i] != '\n' && file[i])
	{
		i++;
	}
	if (file[i] == '\n')
		i++;
	drained = malloc(i + 1);
	if (!drained)
		return (NULL);
	drained[i] = '\0';
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		drained[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		drained[i] = '\n';
	return (drained);
}

char	*reposition(char *file)
{
	int		i;
	char	*next;

	i = 0;
	while (file[i] != '\n' && file[i])
	{
		i++;
	}
	if (file[i] == '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	next = ft_strdup(file + i);
	if (!next)
		return (NULL);
	free(file);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT32_MAX)
		return (NULL);
	file = bufmalloc(fd, file);
	if (!file)
		return (NULL);
	result = drain(file);
	file = reposition(file);
	return (result);
}
