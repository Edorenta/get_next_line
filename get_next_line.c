/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:04:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/12 13:58:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*get_fd(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
		if ((int)tmp->content_size == fd)
			return (tmp);
		else
			tmp = tmp->next;
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, (ft_lstnew("\0", fd)));
	tmp = *file;
	return (tmp);
}

char				*ft_straddchar(char *str, char c)
{
	char	*tmp;
	int		i;

	if (!str || !c)
		return (NULL);
	i = ft_strlen(str);
	tmp = ft_strnew(i + 1);
	tmp = ft_strcpy(tmp, str);
	free(str);
	tmp[i] = c;
	tmp[++i] = '\0';
	return (tmp);
}

int					strcpyto(char **dst, char *src, char c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[j] && j < i)
	{
		if (!(*dst = ft_straddchar(*dst, src[j])))
			return (0);
		j++;
	}
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*file;
	int					i;
	int					index;
	t_list				*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curr = get_fd(&file, fd);
	IS((*line = ft_strnew(1)));
	while ((index = read(fd, buf, BUFF_SIZE)))
	{
		buf[index] = '\0';
		IS((curr->content = ft_strjoin(curr->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (index < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = strcpyto(line, curr->content, '\n');
	if (i < (int)ft_strlen(curr->content))
		curr->content += (i + 1);
	else
		ft_strclr(curr->content);
	return (1);
}
