/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:29:33 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/06 10:29:41 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vec_square_norm(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vec_rev_sign(t_vec vec)
{
	return (new_vec(-vec.x, -vec.y, -vec.z));
}

double	double_mult(double a, double b)
{
	double ret;

	ret = a * b;
	return (ret);
}

t_vec	vec_change(t_vec a, t_vec b)
{
	t_vec ret;

	ret.y = a.y;
	ret.x = b.x;
	ret.z = a.z;
	return (ret);
}
