/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:29 by jquil             #+#    #+#             */
/*   Updated: 2023/07/11 13:52:15 by jquil            ###   ########.fr       */
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

# define TAKEN 0
# define SLEEPING 2
# define EATING 3
# define THINKING 4
# define DEAD 5

typedef struct s_philo
{
	pthread_t				thread_nb;
	unsigned int			id_philo;
	unsigned int			status;
	long long				ttd;
	unsigned int			max_eat;
	unsigned int			actual_nb_eat;
	long long				last_time_eat;
	unsigned long			last_time_sleep;
	pthread_mutex_t			*lf;
	pthread_mutex_t			*rf;
	struct s_context		*context;
}t_philo;

typedef struct s_context
{
	pthread_mutex_t				death;
	pthread_mutex_t				*fork;
	pthread_mutex_t				standard_exit;
	pthread_mutex_t				single_tone;
	pthread_mutex_t				time;
	pthread_mutex_t				total_finish;
	bool						rip;
	bool						target;
	unsigned int				total_philo;
	unsigned int				total_philo_finish;
	long long					ttd;
	unsigned long				tts;
	unsigned long				tte;
	long long					start_time;
	long long					current_time;
	long long					last_time;
	struct s_philo				*philo;
}t_context;

bool			ft_initialise_philo(t_context *context, char **argv);
unsigned long	ft_atoi(const char *nptr);
void			ft_generate_thread(t_context *context);
bool			ft_initialise_context(t_context *context, char **argv);
void			ft_philo_want_eat(t_context *context, t_philo *philo, int x);
void			ft_philo_want_sleep(t_context *context, t_philo *philo, int x);
void			ft_check_philo_died(t_context *context, t_philo *philo, int x);
void			ft_philo_is_eating(t_context *context, t_philo *philo, int x);
long long		ft_current_time(void);
int				_single_tone_for_id(void);
long long		ft_passed_time(t_context *context);
int				ft_usleep(long long time, t_context *c, t_philo *p);
bool			ft_check_rip(t_context *context, t_philo *philo, int x);
void			ft_print_in_term(t_context *c, int x, char *s, t_philo *p);
void			ft_free_context(t_context *context);
bool			ft_check_finish(t_context *context);
#endif
