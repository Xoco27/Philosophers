/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:40:47 by cfleuret          #+#    #+#             */
/*   Updated: 2025/06/23 16:49:30 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(t_philo *philo)
{
	count_time(philo);
	if (philo->eating == 0 && philo->prog->dead_flag == 0)
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu philo %d took his left fork\n",
			philo->prog->time, philo->id);
		printf("%zu philo %d took his right fork\n",
			philo->prog->time, philo->id);
		printf("%zu philo %d is eating\n", philo->prog->time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->eating = 1;
		return ;
	}
	else if (philo->eating == 1 && philo->prog->dead_flag == 0)
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu philo %d dropped his left fork\n",
			philo->prog->time, philo->id);
		printf("%zu philo %d dropped his right fork\n",
			philo->prog->time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
		philo->eating = 0;
		return ;
	}
}

void	free_and_destroy(t_program *prog, pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->total_lock);
	pthread_mutex_destroy(&prog->starting_lock);
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (prog->philos)
		free(prog->philos);
	free(prog);
	free(forks);
}

size_t	get_current_time(void)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t		start;
	int			i;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		i = 0;
		while (i < philo->num_of_philos)
		{
			check_usleep(philo, i);
			if (begin(philo->prog) == 0)
				return (1);
			if (is_he_dead(philo) == 1)
				return (1);
			i++;
		}
		usleep(500);
	}
	count_time(philo);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	f;

	i = 0;
	f = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (f > INT_MAX)
		return (0);
	if (str[i] != '\0')
		return (0);
	return ((int)f);
}
