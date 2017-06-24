/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:32:11 by cluciani          #+#    #+#             */
/*   Updated: 2016/11/15 07:32:13 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_list_object(t_env *e, t_object *obj)
{
	if (e->error == 42)
		return (e->error);
	if (e->count == 1)
	{
		e->scene.obj = ft_lstnew(obj, sizeof(t_object));
		ft_lstadd(&(e->scene.obj), ft_lstnew(obj, sizeof(t_object)));
	}
	else
		ft_lstadd(&(e->scene.obj), ft_lstnew(obj, sizeof(t_object)));
	return (0);
}

int		ft_list_lights(t_env *e, t_object *obj)
{
	if (e->error == 42)
		return (e->error);
	if (e->countl == 1)
	{
		e->scene.light = ft_lstnew(obj, sizeof(t_object));
		ft_lstadd(&(e->scene.light), ft_lstnew(obj, sizeof(t_object)));
	}
	else
		ft_lstadd(&(e->scene.light), ft_lstnew(obj, sizeof(t_object)));
	return (0);
}

void	ft_object_id2(t_env *e, t_var *v)
{
	int i;

	i = -1;
	while (++i < v->number.glass)
		ft_check_glass(e, v, i);
	i = -1;
	while (++i < v->number.light)
		ft_check_light(e, v, i);
	i = -1;
	while (++i < v->number.hyper)
		ft_check_hyper(e, v, i);
}

int		ft_object_id(t_env *e, t_var *v)
{
	int		i;

	e->scene.eye = ft_check_eye(v);
	e->scene.ambient = v->ambient;
	i = -1;
	while (++i < v->number.sphere)
		ft_check_sphere(e, v, i);
	i = -1;
	while (++i < v->number.cone)
		ft_check_cone(e, v, i);
	i = -1;
	while (++i < v->number.cylinder)
		ft_check_cylinder(e, v, i);
	i = -1;
	while (++i < v->number.plan)
		ft_check_plan(e, v, i);
	i = -1;
	ft_object_id2(e, v);
	return (e->error);
}

void	ft_parse(t_env *e, t_var *v)
{
	e->scene.obj = NULL;
	e->scene.light = NULL;
	e->count = 0;
	e->countl = 0;
	ft_object_id(e, v);
}
