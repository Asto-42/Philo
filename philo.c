/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:17 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 21:05:32 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_input_checker(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 32767)
		return (0);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[2]) > 32767)
		return (0);
	if (ft_atoi(argv[3]) <= 0 || ft_atoi(argv[3]) > 32767)
		return (0);
	if (ft_atoi(argv[4]) <= 0 || ft_atoi(argv[4]) > 32767)
		return (0);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0 || ft_atoi(argv[5]) > 32767)
			return (0);
	}
	return (1);
}

void	ft_error(void)
{
	printf("error\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 5)
		ft_error();
	if (ft_input_checker(argv) != 1)
		ft_error();
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 is thinking\n");
		printf("0 1 has taken a fork\n");
		usleep(ft_atoi(argv[2]) * 1000);
		printf("%lu 1 died\n", ft_atoi(argv[2]));
		return (0);
	}
	else
	{
		if (ft_initialise_context(&context, argv) == 0)
			return (0);
		ft_generate_thread(&context);
	}
}
