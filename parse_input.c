/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:20:16 by lwang             #+#    #+#             */
/*   Updated: 2017/04/09 00:29:37 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

// void	error(char *s)
// {
// 	ft_putstr(s);
// 	return (NULL);
// }

// char *strncut(char *s, int n)
// {
// 	char *dst;
// 	int i;
// 	int j;

// 	if (n > ft_strlen(s))
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	dst = s;
// 	while (s[i++])
// 		dst[j++] = s[i++ + n];
// 	dst[j] = '\0';
// 	return (dst);
// }


// int	ft_nbrlen(int nbr)
// {
// 	int i;

// 	i = 0;
// 	while (nbr >= 1)
// 	{
// 		nbr /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// t_pixel	**each_line(char **s, int j, t_pgm **info)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	if (i != info->info->width && s[info->info->width + 1] != '#')
// 		error("wrong file body");
// 	info->pixel[j] = (t_pixel**)malloc(sizeof(t_pixel*) * (i + 1));
// 	i = 0;
// 	while (s[i])
// 	{
// 		info->pixel-> = (t_pixel*)malloc(sizeof(t_pixel))
// 		info->pixel->
// 	}

// }

// void	check_image(int fd, char *line, t_pgm **info)
// {
// 	int j;

// 	j = 0;
// 	while (gnl(fd, &line))
// 	{
// 		info->pixel[j] = each_line(ft_strsplit(line, ' '), j, info);
// 		j++;
// 	}
// }

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

// static int read_data(t_pgm *image, int fd)
// {
// 	check_image(fd, line, &info);
// 	return (0);
// }

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
	if (read_data(info, fd))
	{
		ft_fprintf(2, "Problem parsing the data of file: %s\n", option->input);
		return (NULL);
	}
	return (info);
}
