/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:35:18 by tcuer             #+#    #+#             */
/*   Updated: 2017/03/07 17:35:24 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	ft_color_conv(t_color color)
{
	return ((color.r * 65536) + (color.g * 256) + color.b);
}

void			ft_check_scene(char **parse, int i)
{
	if (ft_strcmp(parse[1], "<scene>") != 0)
		ft_error("Missing scene", "");
	if (ft_strcmp(parse[i], "</scene>") != 0)
		ft_error("Missing scene", "");
}

int				ft_error(char *error, char *str)
{
	ft_putstr("Error : ");
	ft_putendl(str);
	ft_putendl(error);
	exit(0);
	return (-1);
}

int				ft_check_class(char *parse)
{
	if (ft_strstr(parse, "/camera") || ft_strstr(parse, "/object")
		|| ft_strstr(parse, "/light") || ft_strstr(parse, "/scene"))
		return (0);
	else
		return (1);
}

void			ft_check_error(char **parse, int i)
{
	if (i < 10)
		ft_error("File too small", "");
	if (!parse[0])
		ft_error("File's empty", "");
	if (ft_strcmp(parse[0], "<?xml version=\"1.0\"?>"))
		ft_error("Wrong version of Xml", "");
}
