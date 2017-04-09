/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:48:28 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 21:01:32 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H
# include <stdlib.h>
# include "libft.h"
# define FTC_F 1 << 0
# define FTC_O 1 << 1
# define FTC_C 1 << 2

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_option
{
	int			flags;
	char		*input;
	char		*output;
	int			contrast_level;
}				t_option;


typedef struct	s_pgm
{
	t_option	*option;
	int			magic_number;
	int			type;
	int			width;
	int			height;
	int			max_grey_level;
	int			contrast_level;
	t_pixel		**pixel;
}				t_pgm;

t_pgm			*parse_input(t_option *option);
void			set_contrast(t_pgm *image);
int				write_output(t_pgm *image);

//add to libft
int				ft_strmatch(const char *source, const char *match);

#endif
