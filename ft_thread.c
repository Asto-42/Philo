/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/06/26 12:26:21 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_thread(void *con)
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
		ft_usleep(context->tte, context, philo, id_philo);
	while (ft_check_finish(context) == 0 && ft_check_rip(context) == 0)
	{
		ft_check_philo_died(context, philo, id_philo);
		if (ft_check_rip(context) == 0)
			ft_philo_want_eat(context, philo, id_philo);
		if (ft_check_rip(context) == 0)
			ft_philo_want_sleep(context, philo, id_philo);
		if (ft_usleep(10, context, philo, id_philo) != 1)
			break ;
	}
	return (0);
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;

	x = 0;
	while (++x <= context->total_philo)
		pthread_create(&context->philo->thread_nb,
			NULL, (void *)ft_start_thread, context);
	pthread_join(context->philo->thread_nb, NULL);
	if (ft_check_rip(context) == 0)
	{
		pthread_mutex_lock(&context->standard_exit);
		printf("\nTotal philo finish = %i\t\tTotal philo = %i\nTout le monde a tape sa meilleure graille et tout le monde est en vie oklm\n", context->total_philo_finish, context->total_philo);
		pthread_mutex_unlock(&context->standard_exit);
	}
	ft_free_context(context);
}
