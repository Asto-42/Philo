/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:46 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 20:21:16 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_passed_time(t_context *context)
{
	int	time;

	time = ft_current_time() - context->start_time;
	return (time);
}

int	ft_current_time(void)
{
	struct timeval	clock;
	int				time;

	if (gettimeofday(&clock, NULL) == -1)
		return (-1);
	time = clock.tv_sec * 1000 + clock.tv_usec / 1000;
	return (time);
}

int	ft_usleep(int time, t_context *c, t_philo *p)
{
	int	start;

	start = ft_current_time();
	while ((ft_current_time() - start) < time)
	{
		usleep(500);
		if (ft_passed_time(c) - p->last_time_eat >= c->ttd)
			return (ft_check_philo_died(c, p, p->id_philo));
	}
	return (0);
}

void	ft_print_in_term(t_context *c, t_philo *p, int x, char *s)
{
	if (ft_check_rip(c, p, x) == 0)
	{
		pthread_mutex_lock(&c->death);
		pthread_mutex_lock(&c->standard_exit);
		if (c->rip == 0)
			printf("%i %i %s\n", ft_passed_time(c), x, s);
		pthread_mutex_unlock(&c->standard_exit);
		pthread_mutex_unlock(&c->death);
	}
}
