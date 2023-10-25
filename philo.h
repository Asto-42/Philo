/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:29 by jquil             #+#    #+#             */
/*   Updated: 2023/09/26 21:04:40 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
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
	int						ttd;
	unsigned int			max_eat;
	unsigned int			actual_nb_eat;
	int						last_time_eat;
	int						last_time_sleep;
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
	int							ttd;
	int							tts;
	int							tte;
	int							ttt;
	int							start;
	int							start_time;
	int							current_time;
	int							last_time;
	struct s_philo				*philo;
}t_context;

bool			ft_initialise_philo(t_context *context, char **argv);
unsigned long	ft_atoi(const char *nptr);
void			ft_generate_thread(t_context *context);
bool			ft_initialise_context(t_context *context, char **argv);
int				ft_philo_want_eat(t_context *context, t_philo *philo, int x);
int				ft_philo_want_sleep(t_context *context, t_philo *philo, int x);
int				ft_philo_want_think(t_context *context, t_philo *philo, int x);
int				ft_check_philo_died(t_context *context, t_philo *philo, int x);
void			ft_philo_is_eating(t_context *context, t_philo *philo, int x);
int				ft_current_time(void);
int				ft_passed_time(t_context *context);
int				ft_usleep(int time, t_context *c, t_philo *p);
bool			ft_check_rip(t_context *context, t_philo *philo, int x);
void			ft_print_in_term(t_context *c, t_philo *p, int x, char *s);
void			ft_free_context(t_context *context);
bool			ft_check_finish(t_context *context);
void			drop_forks_1(t_philo *philo);
int				take_forks_1(t_context *context, t_philo *philo, int x);
void			drop_forks_2(t_philo *philo);
int				take_forks_2(t_context *context, t_philo *philo, int x);
#endif
