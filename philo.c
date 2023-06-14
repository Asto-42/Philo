/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:17 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 10:24:54 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_input_checker(char **argv)
{
	if (ft_atoi(argv[1]) < 0)
		return (0);
	if (ft_atoi(argv[2]) <= 0)
		return (0);
	if (ft_atoi(argv[3]) <= 0)
		return (0);
	if (ft_atoi(argv[4]) <= 0)
		return (0);
	if (ft_atoi(argv[5]) <= 0)
		return (0);
	return (1);
}

void	ft_error(void)
{
	printf("error\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_context	context;
	t_fork		fork;

	if (argc != 6)
		ft_error();
	if (ft_input_checker(argv) != 1)
		ft_error();
	else
	{
		ft_initialise_data(&philo, argv);
		ft_initialise_fork(&fork, argv);
		ft_initialise_context(&context, &philo, argv);
		ft_generate_thread(&context, &philo, &fork, argv);
	}
}
