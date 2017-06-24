/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:37:30 by cluciani          #+#    #+#             */
/*   Updated: 2014/11/06 21:58:34 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			while (s1[i + j] && s2[j])
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
