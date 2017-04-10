/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:59:17 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 20:24:19 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpool.h"

t_tp_thread	*tp_create(int n)
{
	t_tp_thread	*tp;

	tp = malloc(sizeof(t_tp_thread));
	tp->size = n;
	tp->current = 0;
	tp->pool = malloc(sizeof(pthread_t) * tp->size);
	return (tp);
}

int			tp_exec_queue_add(t_tp_thread *tp, void (*job)(void *), void *data)
{
	pthread_attr_t	attr;

	if (tp == NULL || tp->size == tp->current)
		return (1);
	pthread_attr_init(&attr);
	pthread_create(&tp->pool[tp->current++], &attr, job, &data);
	return (0);
}

int			tp_wait_for_queue(t_tp_thread *tp)
{
	int		i;

	if (tp == NULL)
		return (1);
	i = 0;
	while (i < tp->current)
	{
		pthread_join(tp->pool[i], NULL);
		i++;
	}
	return (0);
}
