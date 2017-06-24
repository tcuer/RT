/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluciani <cluciani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:16:58 by cluciani          #+#    #+#             */
/*   Updated: 2015/11/19 18:33:07 by cluciani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE	10

int			get_next_line(const int fd, char **line);
void		ft_end(char **ligne, int i);
size_t		lenline(char *str);
int			ft_init_n_check(char *ligne, char **line, int fd);
char		*ft_readline(const int fd, char *ligne, char *buf, int *ret);

#endif
