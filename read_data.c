/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 23:26:57 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 00:35:04 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static int	parse_line(t_pgm *image, int *x, int *y, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
	{
		if (ft_strmatch(split[i], "0123456789"))
		{
			if (split[i][0] == '#')
				break ;
			else
				return (1);
		}
		if (*y == image->height)
			return (1);
		image->pixel[*y][*x].x = *x;
		image->pixel[*y][*x].y = *y;
		image->pixel[*y][*x].color = ft_atoi(split[i]);
		(*x)++;
		if (*x == image->width)
		{
			(*x) = 0;
			(*y)++;
		}
		free(split[i++]);
	}
	while (split[i])
		free(split[i++]);
	free(split);
	return (0);
}

int			read_data(t_pgm *image, int fd)
{
	char	*line;
	int		x;
	int		y;
	int		r;

	image->pixel = malloc(sizeof(t_pixel*) * image->height);
	y = 0;
	while (y < image->height)
		image->pixel[y++] = malloc(sizeof(t_pixel) * image->width);
	y = 0;
	x = 0;
	while ((r = gnl(fd, &line)))
	{
		if (r == -1)
			return (1);
		if (parse_line(image, &x, &y, line))
			return (1);
		free(line);
	}
	if (x != 0 && y != image->height)
		return (1);
	close(fd);
	return (0);
}
