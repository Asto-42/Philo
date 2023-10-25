/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_trauma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:03:25 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 21:04:55 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks_1(t_philo *philo)
{
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_unlock(philo->rf);
}

int	take_forks_1(t_context *context, t_philo *philo, int x)
{
	(void)x;
	pthread_mutex_lock(philo->rf);
	ft_print_in_term(context, philo, x, "has taken a fork");
	if (ft_check_rip(context, philo, x) == 1)
	{
		pthread_mutex_unlock(philo->rf);
		return (1);
	}
	pthread_mutex_lock(philo->lf);
	ft_print_in_term(context, philo, x, "has taken a fork");
	if (ft_check_rip(context, philo, x) == 1)
	{
		drop_forks_1(philo);
		return (2);
	}
	return (0);
}

void	drop_forks_2(t_philo *philo)
{
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
}

int	take_forks_2(t_context *context, t_philo *philo, int x)
{
	(void)x;
	pthread_mutex_lock(philo->lf);
	ft_print_in_term(context, philo, x, "has taken a fork");
	if (ft_check_rip(context, philo, x) == 1)
	{
		pthread_mutex_unlock(philo->lf);
		return (1);
	}
	pthread_mutex_lock(philo->rf);
	ft_print_in_term(context, philo, x, "has taken a fork");
	if (ft_check_rip(context, philo, x) == 1)
	{
		drop_forks_2(philo);
		return (2);
	}
	return (0);
}
