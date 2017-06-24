/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:35:49 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/10 16:35:51 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_inter		cone_inter_ret(t_object *object, t_cone *cone,
	t_ray ray, double delta)
{
	t_inter	inter;
	int		i;

	i = 0;
	inter.pos = get_vec_from_t(ray.pos, ray.dir, delta);
	inter.normal = get_cone_normal(cone, inter);
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.object = object;
	inter.reflection = cone->reflexion;
	inter.refraction = cone->refraction;
	if (cone->length != 0)
	{
		i = cone_limit4(cone);
		if (i == 1)
			return (new_inter());
	}
	return (inter);
}

t_vec		get_cone_normal(t_cone *cone, t_inter inter)
{
	t_vec	normal;
	t_vec	projection;

	projection = vec_minus(inter.pos, cone->pos);
	normal = vec_minus(projection, vec_multiply(cone->dir,
	vec_dot_product(projection, cone->dir)));
	normal = vec_normalize(normal);
	return (normal);
}

t_delta		get_cone_delta2(t_delta delta, t_object *obj)
{
	delta.delta = sqrt(delta.delta);
	delta.t1 = (-delta.b + delta.delta) / (2 * delta.a);
	delta.t2 = (-delta.b - delta.delta) / (2 * delta.a);
	if (obj->id == O_CONE2)
		delta.t = delta.t1;
	else
		delta.t = delta.t2;
	return (delta);
}

t_delta		get_cone_delta(t_cone *cone, t_vec ray, t_vec origin)
{
	t_delta		delta;
	t_vec		deltap;
	t_vec		tmp;

	deltap = vec_minus(origin, cone->pos);
	tmp = vec_minus(ray, vec_multiply(cone->dir,
				vec_dot_product(ray, cone->dir)));
	delta.a = pow2(cos(cone->alpha)) *
		vec_dot_product(tmp, tmp) - pow2(sin(cone->alpha))
		* pow2(vec_dot_product(ray, cone->dir));
	delta.b = 2 * pow2(cos(cone->alpha)) * vec_dot_product(
			vec_minus(ray, vec_multiply(cone->dir,
					vec_dot_product(ray, cone->dir))),
			vec_minus(deltap, vec_multiply(cone->dir,
					vec_dot_product(deltap, cone->dir)))) - 2
		* pow2(sin(cone->alpha)) * vec_dot_product(ray, cone->dir)
				* vec_dot_product(deltap, cone->dir);
	tmp = vec_minus(deltap, vec_multiply(cone->dir,
				vec_dot_product(deltap, cone->dir)));
	delta.c = pow2(cos(cone->alpha))
		* vec_dot_product(tmp, tmp) - pow2(sin(cone->alpha))
		* pow2(vec_dot_product(deltap, cone->dir));
	delta.delta = delta.b * delta.b - 4 * delta.a * delta.c;
	return (delta);
}

t_inter		cone_inter(t_object *object, t_ray ray)
{
	t_cone	*cone;
	t_delta	delta;

	cone = object->data;
	cone->dir = vec_normalize(cone->dir);
	delta = get_cone_delta(cone, ray.dir, ray.pos);
	if (delta.delta < 0)
		return (new_inter());
	else
		delta = get_cone_delta2(delta, object);
	if (delta.t < 0)
		return (new_inter());
	cone = cone_limit(ray.dir, ray.pos, cone, delta.t);
	return (cone_inter_ret(object, cone, ray, delta.t));
}
