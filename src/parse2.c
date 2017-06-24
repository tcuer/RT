/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:21:50 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/04 16:21:53 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object	*ft_check_sphere(t_env *e, t_var *v, int i)
{
	t_sphere	sphere;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_SPHERE;
	sphere.pos = v->sphere[i].pos;
	sphere.dir = v->sphere[i].dir;
	sphere.rayon = v->sphere[i].rayon;
	sphere.reflexion = v->sphere[i].reflexion;
	sphere.refraction = v->sphere[i].refraction;
	obj->path = v->sphere[i].path;
	obj->path2 = v->sphere[i].path2;
	obj->freq = v->sphere[i].freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->color = v->sphere[i].color;
	obj->data = (void*)malloc(sizeof(sphere));
	ft_memcpy(obj->data, &sphere, sizeof(sphere));
	e->count++;
	ft_list_object(e, obj);
	if (sphere.dir.x != 0 || sphere.dir.y != 0 || sphere.dir.z != 0)
		ft_check_sphere2(e, v, i);
	return (obj);
}

t_object	*ft_check_cone(t_env *e, t_var *v, int i)
{
	t_cone		cone;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CONE;
	cone.pos = v->cone[i].pos;
	cone.dir = v->cone[i].dir;
	cone.alpha = v->cone[i].alpha;
	cone.reflexion = v->cone[i].reflexion;
	cone.refraction = v->cone[i].refraction;
	cone.length = v->cone[i].length;
	cone.simple = v->cone[i].simple;
	obj->color = v->cone[i].color;
	obj->path = v->cone[i].path;
	obj->path2 = v->cone[i].path2;
	obj->freq = v->cone[i].freq;
	put_obj(obj, e);
	obj->data = (void*)malloc(sizeof(cone));
	ft_memcpy(obj->data, &cone, sizeof(cone));
	ft_list_object(e, obj);
	if (cone.length > 0 && cone.dir.z != 0)
		ft_check_cone2(e, v, i);
	return (obj);
}

t_object	*ft_check_cylinder(t_env *e, t_var *v, int i)
{
	t_cylinder	cylinder;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CYLINDER;
	cylinder.pos = v->cylinder[i].pos;
	cylinder.dir = v->cylinder[i].dir;
	cylinder.rayon = v->cylinder[i].rayon;
	cylinder.reflexion = v->cylinder[i].reflexion;
	cylinder.refraction = v->cylinder[i].refraction;
	cylinder.length = v->cylinder[i].length;
	obj->color = v->cylinder[i].color;
	obj->path = v->cylinder[i].path;
	obj->path2 = v->cylinder[i].path2;
	obj->freq = v->cylinder[i].freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->data = (void*)malloc(sizeof(cylinder));
	ft_memcpy(obj->data, &cylinder, sizeof(cylinder));
	e->count++;
	ft_list_object(e, obj);
	if (cylinder.length > 0 && cylinder.dir.z != 0)
		ft_check_cylinder2(e, v, i);
	return (obj);
}

t_object	*ft_check_plan(t_env *e, t_var *v, int i)
{
	t_plan		plan;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_PLAN;
	plan.pos = v->plan[i].pos;
	plan.dir = v->plan[i].dir;
	plan.reflexion = v->plan[i].reflexion;
	plan.refraction = v->plan[i].refraction;
	plan.hole = v->plan[i].hole;
	obj->path = v->plan[i].path;
	obj->path2 = v->plan[i].path2;
	obj->freq = v->plan[i].freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->color = v->plan[i].color;
	obj->data = (void *)malloc(sizeof(plan));
	ft_memcpy(obj->data, &plan, sizeof(plan));
	e->count++;
	ft_list_object(e, obj);
	return (obj);
}

t_eye		ft_check_eye(t_var *v)
{
	t_eye eye;

	eye.pos = v->eye.pos;
	eye.dir = v->eye.dir;
	return (eye);
}
