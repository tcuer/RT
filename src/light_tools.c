/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:37:15 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/08 16:37:17 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		no_light(t_env *e, t_object object)
{
	t_color		color;

	color = object.color;
	color.r *= e->scene.ambient;
	color.g *= e->scene.ambient;
	color.b *= e->scene.ambient;
	color.r = color.r < 0 ? 0 : color.r;
	color.g = color.g < 0 ? 0 : color.g;
	color.b = color.b < 0 ? 0 : color.b;
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	return (color);
}

t_color		add_color(t_color color1, t_color color2)
{
	color1.r += color2.r;
	color1.g += color2.g;
	color1.b += color2.b;
	color1.r = color1.r > 255 ? 255 : color1.r;
	color1.g = color1.g > 255 ? 255 : color1.g;
	color1.b = color1.b > 255 ? 255 : color1.b;
	return (color1);
}

t_color		apply_color_lighting(t_env *e, t_object object, t_light light,
	t_ray ray)
{
	t_color		ret;

	e->dist = dist3d(ray.inter.pos, light.pos);
	ret = throwing_light_ray(e, ray, object, light.pos);
	ret = compute_light(ray.inter, light, ret, e);
	ret = specular_light(ray.inter, light, ret, object);
	return (ret);
}

t_color		new_t_color(int r, int g, int b)
{
	t_color color;

	color.g = g;
	color.b = b;
	color.r = r;
	return (color);
}
