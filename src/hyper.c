/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:19:08 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/12 19:19:10 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_inter		hyper_inter_ret(t_object *object, t_hyper *hyper,
	t_ray ray, double delta)
{
	t_inter	inter;
	int		i;

	i = 0;
	inter.pos = get_vec_from_t(ray.pos, ray.dir, delta);
	inter.normal = get_hyper_normal(hyper, inter);
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.object = object;
	inter.reflection = hyper->reflexion;
	inter.refraction = hyper->refraction;
	if (hyper->length != 0)
	{
		i = hyper_limit4(hyper);
		if (i == 1)
			return (new_inter());
	}
	return (inter);
}

t_vec		get_hyper_normal(t_hyper *hyper, t_inter inter)
{
	t_vec	normal;
	t_vec	projection;

	projection = vec_minus(inter.pos, hyper->pos);
	normal = vec_minus(projection, vec_multiply(hyper->dir,
	vec_dot_product(projection, hyper->dir)));
	normal = vec_normalize(normal);
	return (normal);
}

t_delta		get_hyper_delta2(t_delta delta, t_object *obj)
{
	delta.delta = sqrt(delta.delta);
	delta.t1 = (-delta.b + delta.delta) / (2 * delta.a);
	delta.t2 = (-delta.b - delta.delta) / (2 * delta.a);
	if (obj->id == O_HYPER2)
		delta.t = delta.t1;
	else
		delta.t = delta.t2;
	return (delta);
}

t_delta		get_hyper_delta(t_hyper *hyper, t_vec ray, t_vec origin)
{
	t_delta		delta;
	t_vec		deltap;
	t_vec		tmp;

	deltap = vec_minus(origin, hyper->pos);
	tmp = vec_minus(ray, vec_multiply(hyper->dir,
				vec_dot_product(ray, hyper->dir)));
	delta.a = pow2(cos(hyper->alpha)) *
		vec_dot_product(tmp, tmp) - pow2(sin(hyper->alpha))
		* pow2(vec_dot_product(ray, hyper->dir));
	delta.b = 2 * pow2(cos(hyper->alpha)) * vec_dot_product(
			vec_minus(ray, vec_multiply(hyper->dir,
					vec_dot_product(ray, hyper->dir))),
			vec_minus(deltap, vec_multiply(hyper->dir,
					vec_dot_product(deltap, hyper->dir)))) - 2
		* pow2(sin(hyper->alpha)) * vec_dot_product(ray, hyper->dir)
				* vec_dot_product(deltap, hyper->dir);
	tmp = vec_minus(deltap, vec_multiply(hyper->dir,
				vec_dot_product(deltap, hyper->dir)));
	delta.c = pow2(cos(hyper->alpha))
		* vec_dot_product(tmp, tmp) - pow2(sin(hyper->alpha))
		* pow2(vec_dot_product(deltap, hyper->dir));
	delta.delta = hyper_limit3(hyper, delta);
	return (delta);
}

t_inter		hyper_inter(t_object *object, t_ray ray)
{
	t_hyper	*hyper;
	t_delta	delta;

	hyper = object->data;
	hyper->dir = vec_normalize(hyper->dir);
	delta = get_hyper_delta(hyper, ray.dir, ray.pos);
	if (delta.delta < 0)
		return (new_inter());
	else
		delta = get_hyper_delta2(delta, object);
	if (delta.t < 0)
		return (new_inter());
	hyper = hyper_limit(ray.dir, ray.pos, hyper, delta.t);
	return (hyper_inter_ret(object, hyper, ray, delta.t));
}
