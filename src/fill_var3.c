/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_var3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:36:44 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/03 18:36:53 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	increment_object(t_parse *p)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		p->c.sp++;
	else if (ft_strcmp(p->obj, "plan") == 0)
		p->c.pl++;
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		p->c.cy++;
	else if (ft_strcmp(p->obj, "cone") == 0)
		p->c.co++;
	else if (ft_strcmp(p->obj, "spot") == 0)
		p->c.li++;
	else if (ft_strcmp(p->obj, "glass") == 0)
		p->c.gl++;
	else if (ft_strcmp(p->obj, "hyper") == 0)
		p->c.hy++;
}

void	fill_path(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].path = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].path = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].path = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].path = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].path = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].path = ft_strdup(p->path);
}

void	fill_path2(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].path2 = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].path2 = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].path2 = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].path2 = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].path2 = ft_strdup(p->path);
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].path2 = ft_strdup(p->path);
}

void	fill_color(t_parse *p, t_var *v)
{
	more_or_less_color(p);
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "spot") == 0)
		v->light[p->c.li].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].color = (t_color){p->nb[0], p->nb[1], p->nb[2]};
}

void	fill_freq(t_parse *p, t_var *v)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		v->sphere[p->c.sp].freq = p->nb[0];
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		v->cylinder[p->c.cy].freq = p->nb[0];
	else if (ft_strcmp(p->obj, "cone") == 0)
		v->cone[p->c.co].freq = p->nb[0];
	else if (ft_strcmp(p->obj, "plan") == 0)
		v->plan[p->c.pl].freq = p->nb[0];
	else if (ft_strcmp(p->obj, "glass") == 0)
		v->glass[p->c.gl].freq = p->nb[0];
	else if (ft_strcmp(p->obj, "hyper") == 0)
		v->hyper[p->c.hy].freq = p->nb[0];
}
