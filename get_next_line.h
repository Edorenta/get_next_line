/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 18:12:42 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MEX
#  define OPEN_MAX 5000
# endif

# define BUFF_SIZE 42
# define IS(x) if (!x) return (0);

int		get_next_line(const int fd, char **line);

#endif
