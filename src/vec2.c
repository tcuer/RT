/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:29:22 by tcuer             #+#    #+#             */
/*   Updated: 2017/05/06 10:29:28 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	dist3d(t_vec a, t_vec b)
{
	return (sqrt(
	(b.x - a.x) * (b.x - a.x)
	+ (b.y - a.y) * (b.y - a.y)
	+ (b.z - a.z) * (b.z - a.z)));
}

t_vec	new_vec(double x, double y, double z)
{
	t_vec p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec	get_vec_from_t(t_vec pos, t_vec raydir, double t)
{
	return (new_vec(
	pos.x + raydir.x * t,
	pos.y + raydir.y * t,
	pos.z + raydir.z * t));
}

double	vec_norm(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec	vec_plus(t_vec a, double b, t_vec dir)
{
	t_vec	ret;

	ret.x = a.x;
	ret.y = a.y;
	ret.z = a.z;
	if (dir.x > 0)
		ret.x = a.x - b;
	if (dir.y > 0)
		ret.y = a.y - b;
	if (dir.z > 0)
		ret.z = a.z - b;
	if (dir.x < 0)
		ret.x = a.x + b;
	if (dir.y < 0)
		ret.y = a.y + b;
	if (dir.z < 0)
		ret.z = a.z + b;
	return (ret);
}
