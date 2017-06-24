/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:32:12 by cluciani          #+#    #+#             */
/*   Updated: 2014/11/10 13:47:01 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*s2;

	s2 = (const char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (0);
	else
		ft_strcpy((char*)s2, (char*)s1);
	return ((char *)s2);
}
