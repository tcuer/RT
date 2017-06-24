/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:16:21 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/22 10:16:27 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	nbr_init(t_var *v, char **parse, int i)
{
	v->number.sphere = nbr_obj(parse, "sphere", i);
	v->number.plan = nbr_obj(parse, "plan", i);
	v->number.cylinder = nbr_obj(parse, "cy", i);
	v->number.cone = nbr_obj(parse, "cone", i);
	v->number.glass = nbr_obj(parse, "glass", i);
	v->number.light = nbr_obj(parse, "light", i);
	v->number.hyper = nbr_obj(parse, "hyper", i);
	if (v->number.sphere + v->number.plan + v->number.cylinder + v->number.cone
		+ v->number.glass + v->number.hyper > 20)
		ft_error("Too many objects", "");
	if (v->number.light > 5)
		ft_error("Too many lights", "");
}

void	var_init(t_var *v, t_parse *p, char **parse, int i)
{
	nbr_init(v, parse, i);
	ft_init_type(p);
	ft_init_name(p);
	ft_init_class_and_count(p);
	v->sphere = (t_sphere *)malloc(sizeof(t_sphere) * v->number.sphere);
	v->plan = (t_plan *)malloc(sizeof(t_plan) * v->number.plan);
	v->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * v->number.cylinder);
	v->cone = (t_cone *)malloc(sizeof(t_cone) * v->number.cone);
	v->glass = (t_glass *)malloc(sizeof(t_glass) * v->number.glass);
	v->light = (t_light *)malloc(sizeof(t_light) * v->number.light);
	v->hyper = (t_hyper *)malloc(sizeof(t_hyper) * v->number.hyper);
	p->class = (char *)malloc(20);
	p->class2 = (char *)malloc(20);
	p->obj = (char *)malloc(20);
	p->path = (char *)malloc(1000);
	p->k = 0;
	p->nb_class[0] = 0;
	p->nb_class[1] = 0;
	p->nb_class[2] = 0;
	init_type(p);
}

void	parse_init(char *parse, t_parse *p)
{
	p->nb = (double *)malloc(sizeof(double) * p->k);
	p->var = (char *)malloc(ft_strlen(parse) + 1);
	p->name = (char *)malloc(ft_strlen(parse) + 1);
	p->type = (char *)malloc(ft_strlen(parse) + 1);
	p->i = 0;
	p->j = 0;
	p->l = 0;
}

int		nbr_obj(char **parse, char *name, int j)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (parse[++i] && parse[i] && i < j && ft_strcmp(parse[i], "</scene>"))
	{
		if (ft_strstr(parse[i], "sphere") && ft_strcmp(name, "sphere") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "plan") && ft_strcmp(name, "plan") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "cylinder") && ft_strcmp(name, "cy") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "cone") && ft_strcmp(name, "cone") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "spot") && ft_strcmp(name, "light") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "glass") && ft_strcmp(name, "glass") == 0)
			ret += 1;
		else if (ft_strstr(parse[i], "hyper") && ft_strcmp(name, "hyper") == 0)
			ret += 1;
	}
	return (ret);
}
