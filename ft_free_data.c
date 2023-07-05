/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:15:27 by jquil             #+#    #+#             */
/*   Updated: 2023/07/05 12:37:39 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_context(t_context *context)
{
	unsigned int	x;

	x = -1;
	while (++x < context->total_philo - 1)
		pthread_mutex_destroy(&context->fork[x]);
	free(context->fork);
	free(context->philo);
	pthread_mutex_destroy(&context->death);
	pthread_mutex_destroy(&context->total_finish);
	pthread_mutex_destroy(&context->time);
	pthread_mutex_destroy(&context->single_tone);
	pthread_mutex_destroy(&context->standard_exit);
}
