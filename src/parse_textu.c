/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 07:31:41 by wmartine          #+#    #+#             */
/*   Updated: 2017/04/12 17:03:02 by wmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_text	parse_normal(t_env *e, t_object *o)
{
	t_text	tex;
	void	*ptr;

	o->nn = 0;
	ptr = mlx_xpm_file_to_image(e->mlx.mlx, o->path2, &tex.width, &tex.height);
	if (!ptr)
	{
		o->nn = 1;
	}
	if (o->nn != 1)
	{
		tex.im = mlx_get_data_addr(ptr, &tex.bpp, &tex.size, &tex.endian);
	}
	return (tex);
}

t_text	parse_textu(t_env *e, t_object *obj)
{
	t_text	tex;
	void	*ptr;

	obj->tt = 0;
	ptr = mlx_xpm_file_to_image(e->mlx.mlx, obj->path, &tex.width, &tex.height);
	if (!ptr)
	{
		obj->tt = 1;
	}
	if (obj->tt != 1)
	{
		tex.im = mlx_get_data_addr(ptr, &tex.bpp, &tex.size, &tex.endian);
	}
	return (tex);
}
