/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/06/26 14:13:26 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_is_eating(t_context *context, t_philo *philo, int x)
{
	philo[x - 1].status = EATING;
	philo[x - 1].ttd = context->ttd;
	ft_print_in_term(context, x, "is eating");
	if (ft_usleep(context->tte, context, philo, x) != 1)
		return ;
	philo[x - 1].actual_nb_eat += 1;
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
	pthread_mutex_lock(&context->time);
	context->current_time = ft_passed_time(context);
	philo[x - 1].ttd = philo[x - 1].ttd - (context->current_time - context->last_time);
	context->last_time = context->current_time;
	pthread_mutex_unlock(&context->time);
	if (philo[x - 1].ttd <= 0)
	{
		pthread_mutex_lock(&context->death);
		context->rip = 1;
		pthread_mutex_unlock(&context->death);
		context->philo[x - 1].status = DEAD;
		pthread_mutex_lock(&context->standard_exit);
		printf("%lld %i died\n", ft_passed_time(context), x);
		pthread_mutex_unlock(&context->standard_exit);
	}
}
