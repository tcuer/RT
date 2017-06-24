/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_var2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:57:48 by tcuer             #+#    #+#             */
/*   Updated: 2017/04/20 15:58:02 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	fill_refraction(t_parse *p, t_var *v)
{
	if (p->nb[0] < 0)
		p->nb[0] = 0;
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].refraction = p->nb[0] > 3 ? 3 : p->nb[0];
}

void	fill_reflexion(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].reflexion = p->nb[0] > 0.9 ? 0.9 : p->nb[0];
}

void	fill_pos_obj(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].pos = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
}

void	fill_dir_obj(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].dir = (t_vec){p->nb[0], p->nb[1], p->nb[2]};
}

void	fill_name(t_parse *p, t_var *v)
{
	increment_object(p);
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "spot") == 0)
		v->light[p->c.li].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].name = ft_strdup(p->obj);
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].name = ft_strdup(p->obj);
}
