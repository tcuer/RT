/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:31:41 by cluciani          #+#    #+#             */
/*   Updated: 2017/04/12 17:03:02 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_pixel(int x, int y, char *img, int dim_x)
{
	int		nb;
	char	color[4];

	nb = (abs(x) * 4) + (abs(y) * 4 * dim_x);
	color[0] = img[nb];
	color[1] = img[nb + 1];
	color[2] = img[nb + 2];
	color[3] = 0;
	return (*(int *)color);
}

t_color	ft_convert(int color)
{
	t_color	paint;

	paint.b = (color) & 0xFF;
	paint.g = (color >> 8) & 0xFF;
	paint.r = (color >> 16) & 0xFF;
	return (paint);
}

int		ft_plan_fuck(t_vec dir)
{
	if (fabs(dir.y) > fabs(dir.x) && fabs(dir.y) > fabs(dir.z))
		return (1);
	else
		return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.ptri, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;
	t_var *v;

	v = (t_var *)malloc(sizeof(t_var));
	e.error = 0;
	e.ole = 0;
	if (argc != 2)
		ft_error("Wrong Use try : ./rt scene.xml", "");
	ft_init_mlx(&e);
	parse(argv[1], v);
	ft_parse(&e, v);
	e.shadow = 0;
	ft_init_render(&e);
	return (0);
}
