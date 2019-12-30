/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:11:16 by jinhong           #+#    #+#             */
/*   Updated: 2019/12/30 13:30:47 by jinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_s(char **s, int n)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
	return (n);
}

static int		copy(char **line, char **s, int index)
{
	char	*temp;
	int		n;

	temp = 0;
	n = 0;
	if (index > -1)
	{
		if (!(*line = ft_substr(*s, 0, index)))
			return (free_s(s, -1));
		if (!(temp = ft_substr(*s, index + 1, ft_strlen(*s) - index - 1)))
			return (free_s(s, -1));
		n = 1;
	}
	else
	{
		if (!(*line = ft_substr(*s, 0, ft_strlen(*s))))
			return (free_s(s, -1));
	}
	free_s(s, 0);
	*s = temp;
	return (n);
}

static int		count(char *s, int index)
{
	int		k;

	while (s[index] != '\0')
	{
		if (s[index] == '\n')
		{
			k = index;
			break ;
		}
		k = -1;
		index++;
	}
	return (k);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s;
	t_file		var_list;

	if (fd < 0 || !line)
		return (free_s(&s, -1));
	while ((var_list.let = read(fd, var_list.buffer, BUFFER_SIZE)) > 0)
	{
		var_list.buffer[var_list.let] = '\0';
		if (!(var_list.temp = ft_strlcat(s, var_list.buffer, var_list.let)))
			return (free_s(&s, -1));
		free_s(&s, 0);
		s = var_list.temp;
		if (ft_strchr(var_list.buffer, '\n'))
			break ;
	}
	if (var_list.let < 0)
		return (free_s(&s, -1));
	if (var_list.let == 0 && (!s || *s == '\0') && (*line = ft_strnew()))
		return (free_s(&s, 0));
	var_list.index = 0;
	return (copy(line, &s, count(s, var_list.index)));
}
