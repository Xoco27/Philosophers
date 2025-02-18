/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:53:52 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/18 16:57:50 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initiate_rest(char **argv, t_program *prog, \
	pthread_mutex_t *forks, int i)
{
	prog->philos[i].start_time = 0;
	if (argv[5] != NULL)
		prog->philos[i].num_times_to_eat = ft_atoi(argv[5]);
	prog->philos[i].dead = 0;
	prog->philos[i].l_fork = &forks[i];
	prog->philos[i].r_fork = &forks[(i + 1) % prog->philos[i].num_of_philos];
	prog->philos[i].write_lock = &prog->write_lock;
	prog->philos[i].dead_lock = &prog->dead_lock;
	prog->philos[i].meal_lock = &prog->meal_lock;
}

static void	initiate(char **argv, t_program *prog, \
	pthread_mutex_t *forks, int n)
{
	int				i;

	i = 0;
	prog->dead_flag = 0;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
	prog->philos = malloc(sizeof(t_philo) * n);
	while (++i < n)
		pthread_mutex_init(&forks[i], NULL);
	i = 0;
	while (i < n)
	{
		prog->philos[i].id = i;
		prog->philos[i].eating = 0;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].last_meal = 0;
		prog->philos[i].time_to_die = ft_atoi(argv[2]);
		prog->philos[i].time_to_eat = ft_atoi(argv[3]);
		prog->philos[i].time_to_sleep = ft_atoi(argv[4]);
		prog->philos[i].num_of_philos = n;
		initiate_rest(argv, prog, forks, i);
		i++;
	}
}

static void	threading(t_program *prog)
{
	int	n;

	n = 0;
	while (n < prog->philos[0].num_of_philos)
	{
		pthread_create(&prog->philos[n].thread, NULL, &start, \
		(void *)&prog->philos[n]);
		n++;
	}
	n = 0;
	while (n < prog->philos[0].num_of_philos)
	{
		pthread_join(prog->philos[n].thread, NULL);
		n++;
	}
}

int	main(int argc, char **argv)
{
	t_program		*prog;
	pthread_mutex_t	*forks;
	int				n;

	if (argc < 5 || argc > 6)
		return (printf("Wrong arguments\n"), 1);
	n = ft_atoi(argv[1]);
	if (n <= 0)
		return (1);
	prog = malloc(sizeof(t_program));
	if (!prog)
		return (1);
	forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!forks)
	{
		free(prog);
		return (1);
	}
	initiate(argv, prog, forks, n);
	n = 0;
	threading(prog);
	// while (n < prog->philos[0].num_of_philos)
	// {
	// 	printf("%d %d %p %p\n", n, prog->philos[n].num_times_to_eat, prog->philos[n].l_fork, prog->philos[n].r_fork);
	// 	n++;
	// }
}
