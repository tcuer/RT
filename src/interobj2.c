/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interobj2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:10:32 by mriviere          #+#    #+#             */
/*   Updated: 2017/05/13 18:10:35 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		*check_cone3(t_cylinder cylinder, t_object *object, t_env *e)
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
		check_cylinder3(cylinder, obj, e);
	return (obj);
}

t_object		*check_sphere3(t_cylinder cylinder, t_object *object, t_env *e)
{
	t_sphere	sphere;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_SPHERE2;
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
	check_cone3(cylinder, obj, e);
	return (obj);
}

t_object		*check_cylinder3(t_cylinder cylinder,
	t_object *object, t_env *e)
{
	t_cylinder	cy;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CYLINDER2;
	cy.pos = cylinder.pos;
	cy.dir = cylinder.dir;
	cy.rayon = cylinder.rayon;
	cy.reflexion = cylinder.reflexion;
	cy.refraction = cylinder.refraction;
	cy.length = cylinder.length;
	obj->path = object->path;
	obj->path2 = object->path2;
	obj->freq = object->freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->color = object->color;
	obj->data = (void*)malloc(sizeof(cy));
	ft_memcpy(obj->data, &cy, sizeof(cy));
	e->count++;
	ft_list_object(e, obj);
	return (obj);
}
