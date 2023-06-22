/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/06/22 16:17:13 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(void *con)
{
	int			id_philo;
	t_context	*context;
	t_philo		*philo;

	context = con;
	philo = context->philo;
	pthread_mutex_lock(&context->single_tone);
	id_philo = _single_tone_for_id();
	pthread_mutex_unlock(&context->single_tone);
	if ((id_philo) % 2 == 0)
	{
		if (ft_usleep(context->tte, context) != 1)
			return ;
	}
	while (context->total_philo_finish != context->total_philo && ft_check_rip(context) == 0)
	{
		pthread_mutex_lock(&context->standard_exit);
		//printf("total finish = %i\ttotal philo = %i\nphilo actual eat = %i\tphilo max eat = %i\n", context->total_philo_finish, context->total_philo, philo[id_philo - 1].actual_nb_eat, philo[id_philo - 1].max_eat);
		pthread_mutex_unlock(&context->standard_exit);
		ft_check_philo_died(context, philo, id_philo);
		if (ft_check_rip(context) == 0)
			ft_philo_want_eat(context, philo, id_philo);
		if (ft_check_rip(context) == 0)
			ft_philo_want_sleep(context, philo, id_philo);
		ft_usleep(100, context);
	}
	//ft_exit(context, philo);
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;

	x = 0;
	while (x <= context->total_philo)
		pthread_create(&context->philo->thread_nb, NULL, (void *)ft_start_thread, context);
	while (42)
		;
	//pthread_join
}
