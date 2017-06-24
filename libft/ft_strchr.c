/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:12:22 by cluciani          #+#    #+#             */
/*   Updated: 2015/01/12 07:53:05 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			d;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	d = (char)c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == d)
			return (((char*)s + i));
		i++;
	}
	return (NULL);
}
