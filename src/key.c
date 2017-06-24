/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:40:19 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/06 10:40:20 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		key2(int keycode, t_env *e)
{
	if (keycode == 27)
		e->scene.eye.pos.z -= 0.1;
	else if (keycode == 24)
		e->scene.eye.pos.z += 0.1;
	else if (keycode == 126)
		e->scene.eye.pos.y += 1;
	else if (keycode == 125)
		e->scene.eye.pos.y -= 1;
	else if (keycode == 124)
		e->scene.eye.pos.x += 1;
	else if (keycode == 123)
		e->scene.eye.pos.x -= 1;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 43)
	{
		if (e->sepia == 42)
			e->sepia = -1;
		else
			e->sepia = 42;
	}
	else
		return (666);
	return (keycode);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 91)
		e->ole += 50;
	else if (keycode == 87)
		e->ole -= 50;
	else if (keycode == 0)
		e->scene.eye.dir.y += 0.1;
	else if (keycode == 2)
		e->scene.eye.dir.y -= 0.1;
	else if (keycode == 1)
		e->scene.eye.dir.x += 0.1;
	else if (keycode == 13)
		e->scene.eye.dir.x -= 0.1;
	else
	{
		if (key2(keycode, e) == 666)
			return (0);
	}
	e->perc = 0;
	raytracing(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.ptri, 0, 0);
	return (0);
}
