/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/06/22 18:21:20 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
{
	if (x % 2 == 0)
	{


		pthread_mutex_lock(philo[x - 1].rf);
		ft_print_in_term(context, x, "has taken a fork");
		pthread_mutex_lock(philo[x - 1].lf);
		ft_print_in_term(context, x, "has taken a fork");
		ft_philo_is_eating(context, philo, x);
		pthread_mutex_unlock(philo[x - 1].lf);
		pthread_mutex_unlock(philo[x - 1].rf);
	}
	else
	{
		pthread_mutex_lock(philo[x - 1].lf);
		ft_print_in_term(context, x, "has taken a fork");
		pthread_mutex_lock(philo[x - 1].rf);
		ft_print_in_term(context, x, "has taken a fork");
		ft_philo_is_eating(context, philo, x);
		pthread_mutex_unlock(philo[x - 1].rf);
		pthread_mutex_unlock(philo[x - 1].lf);
	}
}

void	ft_philo_want_sleep(t_context *context, t_philo *philo, int x)
{
	philo[x - 1].status = SLEEPING;
	ft_print_in_term(context, x, "is sleeping");
	if (ft_usleep(context->tte, context) != 1)
		return ;
	philo[x - 1].tts = context->tts;
	philo[x - 1].status = THINKING;
}
