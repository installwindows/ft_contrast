/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_contrast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:06:04 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 17:35:17 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

void	set_contrast(t_pgm *image)
{
	int		x;
	int		y;
	float	value;

	value = ((float)image->option->contrast_level / 100.0) ;//*
			//(float)image->max_grey_level;
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			image->pixel[y][x].color *= value;
			x++;
		}
		y++;
	}
	//image->max_grey_level = (float)image->max_grey_level *
	//	(float)image->option->contrast_level / 100.0 * image->max_grey_level;
}

