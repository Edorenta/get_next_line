/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:05:07 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 11:11:24 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, char **ptr)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((str = ft_strnew(len)) == 0)
		return (NULL);
	str = ft_strcat(ft_strcpy(str, s1), s2);
	if (ptr)
		free(*ptr);
	return (str);
}
