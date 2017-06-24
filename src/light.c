/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:31:41 by cluciani          #+#    #+#             */
/*   Updated: 2016/11/15 07:31:44 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		dont_overflow(t_color color)
{
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	return (color);
}

t_color		specular_light(t_inter in, t_light li, t_color col, t_object obj)
{
	t_vec		light_ray;
	t_vec		eye_ray;
	t_vec		reflec_ray;
	double		ok;

	light_ray = vec_rev_sign(vec_normalize(vec_minus(in.pos, li.pos)));
	eye_ray.x = 2 * in.normal.x * vec_dot_product(in.normal, light_ray);
	eye_ray.y = 2 * in.normal.y * vec_dot_product(in.normal, light_ray);
	eye_ray.z = 2 * in.normal.z * vec_dot_product(in.normal, light_ray);
	if (obj.id == 4)
		reflec_ray = vec_normalize(vec_minus(eye_ray, light_ray));
	else
		reflec_ray = vec_normalize(vec_add(eye_ray, light_ray));
	ok = vec_dot_product(reflec_ray, eye_ray);
	ok = ok < 0 ? 0 : ok;
	ok *= exp(li.intensity);
	col.r += ok;
	col.g += ok;
	col.b += ok;
	col = dont_overflow(col);
	return (col);
}

t_color		compute_light(t_inter inter, t_light light, t_color color, t_env *e)
{
	t_color		ret;
	t_vec		cul;
	t_vec		inc_light;
	double		phi;

	cul = inter.normal;
	cul.x *= -1;
	cul.y *= -1;
	cul.z *= -1;
	inc_light = vec_normalize(vec_minus(inter.pos, light.pos));
	phi = vec_dot_product(cul, inc_light) + e->scene.ambient;
	ret.r = color.r;
	ret.g = color.g;
	ret.b = color.b;
	phi = phi < 0 ? 0 : phi;
	phi = phi > 1 ? 1 : phi;
	ret.r *= phi;
	ret.g *= phi;
	ret.b *= phi;
	if (e->sepia == 42)
		ret = sepia_filter(ret);
	return (ret);
}

t_color		throwing_light_ray(t_env *e, t_ray ray, t_object object,
	t_vec light_pos)
{
	t_inter		inter;
	t_object	*snd_obj;
	t_list		*objs;
	t_color		paint;
	double		i;

	i = 0;
	objs = e->scene.obj;
	inter = new_inter();
	while (objs->next != NULL)
	{
		snd_obj = objs->content;
		ray.pos = light_pos;
		inter = get_inter(snd_obj, ray);
		if (inter.distance < e->dist && snd_obj != ray.inter.object
		&& inter.distance > 0)
			i = ft_set_shadow(i, e);
		objs = objs->next;
	}
	paint = get_textu(&object, ray.inter.pos, e);
	if (i > 0.0)
		paint = ft_shadow(i, paint, e, inter);
	return (paint);
}

t_color		get_color(t_env *e, t_ray ray, t_object object)
{
	t_light		*l;
	t_color		tmp;
	t_object	*obj;
	t_list		*lights;
	t_color		ret;

	lights = e->scene.light;
	tmp = set_env_light1(e);
	e->nb_lights = 0;
	while (lights->next != NULL)
	{
		obj = lights->content;
		l = obj->data;
		ret = init_lights(&ray, *l, e, object);
		if (e->nb_lights == 0)
			tmp = ret;
		else if (e->nb_lights == 1)
			tmp = add_color(ret, tmp);
		set_env_light2(e);
		e->nb_lights = 1;
		lights = lights->next;
	}
	return (tmp);
}
