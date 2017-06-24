/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:10:50 by mriviere          #+#    #+#             */
/*   Updated: 2017/05/13 18:10:52 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		put_obj(t_object *obj, t_env *e)
{
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	e->count++;
}

t_object	*ft_check_hyper2(t_env *e, t_var *v, int i)
{
	t_hyper		hyper;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_HYPER2;
	hyper.pos = v->hyper[i].pos;
	hyper.dir = v->hyper[i].dir;
	hyper.alpha = v->hyper[i].alpha;
	hyper.reflexion = v->hyper[i].reflexion;
	hyper.refraction = v->hyper[i].refraction;
	hyper.length = v->hyper[i].length;
	hyper.simple = v->hyper[i].simple;
	obj->color = v->hyper[i].color;
	obj->path = v->hyper[i].path;
	obj->path2 = v->hyper[i].path2;
	obj->freq = v->hyper[i].freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->data = (void*)malloc(sizeof(hyper));
	ft_memcpy(obj->data, &hyper, sizeof(hyper));
	e->count++;
	ft_list_object(e, obj);
	return (obj);
}

t_object	*ft_check_sphere2(t_env *e, t_var *v, int i)
{
	t_sphere	sphere;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_SPHERE2;
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
	return (obj);
}

t_object	*ft_check_cone2(t_env *e, t_var *v, int i)
{
	t_cone		cone;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CONE2;
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
	return (obj);
}

t_object	*ft_check_cylinder2(t_env *e, t_var *v, int i)
{
	t_cylinder	cylinder;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CYLINDER2;
	cylinder.pos = v->cylinder[i].pos;
	cylinder.dir = v->cylinder[i].dir;
	cylinder.rayon = v->cylinder[i].rayon;
	cylinder.reflexion = v->cylinder[i].reflexion;
	cylinder.refraction = v->cylinder[i].refraction;
	cylinder.length = v->cylinder[i].length;
	obj->path = v->cylinder[i].path;
	obj->path2 = v->cylinder[i].path2;
	obj->freq = v->cylinder[i].freq;
	obj->text = parse_textu(e, obj);
	obj->norm = parse_normal(e, obj);
	obj->data = (void*)malloc(sizeof(cylinder));
	ft_memcpy(obj->data, &cylinder, sizeof(cylinder));
	e->count++;
	ft_list_object(e, obj);
	return (obj);
}
