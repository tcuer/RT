/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interobjs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:52:03 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/09 14:52:05 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			where_pos_c(t_cylinder c)
{
	if (c.dir.y > 0 && c.dir.x == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f1, double_mult(c.rayon, 1), c.dir));
	if (c.dir.x > 0 && c.dir.y == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f3, double_mult(c.rayon, 1), c.dir));
	if (c.dir.z > 0)
		return (vec_plus(c.limit.f5, double_mult(c.rayon, 1), c.dir));
	if (c.dir.y > 0 && c.dir.x > 0)
	{
		return (vec_plus(vec_change(c.limit.f1, c.limit.f3),
		double_mult(c.rayon, 4.5), c.dir));
	}
	if (c.dir.y < 0 && c.dir.x == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f2, double_mult(c.rayon, 1), c.dir));
	if (c.dir.x < 0 && c.dir.y == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f4, double_mult(c.rayon, 1), c.dir));
	if (c.dir.z < 0)
		return (vec_plus(c.limit.f6, double_mult(c.rayon, 1), c.dir));
	if (c.dir.y < 0 && c.dir.x < 0)
	{
		return (vec_plus(vec_change(c.limit.f2, c.limit.f4),
		double_mult(c.rayon, 4.5), c.dir));
	}
	return (c.pos);
}

t_vec			where_pos_s(t_cylinder c)
{
	if (c.dir.y > 0 && c.dir.x == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f2, double_mult(c.rayon, 12), c.dir));
	if (c.dir.x > 0 && c.dir.y == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f4, double_mult(c.rayon, 12), c.dir));
	if (c.dir.z > 0)
		return (vec_plus(c.limit.f6, double_mult(c.rayon, 12), c.dir));
	if (c.dir.y > 0 && c.dir.x > 0)
	{
		return (vec_plus(vec_change(c.limit.f2, c.limit.f4),
		double_mult(c.rayon, 4.5), c.dir));
	}
	if (c.dir.y < 0 && c.dir.x == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f1, double_mult(c.rayon, 12), c.dir));
	if (c.dir.x < 0 && c.dir.y == 0 && c.dir.z == 0)
		return (vec_plus(c.limit.f3, double_mult(c.rayon, 12), c.dir));
	if (c.dir.z < 0)
		return (vec_plus(c.limit.f5, double_mult(c.rayon, 12), c.dir));
	if (c.dir.y < 0 && c.dir.x < 0)
	{
		return (vec_plus(vec_change(c.limit.f1, c.limit.f3),
		double_mult(c.rayon, 4.5), c.dir));
	}
	return (c.pos);
}

t_object		*check_cone2(t_cylinder cylinder, t_object *object, t_env *e)
{
	t_cone		cone;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CONE;
	cone.pos = where_pos_c(cylinder);
	cone.dir = cylinder.dir;
	cone.alpha = 4;
	cone.reflexion = cylinder.reflexion;
	cone.refraction = cylinder.refraction;
	cone.length = cylinder.rayon * 4;
	cone.simple = 1;
	obj->path = object->path;
	obj->path2 = object->path2;
	obj->freq = object->freq;
	obj->color = object->color;
	put_obj(obj, e);
	obj->data = (void*)malloc(sizeof(cone));
	ft_memcpy(obj->data, &cone, sizeof(cone));
	ft_list_object(e, obj);
	if (cone.dir.z != 0)
		check_cone3(cylinder, obj, e);
	return (obj);
}

t_object		*check_sphere2(t_cylinder cylinder, t_object *object, t_env *e)
{
	t_sphere	sphere;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_SPHERE;
	sphere.pos = where_pos_s(cylinder);
	sphere.dir = cylinder.dir;
	sphere.rayon = cylinder.rayon * 12;
	sphere.reflexion = cylinder.reflexion;
	sphere.refraction = cylinder.refraction;
	obj->path = object->path;
	obj->path2 = object->path2;
	obj->freq = object->freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->color = object->color;
	obj->data = (void*)malloc(sizeof(sphere));
	ft_memcpy(obj->data, &sphere, sizeof(sphere));
	e->count++;
	ft_list_object(e, obj);
	check_cone2(cylinder, obj, e);
	if (sphere.dir.z != 0)
		check_sphere3(cylinder, obj, e);
	return (obj);
}
