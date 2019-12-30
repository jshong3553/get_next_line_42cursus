/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:13:27 by jinhong           #+#    #+#             */
/*   Updated: 2019/12/04 14:14:26 by jinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strlcat(char *s1, char *s2, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strnew(void);

typedef struct	s_file
{
	char		buffer[BUFFER_SIZE + 1];
	int			let;
	char		*temp;
	int			index;
	int			k;
}				t_file;

#endif
