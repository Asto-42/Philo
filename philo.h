/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:29 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 10:19:28 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>

# ifndef FREE
#  define FREE 0
# endif
# ifndef TAKEN
#  define TAKEN 1
# endif
# ifndef WAITING
#  define WAITING 2
# endif
# ifndef DEAD
#  define DEAD 3
# endif
# ifndef DEAD
#  define DEAD 4
# endif
# ifndef DEAD
#  define DEAD 5
# endif

typedef struct s_philo
{
	int		*nb_philo;
	int		*status;
	int		*ttd;
	int		*tte;
	int		*tts;
	int		*need_total_eat;
	int		*have_eat;
	int		last_time_eat;
}t_philo;

typedef struct s_context
{
	pthread_t	thread_nb;
	int			*nb_philo;
	int			total_philo;
	int			total_philo_finish;
	int			ttd;
	int			tts;
	int			tte;
	int			time_start;
	int			last_time;
	int			current_time;
}t_context;

typedef struct s_fork
{
	int		*nb_fork;
	int		*dispo;
}t_fork;

void	ft_initialise_data(t_philo *data, char **argv);
int		ft_atoi(const char *nptr);
void	ft_generate_thread(t_context *context, t_philo *philo, t_fork *fork, char **argv);
void	ft_initialise_fork(t_fork *fork, char **argv);
void	ft_initialise_context(t_context *context, t_philo *philo, char **argv);
#endif
