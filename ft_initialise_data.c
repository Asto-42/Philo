/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:15:46 by jquil             #+#    #+#             */
/*   Updated: 2023/09/18 14:59:41 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_initialise_context_2(t_context *context)
{
	unsigned long long	x;

	x = -1;
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
	return (1);
}

bool	ft_initialise_context(t_context *context, char **argv)
{
	context->rip = 0;
	context->total_philo = ft_atoi(argv[1]);
	context->total_philo_finish = 0;
	context->ttd = ft_atoi(argv[2]);
	context->tte = ft_atoi(argv[3]) * 1000;
	context->tts = ft_atoi(argv[4]) * 1000;
	context->start_time = ft_current_time();
	context->current_time = 0;
	context->last_time = 0;
	if (argv[5])
		context->target = 1;
	else
		context->target = 0;
	if (ft_initialise_context_2(context) == 0)
		return (0);
	if (ft_initialise_philo(context, argv) == 0)
		return (0);
	return (1);
}

void	ft_fork_assignation(t_context *context, unsigned int x)
{
	context->philo[x].lf = &context->fork[x];
	if (x != 0)
		context->philo[x].rf = &context->fork[x - 1];
	else
		context->philo[x].rf = &context->fork[context->total_philo - 1];
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
		if (argv[5])
			context->philo[x].max_eat = ft_atoi(argv[5]);
		else
			context->philo[x].max_eat = 0;
		context->philo[x].actual_nb_eat = 0;
		context->philo[x].last_time_eat = 0;
		context->philo[x].context = context;
		ft_fork_assignation(context, x);
	}
	return (1);
}
