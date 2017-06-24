/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_type3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:17:27 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/04 17:17:32 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	count_glass(t_parse *p, int comp)
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
		ft_error("Missing something in object", "glass");
}

void	count_hyper(t_parse *p, int comp)
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
		ft_error("Missing something in object", "hyper");
}
