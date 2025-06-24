/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:22:04 by cfleuret          #+#    #+#             */
/*   Updated: 2025/06/24 15:52:29 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid(t_program *prog, pthread_mutex_t *forks, int n)
{
	int	i;

	if (!prog->philos)
	{
		i = 0;
		destroy(prog);
		while (i < n)
			pthread_mutex_destroy(&forks[i++]);
		free(prog);
		free(forks);
		return (1);
	}
	if (prog->philos[0].time_to_die == 0
		|| prog->philos[0].time_to_eat == 0
		|| prog->philos[0].time_to_sleep == 0
		|| prog->philos[0].num_of_philos == 0
		|| prog->philos[0].num_times_to_eat == 0
		|| prog->philos[0].num_of_philos > 200)
	{
		printf("wrong arguments, might be negative\n");
		free_and_destroy(prog, forks, n);
		return (1);
	}
	return (0);
}

void	locking_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
}

int	check_others(t_philo *philo)
{
	if (is_he_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	return (0);
}

int	is_he_dead(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->prog->dead_lock);
	pthread_mutex_lock(&philo->prog->write_lock);
	is_dead = philo->prog->dead_flag;
	pthread_mutex_unlock(&philo->prog->dead_lock);
	pthread_mutex_unlock(&philo->prog->write_lock);
	return (is_dead);
}

void	died_eating(t_philo *philo)
{
	count_time(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	if (philo->prog->dead_flag == 0)
		printf("%zu philo %d DIED NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
			philo->prog->time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->dead_lock);
	philo->dead = 1;
	philo->prog->dead_flag = 1;
	set_starting(philo->prog, 0);
	pthread_mutex_unlock(philo->dead_lock);
}
