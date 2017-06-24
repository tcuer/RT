/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:27:19 by cluciani          #+#    #+#             */
/*   Updated: 2015/05/18 17:54:33 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (s == NULL)
		return (NULL);
	cpy = (char *)malloc(len + 1);
	i = 0;
	if (cpy != NULL)
	{
		while (i < len && s[start + i])
		{
			cpy[i] = ((char*)s)[start + i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
