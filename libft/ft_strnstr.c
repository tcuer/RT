/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:14:39 by cluciani          #+#    #+#             */
/*   Updated: 2014/11/10 13:39:21 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			while (s1[i + j] && s2[j] && i + j < n)
			{
				if (s2[j] != s1[i + j])
					break ;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)s1 + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
