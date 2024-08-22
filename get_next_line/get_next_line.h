/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:03:30 by hdaher            #+#    #+#             */
/*   Updated: 2024/05/29 11:20:04 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// get_next_line.c

char	*get_next_line(int fd);
char	*select_line(char **str);

// get_next_line_utils.c

void	ft_strdel(char **str);
int		ft_strlen(char *str);
char	*conc_strings(char *str, char *buffer);
int		is_new_line(char *str);
char	*delete_first_chars(char *str, int a);

// buffer

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
