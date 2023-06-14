/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:29 by jquil             #+#    #+#             */
/*   Updated: 2023/06/14 17:04:07 by jquil            ###   ########.fr       */
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
# include <stdbool.h>
# include <pthread.h>


#  define TAKEN 0
#  define FREE 1
#  define SLEEPING 2
#  define EATING 3
#  define THINKING 4
#  define DEAD 5


typedef struct s_philo
{
	unsigned int			id_philo;
	unsigned int			status;
	unsigned long			ttd;
	unsigned long			tte;
	unsigned long			tts;
	unsigned int			need_eat;
	unsigned int			total_eat;
	unsigned long			time_born;
	unsigned long			last_time_eat;
	unsigned long			last_time_sleep;
	pthread_mutex_t				*forks;
	pthread_mutex_t				*dispo_forks;
	struct s_context		*context;
}t_philo;

typedef struct s_context
{
	pthread_t					thread_nb;
	bool						rip;
	unsigned int				total_philo;
	unsigned int				total_philo_finish;
	unsigned long				ttd;
	unsigned long				tts;
	unsigned long				tte;
	unsigned long				last_time;
	unsigned long				current_time;
	struct s_philo	*philo;
}t_context;

bool				ft_initialise_philo(t_context *context, char **argv);
unsigned long		ft_atoi(const char *nptr);
void				ft_generate_thread(t_context *context);
bool				ft_initialise_context(t_context *context, char **argv);
void				ft_philo_want_eat(t_context *context, int id_philo);
void				ft_philo_want_sleep(t_context *context, int id_philo);
void				ft_check_philo_died(t_context *context, int id_philo);
void				ft_philo_is_eating(t_context *context, int id_philo);
unsigned long		ft_current_time(void);
#endif
