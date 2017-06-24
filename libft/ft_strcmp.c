/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 14:46:36 by cluciani          #+#    #+#             */
/*   Updated: 2015/01/12 07:33:59 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else
	{
		i = 0;
		while (s1[i] && s1[i] == s2[i])
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
