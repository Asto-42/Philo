/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/06/15 14:55:05 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(void *con)
{
	int			id_philo;
	t_context	*context;
	t_philo		*philo;

	context = con;
	philo = context->philo;
	context = con;
	id_philo = _single_tone_for_id();
	if (((id_philo) - 1) % 2 != 0)
		usleep(context->tte);
	while (context->total_philo_finish != context->total_philo)
	{
		printf("Apres\n");
		ft_check_philo_died(context, philo, id_philo);
		ft_philo_want_eat(context, philo, id_philo);
		ft_philo_want_sleep(context, philo, id_philo);
	}
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;

	x = 0;
	while (++x <= context->total_philo)
	{
		pthread_create(&context->thread_nb, NULL, (void *)ft_start_thread, context);
	}
	//pthread_join
}
