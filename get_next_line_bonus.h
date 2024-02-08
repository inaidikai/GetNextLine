/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:22:45 by inkahar           #+#    #+#             */
/*   Updated: 2023/12/19 17:18:01 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char const *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif