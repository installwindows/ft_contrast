/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:48:28 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 19:25:18 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H
# include "libft.h"

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_pgm
{
	char		*path;
	int			magic_number;
	int			type;
	int			width;
	int			height;
	int			max_grey_level;
	int			contrast_level;
	t_pixel		**pixel;
}				t_pgm;

typedef struct	s_option
{
	int			flags;
	char		*input;
	char		*output;
	int			contrast_level;
}				t_option;

#endif
