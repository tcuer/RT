/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:06:46 by cluciani          #+#    #+#             */
/*   Updated: 2017/04/12 17:06:48 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		refraction2(t_ray ray)
{
	double		refraction;
	double		index;
	double		refraction_deg;

	refraction = vec_dot_product(ray.dir, ray.inter.normal);
	refraction *= -1;
	index = 1.0 / ray.inter.refraction;
	refraction_deg = 1 - index * index * (1 - refraction * refraction);
	ray.dir.x = (ray.dir.x * index) + (((index * refraction)
		- refraction_deg) * -ray.inter.normal.x);
	ray.dir.y = (ray.dir.y * index) + (((index * refraction)
		- refraction_deg) * -ray.inter.normal.y);
	ray.dir.z = (ray.dir.z * index) + (((index * refraction)
		- refraction_deg) * -ray.inter.normal.z);
	return (ray.dir);
}

t_color		check_refraction(t_ray ray, t_env *e,
	t_object object, t_color transparent_color)
{
	t_color		ret;

	ret = new_t_color(0, 0, 0);
	e->refraction++;
	e->hit = 0;
	if (ray.inter.refraction > 1.0)
		ray.dir = refraction2(ray);
	ray.pos = ray.inter.pos;
	ret = throwing_ray(e, ray, object.data);
	if (e->hit == 1)
	{
		ret = refraction3(ret, transparent_color, ray.inter.refraction);
		ret = dont_overflow(ret);
		e->refraction = 0;
		return (ret);
	}
	e->refraction = 0;
	return (transparent_color);
}

t_color		reflection3(t_color ret, t_color mirror_object_color,
	t_inter inter_origin)
{
	ret.r = (((ret.r + mirror_object_color.r) /
		2) * inter_origin.reflection);
	ret.g = (((ret.g + mirror_object_color.g) /
		2) * inter_origin.reflection);
	ret.b = (((ret.b + mirror_object_color.b) /
		2) * inter_origin.reflection);
	return (ret);
}

t_vec		reflection2(double reflection, t_ray ray, t_object object)
{
	t_vec		rayon;
	t_vec		reflect_ray;

	reflection = vec_dot_product(ray.dir, ray.inter.normal);
	rayon.x = 2 * reflection * ray.inter.normal.x;
	rayon.y = 2 * reflection * ray.inter.normal.y;
	rayon.z = 2 * reflection * ray.inter.normal.z;
	if (object.id == 4)
		reflect_ray = vec_normalize(vec_minus(rayon, ray.dir));
	else
		reflect_ray = vec_normalize(vec_add(ray.dir, rayon));
	return (reflect_ray);
}

t_color		check_reflection(t_ray ray, t_env *e, t_object object,
	t_color mirror_object_color)
{
	double		reflection;
	t_vec		re;
	t_color		ret;

	e->reflection = 1;
	e->hit = 0;
	ray.dir = vec_normalize(vec_rev_sign(ray.dir));
	ray.inter.normal = vec_normalize(ray.inter.normal);
	re = vec_cross_product(ray.dir, ray.inter.normal);
	reflection = vec_dot_product(ray.dir, ray.inter.normal);
	if (re.x == 0 && re.y == 0 && re.z)
		ray.dir = ray.inter.normal;
	else if (reflection == 0)
		ray.dir = vec_rev_sign(ray.dir);
	else
		ray.dir = reflection2(reflection, ray, object);
	ray.pos = ray.inter.pos;
	ret = throwing_ray(e, ray, object.data);
	if (e->hit == 1)
		ret = reflection3(ret, mirror_object_color, ray.inter);
	else
		ret = reflect_color(ret, mirror_object_color, ray.inter.reflection);
	e->reflection = 0;
	ret = dont_overflow(ret);
	return (ret);
}
