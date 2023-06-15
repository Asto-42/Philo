/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:46 by jquil             #+#    #+#             */
/*   Updated: 2023/06/15 16:45:46 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_passed_time(t_context *context)
{
	context->last_time = context->current_time;
	context->current_time = ft_current_time();
	return (context->current_time - context->start_time);
}

long long	ft_current_time(void)
{
	struct timeval clock;
	unsigned long time;

	gettimeofday(&clock, NULL);
	time = clock.tv_sec * 1000 + clock.tv_usec / 1000;
	return (time);
}

int	_single_tone_for_id(void)
{
	static unsigned int	id_philo;

	if (!id_philo)
		return (0);
	else
		return (++id_philo);
}
