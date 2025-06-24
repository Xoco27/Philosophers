/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:33:29 by cfleuret          #+#    #+#             */
/*   Updated: 2025/06/24 15:51:37 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		cannot_eat(philo);
		return ;
	}
	locking_forks(philo);
	if (check_others(philo) == 1)
		return ;
	if ((get_current_time() - philo->last_meal) >= philo->time_to_die)
	{
		died_eating(philo);
		return ;
	}
	printing(philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	if (check_others(philo) == 1)
		return ;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	printing(philo);
	count_time(philo);
}

static void	philo_sleeping(t_philo *philo)
{
	if (is_he_dead(philo) == 1)
		return ;
	pthread_mutex_lock(philo->write_lock);
	if (philo->prog->dead_flag == 0)
		printf("%zu philo %d is sleeping\n", philo->prog->time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(philo->time_to_sleep, philo);
	if (is_he_dead(philo) == 1)
		return ;
	if (get_current_time() - philo->last_meal >= philo->time_to_die)
	{
		count_time(philo);
		pthread_mutex_lock(philo->dead_lock);
		pthread_mutex_lock(philo->write_lock);
		if (philo->prog->dead_flag == 0)
			printf("%zu philo %d DIED NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
				philo->prog->time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->dead = 1;
		philo->prog->dead_flag = 1;
		set_starting(philo->prog, 0);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	count_time(philo);
}

static int	philo_thinking(t_philo *philo)
{
	int	time_to_think;

	pthread_mutex_lock(philo->dead_lock);
	pthread_mutex_lock(philo->write_lock);
	if (philo->prog->dead_flag == 0)
		printf("%zu philo %d is thinking\n", philo->prog->time, philo->id);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->write_lock);
	time_to_think = philo->time_to_die - (get_current_time() - philo->last_meal)
		- philo->time_to_eat / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	ft_usleep(time_to_think, philo);
	if (is_he_dead(philo) == 1)
		return (1);
	count_time(philo);
	return (0);
}

void	*start(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (begin(philo->prog))
	{
		if (is_he_dead(philo) == 1)
			return (NULL);
		philo_eating(philo);
		if (is_he_dead(philo) == 1)
			return (NULL);
		philo_sleeping(philo);
		if (is_he_dead(philo) == 1)
			return (NULL);
		if (philo_thinking(philo) == 1)
			return (NULL);
		pthread_mutex_lock(philo->total_lock);
		if (philo->num_times_to_eat == philo->meals_eaten)
			philo->prog->total++;
		pthread_mutex_unlock(philo->total_lock);
		pthread_mutex_lock(philo->total_lock);
		if (philo->prog->total == philo->num_of_philos)
			set_starting(philo->prog, 0);
		pthread_mutex_unlock(philo->total_lock);
	}
	return (0);
}
