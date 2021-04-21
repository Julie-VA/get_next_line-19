/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:14:13 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/18 18:35:05 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*save(char *str)
{
	char	*temp;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = ft_modstrlen(str, 1);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_modstrlen(str, 0) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

int	out(char **str, char **line, int count, int fd)
{
	int		i;
	char	*temp;

	if (!(str[fd]))
		return (-1);
	temp = malloc(sizeof(char) * (ft_modstrlen(str[fd], 1) + 1));
	if (!temp)
		return (-1);
	i = 0;
	while ((str[fd])[i] && (str[fd])[i] != '\n')
	{
		temp[i] = (str[fd])[i];
		i++;
	}
	temp[i] = '\0';
	*line = temp;
	str[fd] = save(str[fd]);
	if (count == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*str[FD_MAX];
	int				count;

	count = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!ft_strchr(str[fd], '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (-1);
		}
		buff[count] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
	}
	free(buff);
	return (out(str, line, count, fd));
}
