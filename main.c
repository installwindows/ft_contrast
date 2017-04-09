/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:37:50 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 19:50:09 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static void		usage(void)
{
	ft_fprintf(2, "usage: ft_contrast -f [input.pgm] -c [contrast level] "
					"-o [output.pgm]\n");
}

static t_option	*parse_argv(int argc, char **argv)
{
	ft_printf("Ayy\n");
	return (NULL);
}

int				main(int argc, char **argv)
{
	t_pgm		*image;
	t_option	*option;

	if (argc != 7 || !(option = parse_argv(argc, argv)))
	{
		usage();
		return (1);
	}
}
