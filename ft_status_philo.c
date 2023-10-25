/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:43:56 by jquil             #+#    #+#             */
/*   Updated: 2023/09/27 13:31:10 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_philo_died(t_context *c, t_philo *p, int x)
{
	pthread_mutex_lock(&c->death);
	if (c->rip == 1)
	{
		pthread_mutex_unlock(&c->death);
		return (1);
	}
	if (ft_passed_time(c) - p->last_time_eat >= c->ttd)
	{
		c->rip = 1;
		pthread_mutex_lock(&c->standard_exit);
		pthread_mutex_lock(&c->time);
		printf("%d %i died\n", ft_passed_time(c), x);
		pthread_mutex_unlock(&c->time);
		pthread_mutex_unlock(&c->standard_exit);
		pthread_mutex_unlock(&c->death);
		return (1);
	}
	pthread_mutex_unlock(&c->death);
	return (0);
}
