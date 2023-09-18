/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:46 by jquil             #+#    #+#             */
/*   Updated: 2023/09/18 17:03:21 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_passed_time(t_context *context)
{
	long long int	time;

	time = ft_current_time() - context->start_time;
	return (time);
}

long long	ft_current_time(void)
{
	struct timeval	clock;
	unsigned long	time;

	gettimeofday(&clock, NULL);
	time = clock.tv_sec * 1000 + clock.tv_usec / 1000;
	return (time);
}

int	ft_usleep(long long time, t_context *c, t_philo *p)
{
	const long long	start = ft_current_time();
	unsigned int	x;

	x = p->id_philo;
	while ((ft_current_time() - start) < (long long)time / 1000)
	{
		if (ft_check_rip(c, p, x) != 0 || ft_check_finish(c) != 0)
			return (0);
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

void	ft_print_in_term(t_context *c, int x, char *s, t_philo *p)
{
	if (ft_check_rip(c, p, x) == 0)
	{
		pthread_mutex_lock(&c->death);
		pthread_mutex_lock(&c->standard_exit);
		pthread_mutex_lock(&c->time);
		if (c->rip == 0)
			printf("%lld %i %s\n", ft_passed_time(c), x, s);
		pthread_mutex_unlock(&c->time);
		pthread_mutex_unlock(&c->standard_exit);
		pthread_mutex_unlock(&c->death);
	}
}
