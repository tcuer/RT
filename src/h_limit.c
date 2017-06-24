/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_limit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:18:57 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/12 19:19:01 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		hyper_limit3(t_hyper *hyper, t_delta delta)
{
	if (hyper->simple == 0)
		delta.delta = delta.b * delta.b - 4 * delta.a * delta.c
	- double_mult(hyper->alpha, hyper->alpha);
	else
		delta.delta = delta.b * delta.b - 4 * delta.a * delta.c
	+ double_mult(hyper->alpha, hyper->alpha);
	return (delta.delta);
}

t_hyper		*hyper_limit2(t_hyper *hyper)
{
	hyper->limit.f2.y = hyper->pos.y - hyper->length;
	hyper->limit.f4.x = hyper->pos.x - hyper->length;
	hyper->limit.f6.z = hyper->pos.z - hyper->length;
	hyper->limit.f1.y = hyper->pos.y + hyper->length;
	hyper->limit.f3.x = hyper->pos.x + hyper->length;
	hyper->limit.f5.z = hyper->pos.z + hyper->length;
	return (hyper);
}

t_hyper		*hyper_limit(t_vec ray, t_vec origin,
					t_hyper *hyper, double delta)
{
	hyper->limit.f1 = hyper->pos;
	hyper->limit.f2 = hyper->pos;
	hyper->limit.f3 = hyper->pos;
	hyper->limit.f4 = hyper->pos;
	hyper->limit.f5 = hyper->pos;
	hyper->limit.f6 = hyper->pos;
	hyper = hyper_limit2(hyper);
	hyper->limit.t1 = vec_dot_product(vec_minus(hyper->limit.f1,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	hyper->limit.t2 = vec_dot_product(vec_minus(hyper->limit.f2,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	hyper->limit.t3 = vec_dot_product(vec_minus(hyper->limit.f3,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	hyper->limit.t4 = vec_dot_product(vec_minus(hyper->limit.f4,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	hyper->limit.t5 = vec_dot_product(vec_minus(hyper->limit.f5,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	hyper->limit.t6 = vec_dot_product(vec_minus(hyper->limit.f6,
		vec_add(origin, vec_multiply(ray, delta))), hyper->dir);
	return (hyper);
}

int			hyper_limit4(t_hyper *hyper)
{
	if (hyper->dir.y > 0 && (hyper->limit.t1 < 0 || hyper->limit.t2 > 0))
		return (1);
	if (hyper->dir.x > 0 && (hyper->limit.t3 < 0 || hyper->limit.t4 > 0))
		return (1);
	if (hyper->dir.z > 0 && (hyper->limit.t5 < 0 || hyper->limit.t6 > 0))
		return (1);
	if (hyper->dir.y < 0 && (hyper->limit.t2 < 0 || hyper->limit.t1 > 0))
		return (1);
	if (hyper->dir.x < 0 && (hyper->limit.t4 < 0 || hyper->limit.t3 > 0))
		return (1);
	if (hyper->dir.z < 0 && (hyper->limit.t6 < 0 || hyper->limit.t5 > 0))
		return (1);
	return (0);
}
