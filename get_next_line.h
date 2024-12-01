/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:18:27 by oakyol            #+#    #+#             */
/*   Updated: 2024/12/01 04:20:59 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	str_len(char *str);
char	*check_new_line(char *str);
char	*add_str(char *s1, char *s2);
int		count_to_new_line(char *remainder);
char	*get_next_line(int fd);
char	*get_new_remainder(char *remainder);
char	*get_the_line(char *remainder);
char	*get_remainder(int fd, char *remainder);

#endif