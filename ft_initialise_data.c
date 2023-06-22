/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:15:46 by jquil             #+#    #+#             */
/*   Updated: 2023/06/22 16:04:00 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_initialise_context(t_context *context, char **argv)
{
	unsigned int	x;

	x = -1;
	context->rip = 0;
	context->total_philo = ft_atoi(argv[1]);
	context->total_philo_finish = 0;
	context->ttd = ft_atoi(argv[2]);
	context->tte = ft_atoi(argv[3]);
	context->tts = ft_atoi(argv[4]);
	context->start_time = ft_current_time();
	context->current_time = 0;
	if (pthread_mutex_init(&context->standard_exit, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&context->single_tone, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&context->time, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&context->total_finish, NULL) == -1)
		return (0);
	if (context->total_philo > 0)
	{
		context->fork = malloc(sizeof(pthread_mutex_t) * context->total_philo);
		if (pthread_mutex_init(&context->death, NULL) == -1)
			return (0);
		while (++x < context->total_philo)
		{
			if (pthread_mutex_init(&context->fork[x], NULL) == -1)
				return (0);
		}
	}
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
	while (++x < context->total_philo)
	{
		context->philo[x].id_philo = x + 1;
		context->philo[x].status = THINKING;
		context->philo[x].ttd = ft_atoi(argv[2]);
		context->philo[x].tte = ft_atoi(argv[3]);
		context->philo[x].tts = ft_atoi(argv[4]);
		if (ft_atoi(argv[5]) > 0)
			context->philo[x].max_eat = ft_atoi(argv[5]);
		else
			context->philo[x].max_eat = 0;
		context->philo[x].actual_nb_eat = 0;
		context->philo[x].last_time_eat = ft_current_time();
		context->philo[x].last_time_sleep = ft_current_time();
		if (x == context->total_philo - 1)
			context->philo[x].lf = &context->fork[0];
		context->philo[x].lf = &context->fork[x + 1];
		if (x != 0)
			context->philo[x].rf = &context->fork[x];
		else
			context->philo[x].rf = &context->fork[context->total_philo - 1];
	}
	return (1);
}
