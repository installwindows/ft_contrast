/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:30:56 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 23:48:46 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

t_pgm	*set_sample_image(t_option *option)
{
	int		fd;
	t_pgm	*image;

	image = malloc(sizeof(t_pgm));
	image->option = option;
	image->magic_number = 2;
	image->type = 0;
	image->width = 24;
	image->height = 7;
	image->max_grey_level = 15;
	image->contrast_level = option->contrast_level;
	image->pixel = malloc(sizeof(t_pixel*) * 7);
	for (int i = 0; i < 7; i++)
		image->pixel[i] = malloc(sizeof(t_pixel) * 24);
	if ((fd = open(option->input, O_RDONLY)) == -1)
		return (NULL);
	if (read_data(image, fd))
		return (NULL);
	return (image);
}
	/*
	image->pixel = pixel;
	image->pixel[0][0].color = 0;
	image->pixel[0][1].color = 0;
	image->pixel[0][2].color = 0;
	image->pixel[0][3].color = 0;
	image->pixel[0][4].color = 0;
	image->pixel[0][5].color = 0;
	image->pixel[0][6].color = 0;
	image->pixel[0][7].color = 0;
	image->pixel[0][8].color = 0;
	image->pixel[0][9].color = 0;
	image->pixel[0][10].color = 0;
	image->pixel[0][11].color = 0;
	image->pixel[0][12].color = 0;
	image->pixel[0][13].color = 0;
	image->pixel[0][14].color = 0;
	image->pixel[0][15].color = 0;
	image->pixel[0][16].color = 0;
	image->pixel[0][17].color = 0;
	image->pixel[0][18].color = 0;
	image->pixel[0][19].color = 0;
	image->pixel[0][20].color = 0;
	image->pixel[0][21].color = 0;
	image->pixel[0][22].color = 0;
	image->pixel[0][23].color = 0;
	image->pixel[1][0].color = 0;
	image->pixel[1][1].color = 3;
	image->pixel[1][2].color = 3;
	image->pixel[1][3].color = 3;
	image->pixel[1][4].color = 3;
	image->pixel[1][5].color = 0;
	image->pixel[1][6].color = 0;
	image->pixel[1][7].color = 7;
	image->pixel[1][8].color = 7;
	image->pixel[1][9].color = 7;
	image->pixel[1][10].color = 7;
	image->pixel[1][11].color = 0;
	image->pixel[1][12].color = 0;
	image->pixel[1][13].color = 11;
	image->pixel[1][14].color = 11;
	image->pixel[1][15].color = 11;
	image->pixel[1][16].color = 11;
	image->pixel[1][17].color = 0;
	image->pixel[1][18].color = 0;
	image->pixel[1][19].color = 15;
	image->pixel[1][20].color = 15;
	image->pixel[1][21].color = 15;
	image->pixel[1][22].color = 15;
	image->pixel[1][23].color = 0;
	image->pixel[2][0].color = 0;
	image->pixel[2][1].color = 3;
	image->pixel[2][2].color = 0;
	image->pixel[2][3].color = 0;
	image->pixel[2][4].color = 0;
	image->pixel[2][5].color = 0;
	image->pixel[2][6].color = 0;
	image->pixel[2][7].color = 7;
	image->pixel[2][8].color = 0;
	image->pixel[2][9].color = 0;
	image->pixel[2][10].color = 0;
	image->pixel[2][11].color = 0;
	image->pixel[2][12].color = 0;
	image->pixel[2][13].color = 11;
	image->pixel[2][14].color = 0;
	image->pixel[2][15].color = 0;
	image->pixel[2][16].color = 0;
	image->pixel[2][17].color = 0;
	image->pixel[2][18].color = 0;
	image->pixel[2][19].color = 15;
	image->pixel[2][20].color = 0;
	image->pixel[2][21].color = 0;
	image->pixel[2][22].color = 15;
	image->pixel[2][23].color = 0;
	image->pixel[3][0].color = 0;
	image->pixel[3][1].color = 3;
	image->pixel[3][2].color = 3;
	image->pixel[3][3].color = 3;
	image->pixel[3][4].color = 0;
	image->pixel[3][5].color = 0;
	image->pixel[3][6].color = 0;
	image->pixel[3][7].color = 7;
	image->pixel[3][8].color = 7;
	image->pixel[3][9].color = 7;
	image->pixel[3][10].color = 0;
	image->pixel[3][11].color = 0;
	image->pixel[3][12].color = 0;
	image->pixel[3][13].color = 11;
	image->pixel[3][14].color = 11;
	image->pixel[3][15].color = 11;
	image->pixel[3][16].color = 0;
	image->pixel[3][17].color = 0;
	image->pixel[3][18].color = 0;
	image->pixel[3][19].color = 15;
	image->pixel[3][20].color = 15;
	image->pixel[3][21].color = 15;
	image->pixel[3][22].color = 15;
	image->pixel[3][23].color = 0;
	image->pixel[4][0].color = 0;
	image->pixel[4][1].color = 3;
	image->pixel[4][2].color = 0;
	image->pixel[4][3].color = 0;
	image->pixel[4][4].color = 0;
	image->pixel[4][5].color = 0;
	image->pixel[4][6].color = 0;
	image->pixel[4][7].color = 7;
	image->pixel[4][8].color = 0;
	image->pixel[4][9].color = 0;
	image->pixel[4][10].color = 0;
	image->pixel[4][11].color = 0;
	image->pixel[4][12].color = 0;
	image->pixel[4][13].color = 11;
	image->pixel[4][14].color = 0;
	image->pixel[4][15].color = 0;
	image->pixel[4][16].color = 0;
	image->pixel[4][17].color = 0;
	image->pixel[4][18].color = 0;
	image->pixel[4][19].color = 15;
	image->pixel[4][20].color = 0;
	image->pixel[4][21].color = 0;
	image->pixel[4][22].color = 0;
	image->pixel[4][23].color = 0;
	image->pixel[5][0].color = 0;
	image->pixel[5][1].color = 3;
	image->pixel[5][2].color = 0;
	image->pixel[5][3].color = 0;
	image->pixel[5][4].color = 0;
	image->pixel[5][5].color = 0;
	image->pixel[5][6].color = 0;
	image->pixel[5][7].color = 7;
	image->pixel[5][8].color = 7;
	image->pixel[5][9].color = 7;
	image->pixel[5][10].color = 7;
	image->pixel[5][11].color = 0;
	image->pixel[5][12].color = 0;
	image->pixel[5][13].color = 11;
	image->pixel[5][14].color = 11;
	image->pixel[5][15].color = 11;
	image->pixel[5][16].color = 11;
	image->pixel[5][17].color = 0;
	image->pixel[5][18].color = 0;
	image->pixel[5][19].color = 15;
	image->pixel[5][20].color = 0;
	image->pixel[5][21].color = 0;
	image->pixel[5][22].color = 0;
	image->pixel[5][23].color = 0;
	image->pixel[6][0].color = 0;
	image->pixel[6][1].color = 0;
	image->pixel[6][2].color = 0;
	image->pixel[6][3].color = 0;
	image->pixel[6][4].color = 0;
	image->pixel[6][5].color = 0;
	image->pixel[6][6].color = 0;
	image->pixel[6][7].color = 0;
	image->pixel[6][8].color = 0;
	image->pixel[6][9].color = 0;
	image->pixel[6][10].color = 0;
	image->pixel[6][11].color = 0;
	image->pixel[6][12].color = 0;
	image->pixel[6][13].color = 0;
	image->pixel[6][14].color = 0;
	image->pixel[6][15].color = 0;
	image->pixel[6][16].color = 0;
	image->pixel[6][17].color = 0;
	image->pixel[6][18].color = 0;
	image->pixel[6][19].color = 0;
	image->pixel[6][20].color = 0;
	image->pixel[6][21].color = 0;
	image->pixel[6][22].color = 0;
	image->pixel[6][23].color = 0;
	return (image);
}
*/
