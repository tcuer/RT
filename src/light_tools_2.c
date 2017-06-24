/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:11:01 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/08 18:11:02 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_env_light2(t_env *e)
{
	e->nb_lights = 1;
	e->shadow -= 0.1;
	e->shadow = e->shadow < 0.1 ? 0.1 : e->shadow;
}

t_color		set_env_light1(t_env *e)
{
	t_color		tmp;

	tmp = new_t_color(0, 0, 0);
	e->shadow = 0.5;
	e->nb_lights = 0;
	return (tmp);
}

t_color		sepia_filter(t_color color)
{
	color.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
	color.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);
	color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	return (color);
}

t_color		ft_shadow(double i, t_color color, t_env *e, t_inter inter)
{
	double shadow;

	shadow = e->shadow;
	e->shadow += i;
	if (inter.refraction >= 0.1)
	{
		shadow += 0.3;
		shadow = shadow > 0.7 ? 0.7 : shadow;
	}
	return (new_t_color(color.r * shadow, color.g * shadow, color.b * shadow));
}

double		ft_set_shadow(double i, t_env *e)
{
	e->shadow -= 0.1;
	e->shadow = e->shadow < 0.1 ? 0.1 : e->shadow;
	i += 0.1;
	return (i);
}
