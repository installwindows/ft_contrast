/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:20:16 by lwang             #+#    #+#             */
/*   Updated: 2017/04/09 20:57:55 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static t_pgm	*read_header(t_option *option, int fd)
{
	t_pgm *info;
	int r;
	char	**split;
	int i;
	char *line;

	info = (t_pgm*)malloc(sizeof(t_pgm) * 1);
	info->option = option;
	// P2
	r = gnl(fd, &line);
	if (r == 0 || r == -1)
	{
		ft_fprintf(2, "File invalid or Gnl error");
		return (NULL);
	}
	if (ft_strncmp(line, "P2", 2) != 0)
		return (NULL);
	if (!(line[2] == '\0' || line[2] == '#'))
		return (NULL);
	free(line);
	// WIDTH AND HEIGHT
	while ((r = gnl(fd, &line)) == 1)
	{
		if (line[0] != '#')
			break ;
		free(line);
	}
	if (r == 0 || r == -1)
	{
		ft_fprintf(2, "File invalid or Gnl error");
		return (NULL);
	}
	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] && i < 2)
		i++;
	if (split[i] && split[i][0] != '#')
		return (NULL);
	if ((info->width = ft_atoi(split[0])) <= 0)
		return (NULL);
	if ((info->height = ft_atoi(split[1])) <= 0)
		return (NULL);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	free(line);
	// MAX CONTRAST
	while (gnl(fd, &line) == 1)
	{
		if (line[0] != '#') 
			break ;
		free(line);
	}
	if (r == 0 || r == -1)
	{
		ft_fprintf(2, "File invalid or Gnl error");
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	info->max_grey_level = ft_atoi(line);
	if (line[ft_numlen(info->max_grey_level) + i] && line[ft_numlen(info->max_grey_level) + i] != '#')
		return (NULL);
	free(line);
	return (info);
}

static void	print_header(t_pgm *image)
{
	ft_printf("header of %s:\n", image->option->input);
	ft_printf("width: %d\nheight: %d\n", image->width, image->height);
	ft_printf("max grey level: %d\n", image->max_grey_level);
}

t_pgm	*parse_input(t_option *option)
{
	t_pgm *info;
	int fd;

	fd = open(option->input, O_RDONLY);
	if (fd == -1)
	{
		ft_fprintf(2, "Can't open the file: %s\n", option->input);
		return (NULL);
	}
	if (!(info = read_header(option, fd)))
	{
		ft_fprintf(2, "Problem parsing the header of file: %s\n", option->input);
		return (NULL);
	}
	print_header(info);
	if (read_data(info, fd))
	{
		ft_fprintf(2, "Problem parsing the data of file: %s\n", option->input);
		return (NULL);
	}
	return (info);
}
