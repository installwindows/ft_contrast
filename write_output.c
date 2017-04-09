/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:09:57 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 22:01:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_contrast.h"

int		write_output(t_pgm *image)
{
	int		x;
	int		y;
	int		fd;
	int		maxlen;

	if ((fd = open(image->option->output, O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (1);
	ft_fprintf(fd, "%s\n", "P2");//TODO add support for multiple magic number
	ft_fprintf(fd, "%d %d\n", image->width, image->height);
	ft_fprintf(fd, "%d\n", image->max_grey_level);
	maxlen = ft_numlen(image->max_grey_level *
		(float)image->option->contrast_level / 100.0 * image->max_grey_level);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			ft_fprintf(fd, "%*d%s", x == 0 ? 1 : maxlen,
				image->pixel[y][x].color, x < image->width - 1 ? " " : "");
			x++;
		}
		ft_fprintf(fd, "\n");
		y++;
	}
	close(fd);
	return (0);
}
