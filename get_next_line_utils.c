/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:22:01 by oakyol            #+#    #+#             */
/*   Updated: 2024/12/01 04:20:04 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	count_to_new_line(char *remainder)
{
	int	i;

	if (!remainder)
		return (0);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	return (i);
}

char	*check_new_line(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*add_str(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined_str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joined_str = malloc(str_len(s1) + str_len(s2) + 1);
	if (!joined_str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		joined_str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		joined_str[i++] = s2[j++];
	joined_str[str_len(s1) + str_len(s2)] = '\0';
	free(s1);
	return (joined_str);
}
