/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:21:36 by tcuer             #+#    #+#             */
/*   Updated: 2017/04/20 15:21:41 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		ft_check_type(t_parse *p)
{
	int		i;

	i = -1;
	while (++i < 15 && ft_strcmp(p->type_list[i], p->type))
	{
	}
	if (i == 15)
		return (1);
	else
		return (0);
}

int		ft_check_name(t_parse *p)
{
	int		i;

	i = -1;
	while (++i < 7 && ft_strcmp(p->name_list[i], p->var))
	{
	}
	if (i == 7)
		return (1);
	else
		return (0);
}

void	ft_check_symbol(char *parse, t_parse *p, int *j, int l)
{
	if (parse[*j] == '>' && *j != l)
		ft_error("Too many \'>\'", parse);
	if (parse[*j] == '\t')
	{
		if (parse[++*j] == '\t')
		{
			if (parse[++*j] != '<')
				ft_error("Missing \'<\'", parse);
			if (parse[l] != '>')
				ft_error("Missing \'>\'", parse);
			if (parse[l - 1] != '/')
				ft_error("Missing \'/\'", parse);
		}
		else if (parse[*j] != '<')
			ft_error("Missing \'<\'", parse);
		else
			get_class(parse, p);
	}
}

void	ft_check_count(t_parse *p)
{
	int comp;

	comp = p->n.type + p->n.pos + p->n.dir + p->n.radius + p->n.color
	+ p->n.reflexion + p->n.refraction + p->n.ambient + p->n.intensity
	+ p->n.length + p->n.path + p->n.path2 + p->n.freq + p->n.simple
	+ p->n.hole;
	if (comp != 0)
		ft_error("Too many types", "");
}

void	ft_check_nb_class(t_parse *p, char **parse, int i)
{
	if (p->nb_class[0] != 2)
		ft_error("Too many or no camera", "");
	if (p->nb_class[1] < 2)
		ft_error("No object", "");
	free_parse(p, parse, i);
}
