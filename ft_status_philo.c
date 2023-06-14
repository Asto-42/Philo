/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 16:57:23 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_is_eating(t_context *context, int id_philo)
{
	struct timeval	clock;

	context->philo[id_philo].status = EATING;
	printf("%i %i is eating\n", gettimeofday(&clock, NULL), id_philo);
	usleep(context->tte);
	context->philo[id_philo].total_eat += 1;
	context->philo[id_philo].tte = context->tte;
	context->philo[id_philo].status = THINKING;
}

void	ft_check_philo_died(t_context *context, int id_philo)
{
	struct timeval	clock;

	context->current_time = gettimeofday(&clock, NULL);
	context->philo[id_philo].tte = context->philo[id_philo].tte - context->current_time;
	context->philo[id_philo].tts = context->philo[id_philo].tts - context->current_time;
	context->philo[id_philo].ttd = context->philo[id_philo].ttd - context->current_time;
	if (context->philo[id_philo].tte <= 0 || context->philo[id_philo].tts <= 0 || context->philo[id_philo].ttd <= 0)
	{
		context->philo[id_philo].status = DEAD;
		printf("%lu %i died\n", context->tte, id_philo);
	}
}
