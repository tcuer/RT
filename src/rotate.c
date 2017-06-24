/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:08:34 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/08 16:08:36 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	ft_rotate_z(t_vec vec, double i)
{
	t_vec tmp;

	tmp.x = vec.x * cos(i) + vec.y * -sin(i);
	tmp.y = vec.x * sin(i) + vec.y * cos(i);
	tmp.z = vec.z;
	return (tmp);
}

t_vec	ft_rotate_x(t_vec vec, double i)
{
	t_vec tmp;

	tmp.x = vec.x;
	tmp.y = vec.y * cos(i) + vec.z * -sin(i);
	tmp.z = vec.y * sin(i) + vec.z * cos(i);
	return (tmp);
}

t_vec	ft_rotate_y(t_vec vec, double i)
{
	t_vec tmp;

	tmp.x = vec.x * cos(i) + vec.z * sin(i);
	tmp.y = vec.y;
	tmp.z = vec.x * -sin(i) + vec.z * cos(i);
	return (tmp);
}

double	pow2(double a)
{
	return (a * a);
}
