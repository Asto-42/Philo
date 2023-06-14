/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 11:43:30 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_is_eating(t_philo *philo, int nb_philo, t_context *context)
{
	struct timeval	clock;

	philo->status[nb_philo] = EATING;
	printf("%i %i is eating\n", gettimeofday(&clock, NULL), nb_philo);
	usleep(context->tte);
	philo->have_eat[nb_philo] = 1;
	philo->need_total_eat[nb_philo] = philo->need_total_eat[nb_philo] + 1;
	philo->tte[nb_philo] = context->tte;
	philo->status[nb_philo] = THINKING;
}

void	ft_check_philo_died(t_philo *philo, t_context *context, int nb_philo)
{
	struct timeval	clock;

	context->current_time = gettimeofday(&clock, NULL);
	philo->tte[nb_philo] = philo->tte[nb_philo] - context->current_time;
	philo->tts[nb_philo] = philo->tts[nb_philo] - context->current_time;
	philo->ttd[nb_philo] = philo->ttd[nb_philo] - context->current_time;
	if (philo->tte[nb_philo] <= 0 || philo->tts[nb_philo] <= 0 || philo->ttd[nb_philo] <= 0)
	{
		philo->status[nb_philo] = DEAD;
		printf("%i %i died\n", context->tte, nb_philo);
	}
}
