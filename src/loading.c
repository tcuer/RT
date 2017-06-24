/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:36:12 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/02 17:36:26 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			red_cross2(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	exit(0);
	return (0);
}

void		loading_bar(t_env *e)
{
	t_color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.ptri, 0, 0);
	mlx_string_put(e->mlx.mlx, e->mlx.win, 500, 300,
		ft_color_conv(color), ft_itoa(e->perc));
	mlx_string_put(e->mlx.mlx, e->mlx.win, 530, 300,
		ft_color_conv(color), "\%");
	mlx_do_sync(e->mlx.mlx);
}

void		loading(int x, int y, t_env *e)
{
	if (100 * (y + x * HEIGHT) / (WIDTH * HEIGHT) > e->perc + 10)
	{
		mlx_hook(e->mlx.win, 17, (1L << 17), red_cross2, e);
		e->perc = 100 * (y + x * HEIGHT) / (WIDTH * HEIGHT) - 1;
		ft_putnbr(e->perc);
		ft_putendl("\%");
		loading_bar(e);
	}
}
