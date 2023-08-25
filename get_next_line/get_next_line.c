/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:36:36 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/20 21:12:40 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_nextos(char *line)
{
	char	*cuerda;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	cuerda = ft_substr(line, (i + 1), ft_strlen(line));
	free(line);
	line = NULL;
	return (cuerda);
}

char	*ft_line(char **line)
{
	int	i;

	i = 0;
	if (line[0][i] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	return (ft_substr(*line, 0, (i + 1)));
}

char	*ft_reader(int fd, char *line)
{
	char		*buff;
	ssize_t		i;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff);
			free(line);
			line = NULL;
			return (NULL);
		}
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*cuerda;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_reader(fd, line);
	if (line == NULL)
		return (NULL);
	cuerda = ft_line(&line);
	if (cuerda == NULL)
		return (NULL);
	line = ft_nextos(line);
	return (cuerda);
}
