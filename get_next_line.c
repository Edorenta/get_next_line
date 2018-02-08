/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:04:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 18:12:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		store_line(char **dst, char *src)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (src[i] != '\n')
		i++;
	IS((tmp = (char*)malloc(sizeof(char) * i + 1)));
	i = -1;
	while (src[++i] != '\n')
		tmp[i] = src[i];
	tmp[i] = '\0';
	*dst = tmp;
	while (src[++i])
	{
		src[j] = src[i];
		++j;
	}
	src[j] = '\0';
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*stack[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	size_t		found;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) || fd > OPEN_MAX)
		return (-1);
	stack[fd] = (stack[fd] == NULL ? (char *)malloc(sizeof(char)) : stack[fd]);
	if (stack[fd] && (ft_strchr(stack[fd], '\n') != 0))
		return (store_line(line, stack[fd]));
	while ((found = read(fd, buf, BUFF_SIZE)))
	{
		while (buf[found])
			buf[found++] = '\0';
		stack[fd] = ft_strjoinfree(stack[fd], buf, &stack[fd]);
		if (ft_strchr(stack[fd], '\n') != 0)
			return (store_line(line, stack[fd]));
	}
	if (stack[fd][0] != '\0')
	{
		IS((*line = (char *)malloc(ft_strlen(stack[fd]))));
		*line = ft_strcpy(*line, stack[fd]);
		ft_bzero(stack[fd], ft_strlen(stack[fd]));
		return (1);
	}
	return (0);
}
