/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:38:29 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/17 16:43:54 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_parse(t_parse *p, char **parse, int i)
{
	int	j;

	j = 0;
	if (i == -1)
	{
		free(p->var);
		free(p->name);
		free(p->nb);
		free(p->type);
	}
	else if (i >= 0)
	{
		while (j < i)
		{
			free(parse[j]);
			j++;
		}
		free(p->class);
		free(p->class2);
		free(p->obj);
		free(p->path);
		free(parse);
		free(p);
	}
}

int		check_slash(char *parse)
{
	int		i;

	i = -1;
	while (parse[++i])
	{
		if (parse[i] == '/')
			return (1);
		if (parse[i] == '"')
		{
			while (parse[++i] != '"')
			{
			}
			i++;
		}
	}
	return (0);
}

void	parse_pos2(char *parse, t_var *v, t_parse *p)
{
	parse_init(parse, p);
	while (parse[p->i] && p->l < p->k)
	{
		get_type(parse, p);
		get_name(parse, p);
		get_var(parse, p);
		p->i++;
	}
	fill_var(p, v);
	free_parse(p, &parse, -1);
	p->k = 0;
}

void	parse_pos(char **parse, t_var *v, t_parse *p)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (parse[++i] && ft_strcmp(parse[i], "</scene>"))
	{
		j = -1;
		l = ft_strlen(parse[i]) - 1;
		while (parse[i][++j])
		{
			if (parse[i][j] == '=')
				p->k++;
			if (parse[i][j] == '/')
			{
				if (j != l - 1 && ft_check_class(parse[i])
					&& check_slash(parse[i]))
					ft_error("Too many \'/\'", parse[i]);
				if (parse[i][++j] == '>')
					parse_pos2(parse[i], v, p);
			}
			ft_check_symbol(parse[i], p, &j, l);
		}
	}
}

void	parse(char *file, t_var *v)
{
	int		fd;
	int		i;
	char	**parse;
	char	*line;
	t_parse	*p;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist", file);
	parse = (char **)malloc(sizeof(char *) * 10000);
	p = (t_parse *)malloc(sizeof(t_parse));
	while (get_next_line(fd, &line) > 0)
	{
		parse[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strcpy(parse[i], line);
		free(line);
		i++;
	}
	ft_check_error(parse, i);
	var_init(v, p, parse, i);
	ft_check_scene(parse, i - 1);
	parse_pos(parse, v, p);
	ft_check_count(p);
	ft_check_nb_class(p, parse, i);
}
