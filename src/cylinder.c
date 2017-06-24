/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:03:38 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/09 15:03:40 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec		get_cylinder_normal(t_cylinder *cylinder, t_inter inter)
{
	t_vec		normal;
	t_vec		projection;

	projection = vec_minus(inter.pos, cylinder->pos);
	normal = vec_minus(projection, vec_multiply(cylinder->dir,
		vec_dot_product(projection, cylinder->dir)));
	normal = vec_normalize(normal);
	return (normal);
}

static t_delta		get_cylinder_delta2(t_delta delta, t_object *obj)
{
	delta.delta = sqrt(delta.delta);
	if (delta.delta >= 0)
	{
		delta.t1 = (-delta.b - delta.delta) / (2 * delta.a);
		delta.t2 = (-delta.b + delta.delta) / (2 * delta.a);
		if (obj->id == O_CYLINDER2)
			delta.t = delta.t2;
		else
			delta.t = delta.t1;
	}
	return (delta);
}

static t_delta		get_cylinder_delta(t_cylinder *cylinder,
			t_vec ray, t_vec origin)
{
	t_delta			delta;
	t_vec			deltap;
	t_vec			tmp;

	deltap = vec_minus(origin, cylinder->pos);
	tmp = vec_minus(ray, vec_multiply(cylinder->dir,
		vec_dot_product(ray, cylinder->dir)));
	delta.a = vec_dot_product(tmp, tmp);
	delta.b = 2 * vec_dot_product(vec_minus(ray,
		vec_multiply(cylinder->dir,
		vec_dot_product(ray, cylinder->dir))), vec_minus(deltap,
		vec_multiply(cylinder->dir,
		vec_dot_product(deltap, cylinder->dir))));
	tmp = vec_minus(deltap, vec_multiply(cylinder->dir,
		vec_dot_product(deltap, cylinder->dir)));
	delta.c = vec_dot_product(tmp, tmp) - cylinder->rayon * cylinder->rayon;
	delta.delta = delta.b * delta.b - 4 * delta.a * delta.c;
	return (delta);
}

static t_inter		cylinder_inter_ret(t_object *object,
	t_cylinder *cylinder, t_ray ray, double delta)
{
	t_inter	inter;
	int		i;

	i = 0;
	inter.pos = get_vec_from_t(ray.pos, ray.dir, delta);
	inter.normal = get_cylinder_normal(cylinder, inter);
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.object = object;
	inter.reflection = cylinder->reflexion;
	inter.refraction = cylinder->refraction;
	if (cylinder->length != 0)
	{
		i = cylinder_limit2(cylinder);
		if (i == 1)
			return (new_inter());
	}
	return (inter);
}

t_inter				cylinder_inter(t_object *object, t_ray ray)
{
	t_cylinder		*c;
	t_inter			inter;
	t_delta			delta;

	inter = new_inter();
	c = object->data;
	c->dir = vec_normalize(c->dir);
	delta = get_cylinder_delta(c, ray.dir, ray.pos);
	if (delta.delta < 0)
		return (new_inter());
	else
		delta = get_cylinder_delta2(delta, object);
	if (delta.t < 0)
		return (new_inter());
	c = cylinder_limit(ray.dir, ray.pos, c, delta.t);
	return (cylinder_inter_ret(object, c, ray, delta.t));
}
