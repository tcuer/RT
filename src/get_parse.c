/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:06:32 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/15 10:06:36 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_class(char *parse, t_parse *p)
{
	if (ft_strstr(parse, "/camera"))
		get_class2(p, "/camera", "camera", 0);
	else if (ft_strstr(parse, "/object"))
		get_class2(p, "/object", "object", 1);
	else if (ft_strstr(parse, "/light"))
		get_class2(p, "/light", "light", 2);
	else if (ft_strstr(parse, "camera"))
	{
		ft_strcpy(p->class, "camera");
		p->nb_class[0]++;
	}
	else if (ft_strstr(parse, "object"))
	{
		ft_strcpy(p->class, "object");
		p->nb_class[1]++;
	}
	else if (ft_strstr(parse, "light"))
	{
		ft_strcpy(p->class, "light");
		p->nb_class[2]++;
	}
	else
		ft_error("\"class\" doesn't exist", parse);
}

void	get_type(char *parse, t_parse *p)
{
	if (parse[p->i] == '<')
	{
		while (parse[++p->i] != ' ')
		{
			p->type[p->j] = parse[p->i];
			p->j++;
		}
		p->type[p->j] = '\0';
		if (p->j == 0)
			ft_error("Missing something in \"type\"", "");
		if (ft_check_type(p))
			ft_error("\"type\" doesn't exist", p->type);
		p->j = 0;
	}
}

void	get_name(char *parse, t_parse *p)
{
	if (parse[p->i] == ' ')
	{
		while (parse[++p->i] != '=')
		{
			p->name[p->j] = parse[p->i];
			p->j++;
		}
		p->name[p->j] = '\0';
		if (p->j == 0)
			ft_error("Missing something in \"name\"", "");
		p->j = 0;
	}
}

void	get_var2(t_parse *p)
{
	if (ft_strcmp(p->type, "type") && ft_strcmp(p->type, "path")
		&& ft_strcmp(p->type, "path2"))
	{
		p->nb[p->l] = ft_atof(p->var);
		p->l++;
	}
	else
	{
		if (ft_check_name(p) && ft_strcmp(p->type, "type") == 0)
			ft_error("\"name\" doesn't exist", p->var);
		else if (ft_strcmp(p->type, "type") == 0)
			ft_strcpy(p->obj, p->var);
		else if (ft_strcmp(p->type, "path") == 0
			|| ft_strcmp(p->type, "path2") == 0)
			ft_strcpy(p->path, p->var);
	}
}

void	get_var(char *parse, t_parse *p)
{
	if (parse[p->i] == '"')
	{
		while (parse[++p->i] != '"')
		{
			if (parse[p->i] != '-' && (parse[p->i] == '/' || parse[p->i] < '.'
				|| parse[p->i] > '9') && ft_strcmp(p->type, "type")
				&& ft_strcmp(p->type, "path") && ft_strcmp(p->type, "path2"))
				ft_error("Var is not a number", p->name);
			p->var[p->j] = parse[p->i];
			p->j++;
		}
		p->var[p->j] = '\0';
		if (p->j == 0)
			ft_error("Missing something in \"var\"", "");
		get_var2(p);
		p->j = 0;
	}
}
