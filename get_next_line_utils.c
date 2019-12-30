/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:29:14 by jinhong           #+#    #+#             */
/*   Updated: 2019/12/04 14:05:46 by jinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new[0] = '\0';
		return (new);
	}
	while (((len - i) > 0) && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strlcat(char *s1, char *s2, size_t size)
{
	int		length;
	char	*result;
	int		i;
	int		k;

	length = ft_strlen(s1) + size;
	if (!(result = (char*)malloc(sizeof(char) * (length + 1))))
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2 && s2[k] != '\0')
	{
		result[i] = s2[k];
		k++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (c == str[index])
			return ((char*)&(str[index]));
		index++;
	}
	if (c == str[index])
		return ((char*)&(str[index]));
	return (NULL);
}

char	*ft_strnew(void)
{
	char	*n;

	if (!(n = (char*)malloc(sizeof(char))))
		return (0);
	n[0] = '\0';
	return (n);
}
