/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:56:38 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/08 19:56:39 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		init_lights(t_ray *ray, t_light light,
	t_env *e, t_object object)
{
	t_color	ret;

	ray->dir = vec_normalize(vec_minus(ray->inter.pos, light.pos));
	e->dist = dist3d(ray->inter.pos, light.pos);
	ret = apply_color_lighting(e, object, light, *ray);
	return (ret);
}

t_color		reflect_color(t_color ret, t_color mirror_object_color,
	double reflection)
{
	ret.r = (((0 + mirror_object_color.r) / 2) * reflection);
	ret.g = (((0 + mirror_object_color.g) / 2) * reflection);
	ret.b = (((0 + mirror_object_color.b) / 2) * reflection);
	return (ret);
}

t_color		refraction3(t_color ret, t_color transparent_color,
	double refraction)
{
	ret.r = (((ret.r + transparent_color.r) / 2) * refraction);
	ret.g = (((ret.g + transparent_color.g) / 2) * refraction);
	ret.b = (((ret.b + transparent_color.b) / 2) * refraction);
	return (ret);
}
