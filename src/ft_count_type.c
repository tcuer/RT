/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:40:31 by tcuer             #+#    #+#             */
/*   Updated: 2017/04/25 15:40:37 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	count_sphere(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.dir + p->n.color + p->n.radius +
	p->n.type + p->n.refraction + p->n.reflexion + p->n.freq;
	if (comp == 8)
	{
		p->n.pos = 0;
		p->n.dir = 0;
		p->n.color = 0;
		p->n.radius = 0;
		p->n.type = 0;
		p->n.reflexion = 0;
		p->n.refraction = 0;
		p->n.path = 0;
		p->n.path2 = 0;
		p->n.freq = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in object", "sphere");
}

void	count_plan(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.dir + p->n.color + p->n.freq +
	p->n.type + p->n.refraction + p->n.reflexion + p->n.hole;
	if (comp == 8)
	{
		p->n.pos = 0;
		p->n.dir = 0;
		p->n.color = 0;
		p->n.type = 0;
		p->n.reflexion = 0;
		p->n.refraction = 0;
		p->n.path = 0;
		p->n.path2 = 0;
		p->n.freq = 0;
		p->n.hole = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in object", "plan");
}

void	count_cylinder(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.dir + p->n.color + p->n.radius +
	p->n.type + p->n.refraction + p->n.reflexion + p->n.length
	+ p->n.freq;
	if (comp == 9)
	{
		p->n.pos = 0;
		p->n.dir = 0;
		p->n.color = 0;
		p->n.radius = 0;
		p->n.type = 0;
		p->n.reflexion = 0;
		p->n.refraction = 0;
		p->n.length = 0;
		p->n.path = 0;
		p->n.path2 = 0;
		p->n.freq = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in object", "cylinder");
}

void	count_cone(t_parse *p, int comp)
{
	comp = p->n.pos + p->n.dir + p->n.color + p->n.radius +
	p->n.type + p->n.refraction + p->n.reflexion + p->n.length
	+ p->n.simple + p->n.freq;
	if (comp == 10)
	{
		p->n.pos = 0;
		p->n.dir = 0;
		p->n.color = 0;
		p->n.radius = 0;
		p->n.type = 0;
		p->n.reflexion = 0;
		p->n.refraction = 0;
		p->n.path = 0;
		p->n.length = 0;
		p->n.path2 = 0;
		p->n.freq = 0;
		p->n.simple = 0;
		bzero(p->class2, ft_strlen(p->class2));
	}
	else
		ft_error("Missing something in object", "cone");
}

void	count_type(t_parse *p)
{
	if (p->type && ft_strcmp(p->type, "pos") == 0)
		p->n.pos++;
	else if (p->type && ft_strcmp(p->type, "dir") == 0)
		p->n.dir++;
	else if (p->type && ft_strcmp(p->type, "type") == 0)
		p->n.type++;
	else if (p->type && ft_strcmp(p->type, "color") == 0)
		p->n.color++;
	else if (p->type && ft_strcmp(p->type, "reflexion") == 0)
		p->n.reflexion++;
	else if (p->type && ft_strcmp(p->type, "refraction") == 0)
		p->n.refraction++;
	else if (p->type && ft_strcmp(p->type, "intensity") == 0)
		p->n.intensity++;
	else if (p->type && ft_strcmp(p->type, "ambient") == 0)
		p->n.ambient++;
	ft_too_many_types(p);
}
