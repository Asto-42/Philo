/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_want_philo_want.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:36:49 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 16:51:14 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"

void	ft_philo_want_eat(t_context *context, int id_philo)
{
	struct timeval	clock;

	if (philo->have_eat[x] == 0 && fork->dispo[x] == FREE)
	{
		if (fork->dispo[x - 1] == FREE && x != 1)
		{
			fork->dispo[x] = TAKEN;
			printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
			fork->dispo[x - 1] = TAKEN;
			printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
			ft_philo_is_eating(philo, x, context);
			fork->dispo[x] = FREE;
			fork->dispo[x - 1] = FREE;
		}
		if (fork->dispo[context->total_philo] == FREE && x == 1)
		{
			fork->dispo[x] = TAKEN;
			printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
			fork->dispo[context->total_philo] = TAKEN;
			printf("%i %i has taken a fork\n", gettimeofday(&clock, NULL), x);
			ft_philo_is_eating(philo, x, context);
			fork->dispo[x] = FREE;
			fork->dispo[context->total_philo] = FREE;
		}
	}
}

void	ft_philo_want_sleep(t_context *context, int id_philo)
{
	struct timeval	clock;
	if (philo->have_eat[id_philo] == 1)
	{
		philo->status[id_philo] = SLEEPING;
		printf("%i %i is sleeping\n", gettimeofday(&clock, NULL), id_philo);
		usleep(context->tts);
		philo->have_eat[id_philo] = 0;
		philo->status[id_philo] = THINKING;
	}
}
