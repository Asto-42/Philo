/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 18:02:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(void *philo)
{
	t_philo		*phi;
	t_context	*context;
	unsigned int	id_philo;

	phi = philo;
	context = phi->context;
	//pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITIALIZER;
	if (context->philo->id_philo[id_philo - 1] % 2 != 0)
		usleep(context->tte);
	while (context->total_philo_finish != context->total_philo)
	{
		ft_check_philo_died(context, id_philo);
		ft_philo_want_eat(context, id_philo);
		ft_philo_want_sleep(id_philo);
	}
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;
	unsigned int	id_philo;

	x = 0;
	while (++x <= context->total_philo)
	{
		id_philo = context->philo[x].id_philo;
		pthread_create(&context->thread_nb, NULL, (void *)ft_start_thread, context->philo[x]);
	}
	//pthread_join
}
