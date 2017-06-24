/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:39:10 by cluciani          #+#    #+#             */
/*   Updated: 2015/12/08 16:51:59 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	ft_end(char **ligne, int i)
{
	void		*ptr;

	ptr = *ligne;
	*ligne = ft_strdup(*ligne + i + 1);
	free(ptr);
}

int		get_next_line(const int fd, char **line)
{
	size_t		i;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*ligne = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 0;
	if (!ft_strchr(ligne, '\n'))
		ligne = ft_readline(fd, ligne, buf, &ret);
	if (ligne == NULL && ret < 0)
		return (-1);
	if (ret == 0 && !ft_strlen(ligne))
		return (0);
	i = lenline(ligne);
	*line = ft_strnew(i + 1);
	if (*line == NULL || ret < 0)
		return (-1);
	ft_memcpy(*line, ligne, (int)i);
	(*line)[i] = '\0';
	ft_end(&ligne, i);
	return (1);
}

char	*ft_readline(const int fd,
					char *ligne, char *buf, int *ret)
{
	void	*tmp;

	while ((*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (NULL);
		buf[*ret] = '\0';
		if (!ft_strchr(buf, '\n'))
		{
			tmp = ligne;
			ligne = ft_strjoin(ligne, buf);
			free(tmp);
		}
		else
		{
			tmp = ligne;
			ligne = ft_strjoin(ligne, buf);
			free(tmp);
			break ;
		}
	}
	return (ligne);
}

size_t	lenline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
