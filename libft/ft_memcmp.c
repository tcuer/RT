/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:35:57 by cluciani          #+#    #+#             */
/*   Updated: 2015/01/12 07:52:44 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;
	int				calc;

	i = 0;
	n--;
	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	if ((int)n == -1 || ptrs1 == NULL || ptrs2 == NULL)
		return (0);
	while (i < n)
	{
		if (ptrs1[i] == ptrs2[i])
			i++;
		else
			break ;
	}
	calc = ptrs1[i] - ptrs2[i];
	return (calc);
}
