/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:15:46 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 11:47:01 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(t_philo *philo, t_fork *fork, t_context *context, int x)
{
	struct timeval	clock;

	//pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITIALIZER;
	philo->time_born[x] = gettimeofday(&clock, NULL);
	if (philo->nb_philo[x] % 2 != 0)
		usleep(context->tte);
	while (context->total_philo_finish != context->total_philo)
	{
		ft_check_philo_died(philo, context, x);
		ft_philo_want_eat(philo, fork, context, x);
		ft_philo_want_sleep(philo, context, x);
	}
}

void	ft_generate_thread(t_context *context, t_philo *philo, t_fork *fork, char **argv)
{
	int	x;

	x = 0;
	(void)fork;
	while (++x < ft_atoi(argv[1]))
	{
		pthread_create(&context->thread_nb, NULL, (void *)ft_start_thread, philo);
	}
}

void	ft_initialise_fork(t_fork *fork, char **argv)
{
	int			nb_fork;
	int			x;

	x = 0;
	nb_fork = ft_atoi(argv[1]);
	fork->nb_fork = malloc (nb_fork * sizeof(int));
	fork->dispo = malloc (nb_fork * sizeof(int));
	while (++x <= nb_fork)
	{
		fork->nb_fork[x] = x;
		fork->dispo[x] = 1;
	}
}

void	ft_initialise_context(t_context *context, t_philo *philo, char **argv)
{
	int				x;
	struct timeval	clock;

	context->nb_philo = malloc (ft_atoi(argv[1]) * (sizeof (int)));
	x = 0;
	context->nb_philo = philo->nb_philo;
	context->time_start = gettimeofday(&clock, NULL);
	context->last_time = context->time_start;
	context->current_time = context->time_start;
	context->total_philo = ft_atoi(argv[1]);
	context->ttd = ft_atoi(argv[2]);
	context->tte = ft_atoi(argv[3]);
	context->tts = ft_atoi(argv[4]);
	context->total_philo_finish = 0;
}

void	ft_initialise_data(t_philo *philo, char **argv)
{
	int	x;
	int	nb;

	x = 0;
	nb = ft_atoi(argv[1]);
	philo->nb_philo = malloc (nb * sizeof(int));
	philo->ttd = malloc (nb * sizeof(int));
	philo->tte = malloc (nb * sizeof(int));
	philo->tts = malloc (nb * sizeof(int));
	philo->need_total_eat = malloc (nb * sizeof(int));
	philo->have_eat = malloc (nb * sizeof(int));
	philo->status = malloc (nb * sizeof(int));
	philo->time_born = malloc (nb * sizeof(int));
	while (++x <= nb)
	{
		philo->nb_philo[x] = x;
		philo->ttd[x] = (int)ft_atoi(argv[2]);
		philo->tte[x] = (int)ft_atoi(argv[3]);
		philo->tts[x] = (int)ft_atoi(argv[4]);
		philo->need_total_eat[x] = ft_atoi(argv[5]);
		philo->have_eat[x] = 0;
		philo->status[x] = THINKING;
		philo->time_born[x] = 0;
	}
}
