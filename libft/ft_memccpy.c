/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:12:13 by cluciani          #+#    #+#             */
/*   Updated: 2015/01/12 07:48:10 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (n--)
	{
		if ((unsigned char)c == *s2)
		{
			*s1 = *s2;
			return (s1 + 1);
		}
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (NULL);
}
