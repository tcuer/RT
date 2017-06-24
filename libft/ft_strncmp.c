/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:03:36 by cluciani          #+#    #+#             */
/*   Updated: 2015/01/12 07:25:31 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		{
			i++;
		}
	}
	return ((unsigned char)s1[i]) - ((unsigned char)s2[i]);
}
