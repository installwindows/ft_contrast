/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:09:57 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 20:59:18 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static int	ft_itobuf(unsigned short n, char *array)
{
	int		size;
	int		tmp;

	tmp = n;
	size = 1;
	while ((tmp /= 10))
		size++;
	tmp = size;
	while (tmp--)
	{
		array[tmp] = (n % 10) + '0';
		n /= 10;
	}
	return (size);
}

static void	write_line(t_pgm *image, int y, int fd)
{
	char	line[image->width * 6 + 1];
	char	*buf;
	int		x;
	int		size;

	buf = line;
	x = 0;
	while (x < image->width)
	{
		size = ft_itobuf(image->pixel[y][x].color, buf);
		buf[size] = ' ';
		buf += size + 1;
		x++;
	}
	buf[-size] = '\n';
	buf[-size + 1] = '\0';
	write(fd, line, ft_strlen(line));
}

int		write_output(t_pgm *image)
{
	//int		x;
	int		y;
	int		fd;
	int		maxlen;

	if ((fd = open(image->option->output, O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (1);
	ft_fprintf(fd, "%s\n", "P2");
	ft_fprintf(fd, "%d %d\n", image->width, image->height);
	ft_fprintf(fd, "%d\n", image->max_grey_level);
	maxlen = ft_numlen(image->max_grey_level *
		(float)image->option->contrast_level / 100.0 * image->max_grey_level);
	y = 0;
	while (y < image->height)
	{
		if (y % 100 == 0)
			ft_printf("line: %d\r", y);
		/*
		x = 0;
		while (x < image->width)
		{
			ft_fprintf(fd, "%*d%s", x == 0 ? 1 : maxlen,
				image->pixel[y][x].color, x < image->width - 1 ? " " : "");
			x++;
		}
		ft_fprintf(fd, "\n");
		*/
		write_line(image, y, fd);
		free(image->pixel[y]);
		y++;
	}
	ft_printf("\n");
	free(image->pixel);
	close(fd);
	return (0);
}
