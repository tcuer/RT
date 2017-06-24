/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_limit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:38:06 by cluciani          #+#    #+#             */
/*   Updated: 2017/05/10 16:38:07 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylinder	*cylinder_pos(t_cylinder *c)
{
	c->limit.f1 = c->pos;
	c->limit.f1.y = c->pos.y + c->length;
	c->limit.f2 = c->pos;
	c->limit.f2.y = c->pos.y - c->length;
	c->limit.f3 = c->pos;
	c->limit.f3.x = c->pos.x + c->length;
	c->limit.f4 = c->pos;
	c->limit.f4.x = c->pos.x - c->length;
	c->limit.f5 = c->pos;
	c->limit.f5.z = c->pos.z + c->length;
	c->limit.f6 = c->pos;
	c->limit.f6.z = c->pos.z - c->length;
	return (c);
}

t_cylinder	cylinder_pos2(t_cylinder c)
{
	c.limit.f1 = c.pos;
	c.limit.f1.y = c.pos.y + c.length;
	c.limit.f2 = c.pos;
	c.limit.f2.y = c.pos.y - c.length;
	c.limit.f3 = c.pos;
	c.limit.f3.x = c.pos.x + c.length;
	c.limit.f4 = c.pos;
	c.limit.f4.x = c.pos.x - c.length;
	c.limit.f5 = c.pos;
	c.limit.f5.z = c.pos.z + c.length;
	c.limit.f6 = c.pos;
	c.limit.f6.z = c.pos.z - c.length;
	return (c);
}

t_cylinder	*cylinder_limit(t_vec ray, t_vec o,
			t_cylinder *c, double d)
{
	c = cylinder_pos(c);
	c->limit.t1 = vec_dot_product(vec_minus(c->limit.f1,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	c->limit.t2 = vec_dot_product(vec_minus(c->limit.f2,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	c->limit.t3 = vec_dot_product(vec_minus(c->limit.f3,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	c->limit.t4 = vec_dot_product(vec_minus(c->limit.f4,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	c->limit.t5 = vec_dot_product(vec_minus(c->limit.f5,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	c->limit.t6 = vec_dot_product(vec_minus(c->limit.f6,
		vec_add(o, vec_multiply(ray, d))), c->dir);
	return (c);
}

int			cylinder_limit2(t_cylinder *c)
{
	if (c->dir.y > 0 && (c->limit.t1 < 0 || c->limit.t2 > 0))
		return (1);
	if (c->dir.x > 0 && (c->limit.t3 < 0 || c->limit.t4 > 0))
		return (1);
	if (c->dir.z > 0 && (c->limit.t5 < 0 || c->limit.t6 > 0))
		return (1);
	if (c->dir.y < 0 && (c->limit.t2 < 0 || c->limit.t1 > 0))
		return (1);
	if (c->dir.x < 0 && (c->limit.t4 < 0 || c->limit.t3 > 0))
		return (1);
	if (c->dir.z < 0 && (c->limit.t6 < 0 || c->limit.t5 > 0))
		return (1);
	return (0);
}
