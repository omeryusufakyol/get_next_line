/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:18:45 by oakyol            #+#    #+#             */
/*   Updated: 2024/12/01 04:18:21 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*get_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*new_remainder;

	i = count_to_new_line(remainder);
	if (!remainder[i] && remainder)
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc(str_len(remainder) - i + 1);
	if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}
	i++;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*get_the_line(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	line = malloc(count_to_new_line(remainder) + 2);
	if (!line)
	{
		free(remainder);
		return (NULL);
	}
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_remainder(int fd, char *remainder)
{
	int		i;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(remainder);
		return (NULL);
	}
	i = 1;
	while (!check_new_line(remainder) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((!remainder && i <= 0) || i == -1)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		buffer[i] = '\0';
		remainder = add_str(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		return (0);
	}
	remainder = get_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_the_line(remainder);
	remainder = get_new_remainder(remainder);
	return (line);
}
