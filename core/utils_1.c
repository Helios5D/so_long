/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:16:19 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/01 15:16:00 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_position	position(int x, int y)
{
	t_position	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	remove_nl(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
