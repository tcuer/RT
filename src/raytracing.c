/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:28:11 by cluciani          #+#    #+#             */
/*   Updated: 2017/04/18 14:28:13 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#define PI 3.14159265

t_vec		calc_ray_dir(t_env *e, int x, int y)
{
	t_vec	plan;
	t_vec	vec_plan;
	t_eye	oeil;

	oeil = e->scene.eye;
	vec_plan.x = oeil.pos.x;
	vec_plan.y = oeil.pos.y;
	vec_plan.z = 1800 + oeil.pos.z;
	plan.x = vec_plan.x + (x - WIDTH / 2);
	plan.y = vec_plan.y + (y - HEIGHT / 2);
	plan.z = vec_plan.z;
	plan = ft_rotate_x(plan, oeil.dir.x);
	plan = ft_rotate_y(plan, oeil.dir.y);
	return (vec_normalize(vec_minus(plan, oeil.pos)));
}

t_inter		get_inter(t_object *obj, t_ray ray)
{
	t_inter		inter;

	inter = new_inter();
	if (obj->id == O_SPHERE || obj->id == O_SPHERE2)
		inter = sphere_inter(obj, ray);
	if (obj->id == O_PLAN)
		inter = plan_inter(obj, ray);
	if (obj->id == O_CYLINDER || obj->id == O_CYLINDER2)
		inter = cylinder_inter(obj, ray);
	if (obj->id == O_CONE || obj->id == O_CONE2)
		inter = cone_inter(obj, ray);
	if (obj->id == O_HYPER || obj->id == O_HYPER2)
		inter = hyper_inter(obj, ray);
	return (inter);
}

t_color		t_ray2(t_env *e, t_ray ray, void *data, t_object *obj)
{
	t_color		final_color;

	e->hit = 1;
	if (e->scene.light == NULL)
		final_color = no_light(e, *obj);
	else
		final_color = get_color(e, ray, *obj);
	if (ray.inter.reflection >= 0.1 && data != obj->data &&
	e->reflection < 1 && e->scene.light != NULL)
		final_color = check_reflection(ray, e, *obj, final_color);
	if (ray.inter.refraction >= 0.1 && data != obj->data &&
	e->scene.light != NULL)
		final_color = check_refraction(ray, e, *obj, final_color);
	return (final_color);
}

t_color		throwing_ray(t_env *e, t_ray r, void *data)
{
	t_object	*obj;
	t_list		*objs;
	t_color		final_color;
	t_inter		inter_1;

	inter_1 = new_inter();
	objs = e->scene.obj;
	final_color = new_t_color(0, 0, 0);
	while (objs->next != NULL)
	{
		obj = objs->content;
		r.inter = get_inter(obj, r);
		if (r.inter.distance < inter_1.distance &&
		r.inter.distance > 0 && obj->data != data)
		{
			r.inter.normal = bump_aply(r.inter.normal, obj, r.inter.pos, e);
			ft_memcpy(&inter_1, &r.inter, sizeof(t_inter));
			final_color = t_ray2(e, r, data, obj);
		}
		objs = objs->next;
	}
	if (e->hit == 1)
		return (final_color);
	e->hit = 0;
	return (new_t_color(0, 0, 0));
}

void		raytracing(t_env *e)
{
	int			x;
	int			y;
	t_color		color;
	t_ray		ray;

	x = 0;
	ray.pos = e->scene.eye.pos;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			e->reflection = 0;
			e->hit = 0;
			e->refraction = 0;
			ray.dir = calc_ray_dir(e, x, y);
			color = throwing_ray(e, ray, NULL);
			mlx_pixel_img(e->mlx.ptri, x, y, color);
			loading(x, y, e);
			y++;
		}
		x++;
	}
	expose_hook(e);
	ft_putchar('\n');
}
