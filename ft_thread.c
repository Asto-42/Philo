/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/06/15 16:54:16 by jquil            ###   ########.fr       */
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
	if (((id_philo) - 1) % 3 != 0)
		usleep(context->tte);
	while (context->total_philo_finish != context->total_philo)
	{
		ft_check_philo_died(context, philo, id_philo);
		ft_philo_want_eat(context, philo, id_philo);
		ft_philo_want_sleep(context, philo, id_philo);
	}
	while (42)
		;
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;

	x = 0;
	while (++x <= context->total_philo)
		pthread_create(&context->philo->thread_nb, NULL, (void *)ft_start_thread, context);
	while (42)
		;
	//pthread_join
}
