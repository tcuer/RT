/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:05:25 by tcuer             #+#    #+#             */
/*   Updated: 2017/04/20 16:05:29 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_type(t_parse *p)
{
	p->n.pos = 0;
	p->n.dir = 0;
	p->n.type = 0;
	p->n.ambient = 0;
	p->n.color = 0;
	p->n.intensity = 0;
	p->n.radius = 0;
	p->n.reflexion = 0;
	p->n.refraction = 0;
	p->n.length = 0;
	p->n.path = 0;
	p->n.path2 = 0;
	p->n.freq = 0;
	p->n.simple = 0;
	p->n.hole = 0;
}

void	ft_init_type(t_parse *p)
{
	p->type_list[0] = "pos";
	p->type_list[1] = "dir";
	p->type_list[2] = "type";
	p->type_list[3] = "ambient";
	p->type_list[4] = "color";
	p->type_list[5] = "intensity";
	p->type_list[6] = "radius";
	p->type_list[7] = "reflexion";
	p->type_list[8] = "refraction";
	p->type_list[9] = "length";
	p->type_list[10] = "path";
	p->type_list[11] = "path2";
	p->type_list[12] = "freq";
	p->type_list[13] = "simple";
	p->type_list[14] = "hole";
}

void	ft_init_name(t_parse *p)
{
	p->name_list[0] = "sphere";
	p->name_list[1] = "plan";
	p->name_list[2] = "cylinder";
	p->name_list[3] = "cone";
	p->name_list[4] = "glass";
	p->name_list[5] = "spot";
	p->name_list[6] = "hyper";
}

void	ft_init_class_and_count(t_parse *p)
{
	p->class_list[0] = "scene";
	p->class_list[1] = "camera";
	p->class_list[2] = "light";
	p->class_list[3] = "object";
	p->c.sp = -1;
	p->c.pl = -1;
	p->c.co = -1;
	p->c.cy = -1;
	p->c.li = -1;
	p->c.gl = -1;
	p->c.hy = -1;
}

void	get_class2(t_parse *p, char *class, char *class2, int i)
{
	ft_strcpy(p->class2, class);
	p->nb_class[i]++;
	if (ft_strcmp(p->class, class2) != 0)
		ft_error("Wrong tag", "");
	bzero(p->type, ft_strlen(p->type));
	ft_count_type(p);
}
