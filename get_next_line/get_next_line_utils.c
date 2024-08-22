/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:08:25 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 09:44:06 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*conc_strings(char *str, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc((ft_strlen(str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	ft_strdel(&str);
	return (new_str);
}

int	is_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*delete_first_chars(char *str, int n)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc((len - n + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < len - n)
	{
		new_str[i] = str[n + i];
		i++;
	}
	new_str[i] = '\0';
	ft_strdel(&str);
	return (new_str);
}
