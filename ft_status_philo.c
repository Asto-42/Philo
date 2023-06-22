/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/06/22 16:04:40 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_is_eating(t_context *context, t_philo *philo, int x)
{
	philo[x - 1].status = EATING;
	ft_print_in_term(context, x, "is eating");
	if (ft_usleep(context->tte, context) != 1)
		return ;
	philo[x - 1].actual_nb_eat += 1;
	philo[x - 1].tte = context->tte;
	philo[x - 1].status = THINKING;
	if (philo[x - 1].actual_nb_eat == philo[x - 1].max_eat)
	{
		pthread_mutex_lock(&context->total_finish);
		context->total_philo_finish += 1;
		pthread_mutex_unlock(&context->total_finish);
		philo[x - 1].actual_nb_eat += 1;
	}
}

void	ft_check_philo_died(t_context *context, t_philo *philo, int x)
{
	static long long int	last_time;

	if (!last_time)
		last_time = 0;
	pthread_mutex_lock(&context->time);
	context->current_time = ft_passed_time(context);
	philo[x - 1].tte = philo[x - 1].tte - (context->current_time - last_time);
	philo[x - 1].tts = philo[x - 1].tts - (context->current_time - last_time);
	philo[x - 1].ttd = philo[x - 1].ttd - (context->current_time - last_time);
	last_time = context->current_time;
	pthread_mutex_unlock(&context->time);
	if (philo[x - 1].tte <= 0 || philo[x - 1].tts <= 0)
	{
		pthread_mutex_lock(&context->death);
		context->rip = 1;
		pthread_mutex_unlock(&context->death);
		context->philo[x - 1].status = DEAD;
		pthread_mutex_lock(&context->standard_exit);
		printf("DEBUGG PRINTF curr time %lld, tte = %lld, tts = %lld, ttd = %lld\n", context->current_time, philo[x - 1].tte, philo[x - 1].tts, philo[x - 1].ttd);
		printf("%lld %i died\n", ft_passed_time(context), philo[x - 1].id_philo);
		pthread_mutex_unlock(&context->standard_exit);
	}
}
