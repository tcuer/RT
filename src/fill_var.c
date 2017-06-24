/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:40:07 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/07 16:40:12 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	fill_pos(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->class, "camera") == 0)
		v->eye.pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->class, "light") == 0)
	{
		if (ft_strcmp(p->obj, "spot") == 0)
			v->light[p->c.li].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	}
	else if (ft_strcmp(p->class, "object") == 0)
		fill_pos_obj(p, v);
}

void	fill_dir(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->class, "camera") == 0)
		v->eye.dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->class, "light") == 0)
	{
		if (ft_strcmp(p->obj, "spot") == 0)
			v->light[p->c.li].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	}
	else if (ft_strcmp(p->class, "object") == 0)
		fill_dir_obj(p, v);
}

void	fill_radius(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].rayon = p->nb[0];
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].rayon = p->nb[0];
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].alpha = p->nb[0];
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].radius = p->nb[0];
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].alpha = p->nb[0];
}

void	ft_fill_var(t_parse *p, t_var *v)
{
	if (p->nb[0] < 0.1 && p->nb[0] != 0)
		p->nb[0] = 0.1;
	if (ft_strcmp(p->type, "intensity") == 0)
	{
		if (ft_strcmp(p->obj, "spot") == 0)
			v->light[p->c.li].intensity = p->nb[0] > 4.5 ? 4.5 : p->nb[0];
	}
	else if (ft_strcmp(p->type, "reflexion") == 0)
		fill_reflexion(p, v);
	else if (ft_strcmp(p->type, "ambient") == 0)
		v->ambient = p->nb[0] > 0.5 ? 0.5 : p->nb[0];
	else if (ft_strcmp(p->type, "radius") == 0)
		fill_radius(p, v);
	else if (ft_strcmp(p->type, "length") == 0)
		fill_length(p, v);
	else if (ft_strcmp(p->type, "simple") == 0)
	{
		if (ft_strcmp(p->obj, "cone") == 0)
			v->cone[p->c.co].simple = p->nb[0] > 1 ? 1 : p->nb[0];
		else if (ft_strcmp(p->obj, "hyper") == 0)
			v->hyper[p->c.hy].simple = p->nb[0] > 1 ? 1 : p->nb[0];
	}
	else if (ft_strcmp(p->type, "hole") == 0)
		v->plan[p->c.pl].hole = p->nb[0];
}

void	fill_var(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->type, "pos") == 0)
		fill_pos(p, v);
	else if (ft_strcmp(p->type, "dir") == 0)
		fill_dir(p, v);
	else if (ft_strcmp(p->type, "type") == 0)
		fill_name(p, v);
	else if (ft_strcmp(p->type, "color") == 0)
		fill_color(p, v);
	else if (ft_strcmp(p->type, "refraction") == 0)
		fill_refraction(p, v);
	else if (ft_strcmp(p->type, "path") == 0)
		fill_path(p, v);
	else if (ft_strcmp(p->type, "path2") == 0)
		fill_path2(p, v);
	else if (ft_strcmp(p->type, "freq") == 0)
		fill_freq(p, v);
	ft_fill_var(p, v);
	ft_count_type(p);
}
