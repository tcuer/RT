/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_limit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:33:57 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/10 16:33:58 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone		*cone_limit3(t_cone *cone)
{
	cone->limit.f2.y = cone->pos.y - cone->length;
	cone->limit.f4.x = cone->pos.x - cone->length;
	cone->limit.f6.z = cone->pos.z - cone->length;
	cone->limit.f1.y = cone->pos.y + cone->length;
	cone->limit.f3.x = cone->pos.x + cone->length;
	cone->limit.f5.z = cone->pos.z + cone->length;
	return (cone);
}

t_cone		*cone_limit2(t_cone *cone)
{
	if (cone->simple == 1)
	{
		if (cone->dir.y > 0 || cone->dir.x > 0 || cone->dir.z > 0)
		{
			cone->limit.f2.y = cone->pos.y;
			cone->limit.f4.x = cone->pos.x;
			cone->limit.f6.z = cone->pos.z;
			cone->limit.f1.y = cone->pos.y + cone->length;
			cone->limit.f3.x = cone->pos.x + cone->length;
			cone->limit.f5.z = cone->pos.z + cone->length;
		}
		if (cone->dir.y < 0 || cone->dir.x < 0 || cone->dir.z < 0)
		{
			cone->limit.f1.y = cone->pos.y;
			cone->limit.f3.x = cone->pos.x;
			cone->limit.f5.z = cone->pos.z;
			cone->limit.f2.y = cone->pos.y - cone->length;
			cone->limit.f4.x = cone->pos.x - cone->length;
			cone->limit.f6.z = cone->pos.z - cone->length;
		}
	}
	else
		cone = cone_limit3(cone);
	return (cone);
}

t_cone		*cone_limit(t_vec ray, t_vec origin,
					t_cone *cone, double delta)
{
	cone->limit.f1 = cone->pos;
	cone->limit.f2 = cone->pos;
	cone->limit.f3 = cone->pos;
	cone->limit.f4 = cone->pos;
	cone->limit.f5 = cone->pos;
	cone->limit.f6 = cone->pos;
	cone = cone_limit2(cone);
	cone->limit.t1 = vec_dot_product(vec_minus(cone->limit.f1,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	cone->limit.t2 = vec_dot_product(vec_minus(cone->limit.f2,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	cone->limit.t3 = vec_dot_product(vec_minus(cone->limit.f3,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	cone->limit.t4 = vec_dot_product(vec_minus(cone->limit.f4,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	cone->limit.t5 = vec_dot_product(vec_minus(cone->limit.f5,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	cone->limit.t6 = vec_dot_product(vec_minus(cone->limit.f6,
		vec_add(origin, vec_multiply(ray, delta))), cone->dir);
	return (cone);
}

int			cone_limit4(t_cone *cone)
{
	if (cone->dir.y > 0 && (cone->limit.t1 < 0 || cone->limit.t2 > 0))
		return (1);
	if (cone->dir.x > 0 && (cone->limit.t3 < 0 || cone->limit.t4 > 0))
		return (1);
	if (cone->dir.z > 0 && (cone->limit.t5 < 0 || cone->limit.t6 > 0))
		return (1);
	if (cone->dir.y < 0 && (cone->limit.t2 < 0 || cone->limit.t1 > 0))
		return (1);
	if (cone->dir.x < 0 && (cone->limit.t4 < 0 || cone->limit.t3 > 0))
		return (1);
	if (cone->dir.z < 0 && (cone->limit.t6 < 0 || cone->limit.t5 > 0))
		return (1);
	return (0);
}
