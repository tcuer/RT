/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:21:04 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/04 16:21:06 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		fill_length(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].length = p->nb[0];
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].length = p->nb[0];
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].length = p->nb[0];
}

t_object	*ft_check_glass(t_env *e, t_var *v, int i)
{
	t_cylinder	cylinder;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_CYLINDER;
	cylinder.pos = v->glass[i].pos;
	cylinder.dir = v->glass[i].dir;
	cylinder.rayon = v->glass[i].radius;
	cylinder.length = cylinder.rayon * 8;
	cylinder.reflexion = v->glass[i].reflexion;
	cylinder.refraction = v->glass[i].refraction;
	obj->color = v->glass[i].color;
	obj->path = v->glass[i].path;
	obj->path2 = v->glass[i].path2;
	obj->freq = v->glass[i].freq;
	put_obj(obj, e);
	obj->data = (void*)malloc(sizeof(cylinder));
	ft_memcpy(obj->data, &cylinder, sizeof(cylinder));
	ft_list_object(e, obj);
	cylinder = cylinder_pos2(cylinder);
	check_cylinder3(cylinder, obj, e);
	check_sphere2(cylinder, obj, e);
	return (obj);
}

t_object	*ft_check_light(t_env *e, t_var *v, int i)
{
	t_light		light;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_LIGHT;
	light.pos = v->light[i].pos;
	light.dir = v->light[i].dir;
	light.intensity = v->light[i].intensity;
	obj->color = v->light[i].color;
	obj->data = (void*)malloc(sizeof(light));
	ft_memcpy(obj->data, &light, sizeof(light));
	e->countl++;
	ft_list_lights(e, obj);
	return (obj);
}

t_object	*ft_check_hyper(t_env *e, t_var *v, int i)
{
	t_hyper		hyper;
	t_object	*obj;

	obj = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = O_HYPER;
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
	put_obj(obj, e);
	obj->data = (void*)malloc(sizeof(hyper));
	ft_memcpy(obj->data, &hyper, sizeof(hyper));
	ft_list_object(e, obj);
	if (hyper.length > 0 && hyper.dir.z != 0)
		ft_check_hyper2(e, v, i);
	return (obj);
}

void		more_or_less_color(t_parse *p)
{
	p->nb[0] = p->nb[0] > 255 ? 255 : p->nb[0];
	p->nb[1] = p->nb[1] > 255 ? 255 : p->nb[1];
	p->nb[2] = p->nb[2] > 255 ? 255 : p->nb[2];
	p->nb[0] = p->nb[0] < 0 ? 0 : p->nb[0];
	p->nb[1] = p->nb[1] < 0 ? 0 : p->nb[1];
	p->nb[2] = p->nb[2] < 0 ? 0 : p->nb[2];
}
