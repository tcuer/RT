/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:07:45 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/10 17:07:48 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_inter				new_inter(void)
{
	t_inter t;

	t.distance = DBL_MAX - 1000;
	t.pos.x = 0;
	t.pos.y = 0;
	t.pos.z = 0;
	t.object = NULL;
	return (t);
}

static t_delta		get_sphere_delta2(t_delta delta, t_object *obj)
{
	delta.delta = sqrt(delta.delta);
	delta.t1 = (-delta.b + delta.delta);
	delta.t2 = (-delta.b - delta.delta);
	if (obj->id == O_SPHERE2)
		delta.t = delta.t1;
	else
		delta.t = delta.t2;
	return (delta);
}

static t_sphere		*sphere_limit(t_vec ray, t_vec origin,
		t_sphere *sphere, double delta)
{
	sphere->limit.f1 = sphere->pos;
	sphere->limit.f2 = sphere->pos;
	sphere->limit.f3 = sphere->pos;
	sphere->limit.t1 = vec_dot_product(vec_minus(sphere->limit.f1,
		vec_add(origin, vec_multiply(ray, delta))), sphere->dir);
	sphere->limit.t2 = vec_dot_product(vec_minus(sphere->limit.f2,
		vec_add(origin, vec_multiply(ray, delta))), sphere->dir);
	sphere->limit.t3 = vec_dot_product(vec_minus(sphere->limit.f2,
		vec_add(origin, vec_multiply(ray, delta))), sphere->dir);
	return (sphere);
}

static t_inter		sphere_inter_ret(t_object *obj, t_sphere *sphere,
				t_ray ray, t_delta delta)
{
	t_inter	inter;

	inter = new_inter();
	if (sphere->dir.y != 0 && sphere->limit.t1 > 0)
		return (new_inter());
	if (sphere->dir.x != 0 && sphere->limit.t2 > 0)
		return (new_inter());
	if (sphere->dir.z != 0 && sphere->limit.t3 > 0)
		return (new_inter());
	inter.pos = get_vec_from_t(ray.pos, ray.dir, delta.t);
	inter.normal = vec_normalize(vec_minus(inter.pos, sphere->pos));
	inter.object = obj;
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.reflection = sphere->reflexion;
	inter.refraction = sphere->refraction;
	return (inter);
}

t_inter				sphere_inter(t_object *obj, t_ray ray)
{
	t_sphere	*s;
	t_delta		delta;
	t_vec		ray_org;

	s = obj->data;
	ray_org = vec_minus(ray.pos, s->pos);
	delta.b = vec_dot_product(ray_org, ray.dir);
	delta.delta = delta.b * delta.b -
	vec_square_norm(ray_org) + s->rayon * s->rayon;
	if (delta.delta < 0)
		return (new_inter());
	else if (delta.delta == 0)
		delta.t = -delta.b;
	else
		delta = get_sphere_delta2(delta, obj);
	if (delta.t < 0)
		return (new_inter());
	s = sphere_limit(ray.dir, ray.pos, s, delta.t);
	return (sphere_inter_ret(obj, s, ray, delta));
}
