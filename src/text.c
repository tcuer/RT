/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:31:41 by wmartine          #+#    #+#             */
/*   Updated: 2017/04/12 17:03:02 by wmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#define PI 3.14159265

void	ft_sphere_maping(t_vec inter, t_vec pos, double rayon, t_text *text)
{
	t_vec	vn;
	t_vec	vp;
	t_vec	ve;
	t_vec	nord;
	t_vec	equa;

	nord = pos;
	nord.y = nord.y - rayon;
	equa = pos;
	equa.z = equa.z + rayon;
	vn = vec_normalize(vec_minus(nord, pos));
	ve = vec_normalize(vec_minus(equa, pos));
	vp = vec_normalize(vec_minus(inter, pos));
	text->y = acos((vec_dot_product(vn, vp))) / PI;
	if (vec_dot_product(vec_cross_product(vn, ve), vp) > 0)
		text->x = (acos(vec_dot_product(vp, ve) /
			sin(acos(-(vec_dot_product(vn, vp)))))) / (2 * PI);
	else
		text->x = 1 - ((acos(vec_dot_product(vp, ve) /
			sin(acos(-(vec_dot_product(vn, vp)))))) / (2 * PI));
	text->x *= text->width;
	text->y *= text->height;
}

t_color	ft_get_norm(t_object *o, t_vec pos, t_env *e)
{
	t_plan		*p;
	t_color		paint;

	paint = new_t_color(0, 0, 0);
	if (o->id == 4)
	{
		p = o->data;
		if (ft_plan_fuck(p->dir) == 1)
			o->norm.y = (abs((int)pos.z) + e->ole) % o->norm.height;
		else
			o->norm.y = (abs((int)pos.y) + e->ole) % o->norm.height;
	}
	else
		o->norm.y = (abs((int)pos.y) + e->ole) % o->norm.height;
	o->norm.x = (abs((int)pos.x) + e->ole) % o->norm.width;
	paint = ft_convert(get_pixel((int)o->norm.x, (int)o->norm.y,
		o->norm.im, o->norm.width));
	return (paint);
}

t_color	get_norm(t_object *o, t_vec pos, t_env *e)
{
	t_color		paint;
	t_sphere	*sp;

	paint = new_t_color(0, 0, 0);
	if (o->nn != 1)
	{
		if (o->id == 1)
		{
			sp = o->data;
			ft_sphere_maping(pos, sp->pos, sp->rayon, &o->norm);
			paint = ft_convert(get_pixel((int)o->norm.x, (int)o->norm.y,
				o->norm.im, o->norm.width));
		}
		else
			paint = ft_get_norm(o, pos, e);
	}
	return (paint);
}

t_color	ft_get_textu(t_object *o, t_vec pos, t_env *e)
{
	t_color		paint;
	t_plan		*plan;

	paint = new_t_color(0, 0, 0);
	if (o->id == 4)
	{
		plan = o->data;
		if (ft_plan_fuck(plan->dir) == 1)
			o->text.y = (abs((int)pos.z) + e->ole) % o->text.height;
		else
			o->text.y = (abs((int)pos.y) + e->ole) % o->text.height;
	}
	else
		o->text.y = (abs((int)pos.y) + e->ole) % o->text.height;
	o->text.x = (abs((int)pos.x) + e->ole) % o->text.width;
	paint = ft_convert(get_pixel((int)o->text.x, (int)o->text.y,
		o->text.im, o->text.width));
	return (paint);
}

t_color	get_textu(t_object *o, t_vec pos, t_env *e)
{
	t_color		paint;
	t_sphere	*sphere;

	if (o->tt != 1)
	{
		if (o->id == 1)
		{
			sphere = o->data;
			ft_sphere_maping(pos, sphere->pos, sphere->rayon, &o->text);
			paint = ft_convert(get_pixel((int)o->text.x, (int)o->text.y,
				o->text.im, o->text.width));
		}
		else
			paint = ft_get_textu(o, pos, e);
	}
	else
		paint = o->color;
	return (paint);
}
