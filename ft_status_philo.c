/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/09/18 16:03:25 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_is_eating(t_context *context, t_philo *philo, int x)
{
	philo->status = EATING;
	philo->ttd = context->ttd;
	pthread_mutex_lock(&context->time);
	philo->last_time_eat = ft_passed_time(context);
	pthread_mutex_unlock(&context->time);
	ft_print_in_term(context, x, "is eating", philo);
	if (ft_usleep(context->tte, context, philo) != 1)
		return ;
	philo->actual_nb_eat += 1;
	philo->status = THINKING;
	ft_print_in_term(context, x, "is thinking", philo);
	if (philo->actual_nb_eat == philo->max_eat)
	{
		pthread_mutex_lock(&context->total_finish);
		context->total_philo_finish += 1;
		pthread_mutex_unlock(&context->total_finish);
		philo->actual_nb_eat += 1;
	}
}

void	ft_check_philo_died(t_context *context, t_philo *philo, int x)
{
	long long	time;
	long long	time_eat;

	pthread_mutex_lock(&context->death);
	if (context->rip == 1)
	{
		pthread_mutex_unlock(&context->death);
		return ;
	}
	pthread_mutex_unlock(&context->death);
	pthread_mutex_lock(&context->time);
	context->current_time = ft_passed_time(context);
	time = context->current_time;
	time_eat = philo->last_time_eat;
	pthread_mutex_unlock(&context->time);
	pthread_mutex_lock(&context->death);
	if ((time - time_eat) >= context->ttd && context->rip == 0)
	{
		context->rip = 1;
		pthread_mutex_lock(&context->standard_exit);
		pthread_mutex_lock(&context->time);
		printf("%lld %i died\n", time, x);
		pthread_mutex_unlock(&context->time);
		pthread_mutex_unlock(&context->standard_exit);
	}
	pthread_mutex_unlock(&context->death);
}
