/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:45:06 by cluciani          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:09 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_object	*check_sphere4(t_plan *plan, t_object *object)
{
	t_sphere	sphere;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_SPHERE;
	sphere.dir = new_vec(0, 0, 0);
	sphere.pos = plan->pos;
	sphere.rayon = plan->hole;
	sphere.reflexion = plan->reflexion;
	sphere.refraction = plan->refraction;
	obj->path = object->path;
	obj->path2 = object->path2;
	obj->freq = object->freq;
	obj->text = object->text;
	obj->color = object->color;
	obj->text = object->text;
	obj->norm = object->norm;
	obj->data = (void*)malloc(sizeof(sphere));
	ft_memcpy(obj->data, &sphere, sizeof(sphere));
	return (obj);
}

static t_inter	sphere_inter_ret(t_object *obj, t_sphere *sphere,
				t_ray ray, double t[3])
{
	t_inter	inter;

	inter.pos = get_vec_from_t(ray.pos, ray.dir, t[2]);
	inter.normal = vec_normalize(vec_minus(inter.pos, sphere->pos));
	inter.object = obj;
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.reflection = sphere->reflexion;
	inter.refraction = sphere->refraction;
	return (inter);
}

static t_inter	sphere_inter2(t_object *obj, t_ray ray)
{
	t_sphere	*s;
	double		b;
	double		d;
	double		t[3];
	t_vec		ray_org;

	s = obj->data;
	ray_org = vec_minus(ray.pos, s->pos);
	b = vec_dot_product(ray_org, ray.dir);
	d = b * b - vec_square_norm(ray_org) + s->rayon * s->rayon;
	if (d < 0)
		return (new_inter());
	else if (d == 0)
		t[2] = -b;
	else
	{
		d = sqrt(d);
		t[0] = (-b + d);
		t[1] = (-b - d);
		t[2] = MIN(t[0], t[1]);
	}
	if (t[2] < 0)
		return (new_inter());
	return (sphere_inter_ret(obj, s, ray, t));
}

t_inter			get_data(t_object *obj, t_plan *plan, double t, t_ray ray)
{
	t_inter		inter;

	inter.object = obj;
	inter.normal = plan->dir;
	inter.pos = get_vec_from_t(ray.pos, ray.dir, t);
	inter.reflection = plan->reflexion;
	inter.distance = dist3d(inter.pos, ray.pos);
	inter.refraction = plan->refraction;
	return (inter);
}

t_inter			plan_inter(t_object *obj, t_ray ray)
{
	t_plan		*plan;
	double		t;
	t_inter		inter;
	t_object	*tmp;

	plan = obj->data;
	tmp = obj;
	tmp->data = plan;
	if (plan->hole > 0)
	{
		tmp = check_sphere4(plan, obj);
		inter = sphere_inter2(tmp, ray);
		if (inter.object != NULL)
			return (new_inter());
	}
	plan->dir = vec_normalize(plan->dir);
	t = (vec_dot_product((vec_minus(plan->pos, ray.pos)),
	plan->dir)) / vec_dot_product(plan->dir, ray.dir);
	inter = get_data(obj, plan, t, ray);
	if (t < 0)
		return (new_inter());
	return (inter);
}
