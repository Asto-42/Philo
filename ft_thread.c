/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:11 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 21:00:54 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_thread(void *phil)
{
	t_context	*context;
	t_philo		*philo;

	philo = (t_philo *)phil;
	context = (t_context *)philo->context;
	if ((philo->id_philo) % 2 == 0)
		ft_usleep(context->tte, context, philo);
	while ((ft_check_finish(context) == 0
			|| context->target == 0)
		&& ft_check_rip(context, philo, philo->id_philo) != 1)
	{
		if (ft_philo_want_eat(context, philo, philo->id_philo) == 0)
			break ;
		if (ft_philo_want_sleep(context, philo, philo->id_philo) == 0)
			break ;
		if (ft_philo_want_think(context, philo, philo->id_philo) == 0)
			break ;
	}
	return (0);
}

void	ft_generate_thread(t_context *context)
{
	unsigned int	x;

	x = -1;
	while (++x < context->total_philo)
		pthread_create(&context->philo[x].thread_nb,
			NULL, (void *)ft_start_thread, (void *)&context->philo[x]);
	x = -1;
	while (++x < context->total_philo)
		pthread_join(context->philo[x].thread_nb, NULL);
	ft_free_context(context);
}

// void	ft_generate_thread(t_context *context)
// {
// 	unsigned int	x;

// 	x = -1;
// 	while (++x < context->total_philo)
// 		pthread_create(&context->philo[x].thread_nb,
// 			NULL, (void *)ft_start_thread, context);
// 	x = -1;
// 	while (++x < context->total_philo)
// 		pthread_join(context->philo[x].thread_nb, NULL);
// 	ft_free_context(context);
// }
