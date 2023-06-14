/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:15:46 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 16:42:54 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_initialise_context(t_context *context, char **argv)
{
	unsigned int	x;

	x = -1;
	context->total_philo = ft_atoi(argv[1]);
	context->total_philo_finish = 0;
	context->ttd = ft_atoi(argv[2]);
	context->tte = ft_atoi(argv[3]);
	context->tts = ft_atoi(argv[4]);
	context->last_time = ft_current_time();
	context->current_time = ft_current_time();
	context->rip = 0;
	if (ft_initialise_philo(context, argv) == 0)
		return (0);
	return (1);
}

bool	ft_initialise_philo(t_context *context, char **argv)
{
	unsigned int	x;

	x = -1;
	context->philo = (t_philo *)malloc(context->total_philo * sizeof(t_philo));
	if (!context->philo)
		return (0);
	context->philo[x].forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * context->total_philo);
	context->philo[x].dispo_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * context->total_philo);
	if (!context->philo[x].forks || !context->philo[x].dispo_forks)
		return (0);
	while (++x < context->total_philo)
	{
		context->philo[x].id_philo = x + 1;
		context->philo[x].status = THINKING;
		context->philo[x].ttd = ft_atoi(argv[2]);
		context->philo[x].tte = ft_atoi(argv[3]);
		context->philo[x].tts = ft_atoi(argv[4]);
		if (ft_atoi(argv[5]) == 6)
			context->philo[x].need_eat = ft_atoi(argv[5]);
		else
			context->philo[x].need_eat = 0;
		context->philo[x].total_eat = 0;
		context->philo[x].time_born = ft_current_time();
		context->philo[x].last_time_eat = ft_current_time();
		context->philo[x].last_time_sleep = ft_current_time();
		// pthread_mutex_init(&context->philo->forks[x], NULL);
		// pthread_mutex_init(&context->philo->dispo_forks[x], NULL);
		// context->philo.forks[x] = x;
		// context->philo.dispo_forks = FREE;
	}
	return (1);
}