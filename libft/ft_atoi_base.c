/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:19 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:30:21 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inbase(char c, uint8_t base)
{
	if (base <= 10 && (c >= '0' && c <= '9'))
		return (1);
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int			ft_atoi_base(const char *str, uint8_t base)
{
	int	res;
	int	sign;

	res = 0;
	if (base <= 1 || base > 36)
		return (0);
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	sign = ((*str == '-') ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		res = ((*str - 'A' >= 0) ? (res * base + (*str - 'A' + 10))
				: res * base + (*str - '0'));
		str++;
	}
	return (res * sign);
}
