/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:06:59 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/09 21:57:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_tpool.h"
#define MAX_THREAD 4

typedef struct	s_data
{
	char		val;
}				t_data;

typedef struct	s_work
{
	int			a;
	int			b;
	t_data		**data;
	int			size;
}				t_work;

void	*set_data(void *p)
{
	t_work	*work;
	int		i;
	int		j;

	work = (t_work*)p;
	i = work->a;
	while (i < work->b)
	{
		j = 0;
		while (j < work->size)
		{
			work->data[i][j].val = 42;
			j++;
		}
		i++;
	}
	pthread_exit(p);
}

void	no_thread_set_data(t_data **data, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			data[i][j].val = 42;
			j++;
		}
		i++;
	}
}

void	check_data(t_data **data, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			//printf("%d - ", data[i][j].val);
			if (data[i][j].val != 42)
			{
				printf("Error!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_tp_thread	*tp;
	t_data		**data;
	int			size;
	int			i;
	t_work		work[MAX_THREAD];

	size = 100000;
	data = malloc(sizeof(t_data*) * size);
	i = 0;
	while (i < size)
	{
		data[i] = malloc(sizeof(t_data) * size);
		i++;
	}
	printf("Setting data.\n");
	i = 0;
	while (i < MAX_THREAD)
	{
		work[i].a = i * size / MAX_THREAD;
		work[i].b = (i + 1) * size / MAX_THREAD;
		work[i].data = data;
		work[i].size = size;
		printf("i: %d\na: %d b: %d\n", i, work[i].a, work[i].b);
		i++;
	}
	tp = tp_create(MAX_THREAD);
	i = 0;
	while (i < MAX_THREAD)
	{
		tp_exec_queue_add(tp, set_data, (void*)&work[i]);
		i++;
	}
	tp_wait_for_queue(tp);
	no_thread_set_data(data, size);
	check_data(data, size);
	printf("Ok.\n");
}
