/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:54:45 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/27 15:58:55 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h> 

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals_eaten;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					time;
	int					num_of_philos;
	int					num_times_to_eat;
	int					dead;
	int					eating;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*total_lock;
	pthread_mutex_t		*starting_lock;
	struct s_program	*prog;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	int				starting;
	int				total;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	total_lock;
	pthread_mutex_t	starting_lock;
	t_philo			*philos;
}					t_program;

int		main(int argc, char **argv);
int		ft_atoi(const char *str);
void	*start(void *prog);
size_t	get_current_time(void);
void	free_and_destroy(t_program *prog, pthread_mutex_t *forks, int n);
int		ft_usleep(size_t milliseconds);
int		is_he_dead(t_philo *philo);
int		check_others(t_philo *philo);
void	died_eating(t_philo *philo);
void	printing(t_philo *philo);
void	locking_forks(t_philo *philo);
int		begin(t_program *prog);
void	set_starting(t_program *prog, int running);
void	cannot_eat(t_philo *philo);
int		valid(t_program *prog, pthread_mutex_t *forks, int n);
void	destroy(t_program *prog);

#endif