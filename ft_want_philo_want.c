/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 21:03:09 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_want_eat_2(t_context *context, t_philo *philo, int x)
{
	int	nb;

	nb = take_forks_1(context, philo, x);
	if (nb == 1)
		return (0);
	philo->ttd = context->ttd;
	philo->last_time_eat = ft_passed_time(context);
	ft_print_in_term(context, philo, x, "is eating");
	if (ft_usleep(context->tte, context, philo) == 1)
	{
		drop_forks_1(philo);
		return (0);
	}
	philo->actual_nb_eat += 1;
	if (philo->actual_nb_eat == philo->max_eat)
	{
		pthread_mutex_lock(&context->total_finish);
		context->total_philo_finish += 1;
		pthread_mutex_unlock(&context->total_finish);
		philo->actual_nb_eat += 1;
	}
	if (nb != 2)
		drop_forks_1(philo);
	return (1);
}

int	ft_philo_want_eat_1(t_context *context, t_philo *philo, int x)
{
	int	nb;

	nb = take_forks_2(context, philo, x);
	if (nb == 1)
		return (0);
	philo->ttd = context->ttd;
	philo->last_time_eat = ft_passed_time(context);
	ft_print_in_term(context, philo, x, "is eating");
	if (ft_usleep(context->tte, context, philo) == 1)
	{
		drop_forks_2(philo);
		return (0);
	}
	philo->actual_nb_eat += 1;
	if (philo->actual_nb_eat == philo->max_eat)
	{
		pthread_mutex_lock(&context->total_finish);
		context->total_philo_finish += 1;
		pthread_mutex_unlock(&context->total_finish);
		philo->actual_nb_eat += 1;
	}
	if (nb != 2)
		drop_forks_2(philo);
	return (1);
}

int	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
{
	if (x % 2 == 0)
	{
		if (ft_philo_want_eat_2(context, philo, x) == 0)
			return (0);
	}
	else
	{
		if (ft_philo_want_eat_1(context, philo, x) == 0)
			return (0);
	}
	return (1);
}

int	ft_philo_want_sleep(t_context *context, t_philo *philo, int x)
{
	ft_print_in_term(context, philo, x, "is sleeping");
	if (ft_usleep(context->tts, context, philo) == 1)
		return (0);
	return (1);
}

int	ft_philo_want_think(t_context *context, t_philo *philo, int x)
{
	ft_print_in_term(context, philo, x, "is thinking");
	if (ft_usleep(context->ttt, context, philo) == 1)
		return (0);
	return (1);
}
