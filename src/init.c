/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:31:53 by cluciani          #+#    #+#             */
/*   Updated: 2017/04/12 17:01:32 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "rt");
	e->mlx.ptri = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.im = mlx_get_data_addr(e->mlx.ptri, &(e->mlx.bpp),
		&(e->mlx.size), &(e->mlx.endian));
}

int			red_cross(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	exit(0);
	return (0);
}

void		ft_init_render(t_env *e)
{
	raytracing(e);
	mlx_expose_hook(e->mlx.win, expose_hook, e);
	mlx_hook(e->mlx.win, 2, 1, key_hook, e);
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->mlx.mlx);
}
