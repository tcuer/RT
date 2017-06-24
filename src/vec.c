/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:32:02 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/06 10:32:03 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	vec_cross_product(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.y * b.z - b.y * a.z;
	ret.y = a.z * b.x - b.z * a.x;
	ret.z = a.x * b.y - b.x * a.y;
	return (ret);
}

t_vec	vec_multiply(t_vec a, double r)
{
	t_vec	ret;

	ret.x = a.x * r;
	ret.y = a.y * r;
	ret.z = a.z * r;
	return (ret);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec	vec_minus(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec	vec_normalize(t_vec vec)
{
	t_vec	normalized;
	double	norm;

	norm = vec_norm(vec);
	normalized.x = vec.x / norm;
	normalized.y = vec.y / norm;
	normalized.z = vec.z / norm;
	return (normalized);
}
