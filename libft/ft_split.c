/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:32:08 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/25 19:17:14 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_frees(char **list)
{
	size_t	m;

	m = 0;
	while (list[m])
	{
		free(list[m]);
		m++;
	}
	free(list);
	return (NULL);
}

size_t	ft_count(char const *s, char c)
{
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
		(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			s_size++;
		i++;
	}
	return (s_size);
}

char	**ft_split(char const *s, char c)
{
	char	**s_list;
	size_t	i;
	size_t	m;
	size_t	enr;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	s_list = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!s_list)
		return (NULL);
	while (i < ft_count(s, c) && s[m] != '\0')
	{
		while (s[m] == c)
			m++;
		enr = m;
		while (s[m] != c && s[m] != '\0')
			m++;
		s_list[i] = ft_strndup(&s[enr], m - enr);
		if (s_list[i++] == 0)
			return (ft_frees(s_list));
	}
	s_list[i] = NULL;
	return (s_list);
}
