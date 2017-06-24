/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:36:14 by cluciani          #+#    #+#             */
/*   Updated: 2016/06/02 14:55:03 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	a;
	int	nb;

	a = 1;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
	|| *str == '\t' || *str == '\r' || *str == '\f')
		++str;
	if (*str == '-')
	{
		a = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (*str - '0');
		++str;
	}
	return (a * nb);
}
