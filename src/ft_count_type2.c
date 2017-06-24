/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_type2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:59:06 by tcuer             #+#    #+#             */
/*   Updated: 2017/04/25 15:59:11 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_too_many_types(t_parse *p)
{
	if (p->type && ft_strcmp(p->type, "radius") == 0)
		p->n.radius++;
	else if (p->type && ft_strcmp(p->type, "length") == 0)
		p->n.length++;
	else if (p->type && ft_strcmp(p->type, "path") == 0)
		p->n.path++;
	else if (p->type && ft_strcmp(p->type, "path2") == 0)
		p->n.path2++;
	else if (p->type && ft_strcmp(p->type, "freq") == 0)
		p->n.freq++;
	else if (p->type && ft_strcmp(p->type, "simple") == 0)
		p->n.simple++;
	else if (p->type && ft_strcmp(p->type, "hole") == 0)
		p->n.hole++;
	if (p->n.pos > 1 || p->n.dir > 1 || p->n.type > 1 || p->n.color > 1
		|| p->n.reflexion > 1 || p->n.radius > 1 || p->n.ambient > 1
		|| p->n.refraction > 1 || p->n.intensity > 1 || p->n.length > 1
		|| p->n.path > 1 || p->n.path > 1 || p->n.freq > 1 || p->n.simple > 1
		|| p->n.hole > 1)
	{
		ft_error("Too many types", "");
	}
}

void	count_camera(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.dir + p->n.ambient;
	if (comp == 3)
	{
		p->n.pos = 0;
		p->n.dir = 0;
		p->n.ambient = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in camera", "");
}

void	count_light(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.color + p->n.intensity + p->n.type;
	if (comp == 4)
	{
		p->n.pos = 0;
		p->n.color = 0;
		p->n.intensity = 0;
		p->n.type = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in light", "");
}

void	count_object(t_parse *p, int comp)
{
	if (ft_strcmp(p->obj, "sphere") == 0)
		count_sphere(p, comp);
	else if (ft_strcmp(p->obj, "plan") == 0)
		count_plan(p, comp);
	else if (ft_strcmp(p->obj, "cylinder") == 0)
		count_cylinder(p, comp);
	else if (ft_strcmp(p->obj, "cone") == 0)
		count_cone(p, comp);
	else if (ft_strcmp(p->obj, "glass") == 0)
		count_glass(p, comp);
	else if (ft_strcmp(p->obj, "hyper") == 0)
		count_hyper(p, comp);
	else
		ft_error("Missing name of object", "");
}

void	ft_count_type(t_parse *p)
{
	int		comp;

	comp = 0;
	count_type(p);
	if (ft_strcmp(p->class2, "/camera") == 0)
		count_camera(p, comp);
	else if (ft_strcmp(p->class2, "/light") == 0)
	{
		if (ft_strcmp(p->obj, "spot") == 0)
			count_light(p, comp);
	}
	else if (ft_strcmp(p->class2, "/object") == 0)
		count_object(p, comp);
}
