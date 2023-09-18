/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/09/18 16:34:23 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_want_eat_single(t_context *context, t_philo *philo, int x)
{
	pthread_mutex_lock(philo->lf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	pthread_mutex_lock(philo->rf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	ft_philo_is_eating(context, philo, x);
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
}

void	ft_philo_want_eat_double(t_context *context, t_philo *philo, int x)
{
	pthread_mutex_lock(philo->rf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	pthread_mutex_lock(philo->lf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	ft_philo_is_eating(context, philo, x);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_unlock(philo->rf);
}

void	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
{
	if ((unsigned int)x != context->total_philo)
		ft_philo_want_eat_single(context, philo, x);
	else
		ft_philo_want_eat_double(context, philo, x);
}

void	ft_philo_want_sleep(t_context *context, t_philo *philo, int x)
{
	unsigned long long time;

	if ((context->ttd - (context->tte + context->tts) > context->tte))
		time = context->tte;
	else
		time = ((context->ttd - (context->tte + context->tts)) / 5);
	philo->status = SLEEPING;
	ft_print_in_term(context, x, "is sleeping", philo);
	if (ft_usleep(context->tts, context, philo) != 1)
		return ;
	philo->status = THINKING;
	ft_print_in_term(context, x, "is thinking", philo);
	if ((context->total_philo % 2 != 0))
	{
		if (ft_usleep(time, context, philo) != 1)
			return ;
	}
}
