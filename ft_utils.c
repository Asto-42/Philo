/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:46 by jquil             #+#    #+#             */
/*   Updated: 2023/06/22 18:13:05 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_passed_time(t_context *context)
{
	long long int	time;
	context->current_time = ft_current_time();
	time = context->current_time - context->start_time;
	return (time);
}

long long	ft_current_time(void)
{
	struct timeval clock;
	unsigned long time;

	gettimeofday(&clock, NULL);
	time = clock.tv_sec * 1000 + clock.tv_usec / 1000;
	return (time);
}

bool	ft_check_rip(t_context *context)
{
	pthread_mutex_lock(&context->death);
	if (context->rip == 1)
		return (pthread_mutex_unlock(&context->death), 1);
	pthread_mutex_unlock(&context->death);
	return (0);
}

bool	ft_check_finish(t_context *context)
{
	pthread_mutex_lock(&context->total_finish);
	if (context->total_philo_finish != context->total_philo)
		return (pthread_mutex_unlock(&context->total_finish), 0);
	pthread_mutex_unlock(&context->total_finish);
	return (1);
}

int	ft_usleep(unsigned long	time, t_context *context)
{
	unsigned long	tempo;

	tempo = 0;
	while (tempo < time)
	{
		ft_check_rip(context);
		tempo += 10;
		usleep(10);
	}
	return (1);
}

int	_single_tone_for_id(void)
{
	static unsigned int	id_philo;

	if (!id_philo)
	{
		id_philo = 1;
		return (id_philo);
	}
	else
		return (++id_philo);
}

void	ft_print_in_term(t_context *context, int x, char *s)
{
	pthread_mutex_lock(&context->standard_exit);
	pthread_mutex_lock(&context->time);
	printf("%lld %i %s\n", ft_passed_time(context), x, s);
	pthread_mutex_unlock(&context->time);
	pthread_mutex_unlock(&context->standard_exit);
}
