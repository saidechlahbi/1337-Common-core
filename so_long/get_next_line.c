/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:41:35 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/22 02:21:51 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	while (i < size * nmemb)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

static char	*get_full_line(int fd, char *buffer)
{
	char	*full_line;
	char	*vessel;
	ssize_t	r;
	char	*s;

	r = 0;
	full_line = ft_strdup(buffer);
	if (!full_line)
		return (NULL);
	while (!ft_strchr(full_line, '\n'))
	{
		vessel = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
		if (!vessel)
			return (free(full_line), NULL);
		r = read(fd, vessel, BUFFER_SIZE);
		if (r == 0)
			return (free(vessel), full_line);
		else if (r < 0)
			return (free(full_line), free(vessel), NULL);
		s = full_line;
		full_line = ft_strjoin(full_line, vessel);
		free(s);
		free(vessel);
	}
	return (full_line);
}

static char	*get_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = 0;
	return (line);
}

static char	*get_rest_of_line(char *str)
{
	char	*rest;

	while (*str && *str != '\n')
		str++;
	if (*str == '\0')
		return (NULL);
	str++;
	if (*str == '\0')
		return (NULL);
	else
		rest = ft_strdup(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = NULL;
	line = NULL;
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	full_line = get_full_line(fd, buffer);
	free(buffer);
	buffer = NULL;
	if (!full_line)
		return (NULL);
	line = get_line(full_line);
	if (!line)
		return (free(full_line), NULL);
	buffer = get_rest_of_line(full_line);
	free(full_line);
	return (line);
}
