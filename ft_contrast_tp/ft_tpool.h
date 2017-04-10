/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 19:45:58 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 20:17:44 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TPOOL_H
# define FT_TPOOL_H
# include <pthread.h>

typedef struct	s_tp_thread
{
	pthread_t	*pool;
	int			size;
	int			current;
}				t_tp_thread;

t_tp_thread	*tp_create(int n);
int			tp_exec_queue_add(t_tp_thread *tp, void (*job)(void *), void *data);
int			tp_wait_for_queue(t_tp_thread *tp);

#endif
