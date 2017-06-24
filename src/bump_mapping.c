/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:28:11 by wmartine          #+#    #+#             */
/*   Updated: 2017/04/18 14:28:13 by wmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_fucking_norm(t_perlin *p, double x_pos, double y_pos, double z_pos)
{
	p->i = 0;
	p->j = 0;
	p->k = 0;
	p->i = int_and_frac(x_pos, p->i, &p->x);
	p->j = int_and_frac(y_pos, p->j, &p->y);
	p->k = int_and_frac(z_pos, p->k, &p->z);
	p->i &= 255;
	p->j &= 255;
	p->k &= 255;
	p->g000 = fast_dot(get_grad(p->i, p->j, p->k), p->x, p->y, p->z);
	p->g001 = fast_dot(get_grad(p->i, p->j, p->k + 1), p->x, p->y, p->z - 1.);
	p->g010 = fast_dot(get_grad(p->i, p->j + 1, p->k), p->x, p->y - 1., p->z);
	p->g011 = fast_dot(get_grad(p->i, p->j + 1, p->k + 1), p->x, p->y - 1.,
		p->z - 1.);
	p->g100 = fast_dot(get_grad(p->i + 1, p->j, p->k), p->x - 1., p->y, p->z);
	p->g101 = fast_dot(get_grad(p->i + 1, p->j, p->k + 1), p->x - 1., p->y,
		p->z - 1.);
	p->g110 = fast_dot(get_grad(p->i + 1, p->j + 1, p->k), p->x - 1.,
		p->y - 1., p->z);
	p->g111 = fast_dot(get_grad(p->i + 1, p->j + 1, p->k + 1), p->x - 1.,
		p->y - 1., p->z - 1.);
}

double	smooth_noise_3d(t_vec pos, double res)
{
	t_perlin per;

	pos.x /= res;
	pos.y /= res;
	pos.z /= res;
	ft_fucking_norm(&per, pos.x, pos.y, pos.z);
	per.u = quintic_poly(per.x);
	per.v = quintic_poly(per.y);
	per.w = quintic_poly(per.z);
	per.x00 = linear_interpolate(per.g000, per.g100, per.u);
	per.x10 = linear_interpolate(per.g010, per.g110, per.u);
	per.x01 = linear_interpolate(per.g001, per.g101, per.u);
	per.x11 = linear_interpolate(per.g011, per.g111, per.u);
	per.xy0 = linear_interpolate(per.x00, per.x10, per.v);
	per.xy1 = linear_interpolate(per.x01, per.x11, per.v);
	per.xyz = linear_interpolate(per.xy0, per.xy1, per.w);
	return (per.xyz);
}

t_vec	ft_pluopluo(t_vec reflect_ray, t_vec inter_pos, t_object *object)
{
	double		i;
	t_vec		ray_bumpe;
	double		f;

	i = 0;
	f = object->freq;
	if (f < 0 || f > 250)
		f = 20;
	if (f != 0)
	{
		i = smooth_noise_3d(inter_pos, f);
		ray_bumpe = vec_normalize(vec_add(reflect_ray, new_vec(i, i, i)));
	}
	else
		ray_bumpe = reflect_ray;
	return (ray_bumpe);
}

t_vec	bump_aply(t_vec reflect_ray, t_object *o, t_vec inter_pos, t_env *e)
{
	double		i;
	t_color		paint;
	t_vec		ray_bumpe;
	t_vec		new_ray;

	i = 0;
	if (o->nn != 1)
	{
		if (o->id == 4)
		{
			paint = get_norm(o, inter_pos, e);
			new_ray = vec_normalize(new_vec(paint.r, paint.g, paint.b));
			ray_bumpe = vec_normalize(vec_add(reflect_ray, new_ray));
		}
		else
		{
			paint = get_norm(o, inter_pos, e);
			i = (paint.r + paint.g + paint.b) / 3;
			i = ((i / 0.5) / 255) - 1;
			ray_bumpe = vec_normalize(vec_add(reflect_ray, new_vec(i, i, i)));
		}
	}
	else
		ray_bumpe = ft_pluopluo(reflect_ray, inter_pos, o);
	return (ray_bumpe);
}
