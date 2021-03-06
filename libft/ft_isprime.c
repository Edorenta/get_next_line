/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:39:11 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:25:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int nb)
{
	int i;

	i = 3;
	if (nb <= 1 || (nb % 2 == 0 && nb > 2))
		return (0);
	while ((i += 2) < nb / 2)
		if (nb % i == 0)
			return (0);
	return (1);
}
