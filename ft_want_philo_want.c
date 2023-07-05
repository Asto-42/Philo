/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/07/05 16:42:55 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_want_eat_single(t_context *context, t_philo *philo, int x)
{
	pthread_mutex_lock(philo[x - 1].lf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	pthread_mutex_lock(philo[x - 1].rf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	ft_philo_is_eating(context, philo, x);
	pthread_mutex_unlock(philo[x - 1].rf);
	pthread_mutex_unlock(philo[x - 1].lf);
}

void	ft_philo_want_eat_double(t_context *context, t_philo *philo, int x)
{
	pthread_mutex_lock(philo[x - 1].rf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	pthread_mutex_lock(philo[x - 1].lf);
	ft_print_in_term(context, x, "has taken a fork", philo);
	ft_philo_is_eating(context, philo, x);
	pthread_mutex_unlock(philo[x - 1].lf);
	pthread_mutex_unlock(philo[x - 1].rf);
}

void	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
{
	if (x % 2 == 0)
		ft_philo_want_eat_double(context, philo, x);
	else
		ft_philo_want_eat_single(context, philo, x);
}

void	ft_philo_want_sleep(t_context *context, t_philo *philo, int x)
{
	philo[x - 1].status = SLEEPING;
	ft_print_in_term(context, x, "is sleeping", philo);
	if (ft_usleep(context->tts, context, philo) != 1)
		return ;
	philo[x - 1].status = THINKING;
	ft_print_in_term(context, x, "is thinking", philo);
}

//content of philo want eat
//	that permits to die a 310ms but cause hellgrind data race :
//
// void	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
// {
// 	if (x % 2 == 0)
// 		ft_philo_want_eat_double(context, philo, x);
// 	else
// 		ft_philo_want_eat_single(context, philo, x);
// 	if ((unsigned int)x == context->total_philo)
// 	{
// 		while (philo[0].status == EATING || philo[x - 2].status == EATING)
// 			ft_check_philo_died(context, philo, x);
// 	}
// 	if (x % 2 == 0)
// 	{
// 		while (philo[x].status == EATING || philo[x - 2].status == EATING)
// 			ft_check_philo_died(context, philo, x);
// 		ft_philo_want_eat_double(context, philo, x);
// 	}
// 	else
// 	{
// 		if (x != 1)
// 		{
// 			while (philo[x].status == EATING || philo[x - 2].status == EATING)
// 				ft_check_philo_died(context, philo, x);
// 		}
// 		else
// 		{
// 			while (philo[x].status == EATING
//				|| philo[context->total_philo - 1].status == EATING)
// 				ft_check_philo_died(context, philo, x);
// 		}
// 		ft_philo_want_eat_single(context, philo, x);
// 	}
// }
