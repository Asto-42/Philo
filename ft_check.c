/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:03:39 by jquil             #+#    #+#             */
/*   Updated: 2023/06/26 10:03:52 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_check_rip(t_context *context)
{
	pthread_mutex_lock(&context->death);
	if (context->rip == 1)
		return (pthread_mutex_unlock(&context->death), 1);
	return (pthread_mutex_unlock(&context->death), 0);
}

bool	ft_check_finish(t_context *context)
{
	pthread_mutex_lock(&context->total_finish);
	if (context->total_philo_finish != context->total_philo)
		return (pthread_mutex_unlock(&context->total_finish), 0);
	pthread_mutex_unlock(&context->total_finish);
	return (1);
}
