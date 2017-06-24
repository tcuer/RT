/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:01:40 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/09 15:01:42 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mlx_pixel_img(void *img, int x, int y, t_color tcolor)
{
	int		i;
	int		color;
	t_img	pxl;

	color = ft_color_conv(tcolor);
	pxl.info = mlx_get_data_addr(img, &pxl.bits, &pxl.size, &pxl.endian);
	i = x * 4 + y * pxl.size;
	pxl.info[i] = color % 256;
	color /= 256;
	pxl.info[i + 1] = color % 256;
	color /= 256;
	pxl.info[i + 2] = color % 256;
	color /= 256;
	pxl.info[i + 3] = 0;
	color /= 256;
}
