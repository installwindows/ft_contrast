/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:37:50 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 20:59:43 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static void		usage(void)
{
	ft_fprintf(2, "usage: ft_contrast -f [input.pgm] -c [contrast level] "
					"-o [output.pgm]\n");
}

static t_option	*parse_argv(char **argv)
{
	t_option	*option;

	option = malloc(sizeof(t_option));
	while (*++argv)
	{
		if (!ft_strcmp(*argv, "-f") && !(option->flags & FTC_F) &&
			(option->flags |= FTC_F))
			option->input = ft_strdup(*++argv);
		else if (!ft_strcmp(*argv, "-c") && !(option->flags & FTC_C) &&
			(option->flags |= FTC_C))
		{
			if (ft_strmatch(*++argv, "0123456789"))
				return (NULL);
			option->contrast_level = ft_atoi(*argv);
			if (option->contrast_level < 0 || option->contrast_level > 100)
				return (NULL);
		}
		else if (!ft_strcmp(*argv, "-o") && !(option->flags & FTC_O) &&
				(option->flags |= FTC_O))
			option->output = ft_strdup(*++argv);
		else
			return (NULL);
	}
	return (option);
}

/*
static void		print_option(t_option *option)
{
	ft_printf("flags: %b\n", option->flags);
	ft_printf("input: %s\noutput: %s\ncontrast level: %d\n", option->input,
			option->output, option->contrast_level);
}
*/
int				main(int argc, char **argv)
{
	t_pgm		*image;
	t_option	*option;

	if (argc != 7 || !(option = parse_argv(argv)))
	{
		usage();
		return (1);
	}
	//print_option(option);
	//image = set_sample_image(option);
	//if (image == NULL)
	//{
	//	ft_fprintf(2, "Problem with the sample...\n");
	//	return (0);
	//}
	ft_printf("Reading input.\n");
	if (!(image = parse_input(option)))
	{
		ft_fprintf(2, "Invalid input: %s\n", option->input);
		return (1);
	}
	ft_printf("Setting contrast.\n");
	set_contrast(image);
	ft_printf("Writing output.\n");
	if (write_output(image))
	{
		ft_fprintf(2, "Can't write to output file: %s\n", option->output);
		return (1);
	}
}
