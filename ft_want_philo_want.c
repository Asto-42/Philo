/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/06/15 16:52:37 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_want_eat(t_context *context, t_philo *philo, int x)
{
	// if (philo[x - 1].dispo_forks == FREE && x != 1)
	// {
		pthread_mutex_lock(philo[x].lf);
		printf("%lld %i has taken a fork\n", ft_passed_time(context), philo[x].id_philo);
		printf("test\n");
		pthread_mutex_lock(philo[x].rf);
		printf("test\n");
		printf("%lld %i has taken a fork\n", ft_passed_time(context), philo[x].id_philo);
		ft_philo_is_eating(context, philo, x);
		pthread_mutex_unlock(philo[x].rf);
		pthread_mutex_unlock(philo[x].lf);
	//}
	// if (philo[context->total_philo].dispo_forks == FREE && x == 1)
	// {
	// 	pthread_mutex_lock(philo[x].lf);
	// 	printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
	// 	pthread_mutex_lock(philo[context->total_philo].rf);
	// 	printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
	// 	ft_philo_is_eating(context, philo, x);
	// 	pthread_mutex_unlock(philo[x].lf);
	// 	pthread_mutex_unlock(philo[context->total_philo].rf);
	//}
}

//pthread_mutex_lock(
//pthread_mutex_unlock(


void	ft_philo_want_sleep(t_context *context, t_philo *philo, int id_philo)
{
	struct timeval	clock;

	philo[id_philo].status = SLEEPING;
	printf("%i %i is sleeping\n", gettimeofday(&clock, NULL), id_philo);
	usleep(context->tts);
	philo[id_philo].status = THINKING;
}
