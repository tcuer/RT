/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:57:23 by cluciani          #+#    #+#             */
/*   Updated: 2014/11/10 13:42:06 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s);
	j = 0;
	str = ft_strnew(i);
	if (s == NULL || f == NULL || str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = f(s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
