/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:11:58 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/30 18:20:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_gcd(int x, int y)
{
	return ((x == 0) ? y : ft_gcd(y % x, x));
}
