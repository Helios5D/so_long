/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:01:17 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 09:39:17 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*select_line(char **strptr)
{
	int		i;
	int		len;
	char	*selected_line;
	char	*str;

	i = 0;
	str = *strptr;
	len = is_new_line(str);
	if (!len)
		len = ft_strlen(str);
	selected_line = malloc((len + 1) * sizeof(char));
	if (!selected_line)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
	{
		selected_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		selected_line[i++] = '\n';
	selected_line[i] = '\0';
	*strptr = delete_first_chars(*strptr, i);
	return (selected_line);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	int			ret;

	if ((str && *str) && is_new_line(str))
		return (select_line(&str));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || BUFFER_SIZE < 0)
		return (ft_strdel(&buffer), NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0 && (!str))
			break ;
		else if (ret < 0)
			return (ft_strdel(&buffer), ft_strdel(&str), NULL);
		buffer[ret] = '\0';
		str = conc_strings(str, buffer);
		if (is_new_line(str))
			break ;
	}
	if ((ret == 0 && (!str || *str == '\0')))
		return (ft_strdel(&str), ft_strdel(&buffer), NULL);
	return (ft_strdel(&buffer), select_line(&str));
}

/*int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	return (0);
}*/
