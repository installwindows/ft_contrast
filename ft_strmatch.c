/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:38:48 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/08 20:41:56 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmatch(const char *source, const char *match)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	while (source[i])
	{
		j = 0;
		found = 0;
		while (match[j])
		{
			if (match[j] == source[i])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (1);
		i++;
	}
	return (0);
}
