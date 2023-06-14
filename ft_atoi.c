/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:08:26 by jquil             #+#    #+#             */
/*   Updated: 2023/06/13 14:53:51 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	s;
	int	i;

	x = 0;
	s = 1;
	i = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-')
		s = -1;
	if (nptr[x] == '-' || nptr[x] == '+')
		x++;
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		i = i + (nptr[x] - 48);
		if (nptr[x + 1] >= 48 && nptr[x + 1] <= 57)
			i = i * 10;
		x++;
	}
	i = i * s;
	return (i);
}
