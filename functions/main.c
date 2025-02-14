/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:53:52 by cfleuret          #+#    #+#             */
/*   Updated: 2025/02/14 15:20:03 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initiate_rest(char **argv, t_program *prog, int i)
{
	prog->philos[i].start_time = 0;
	if (argv[6] != '\0')
		prog->philos[i].num_times_to_eat = argv[6];
	prog->philos[i].dead = 0;
	prog->philos[i].id = i;
	if (prog->philo[i + 1])
}

static void	initiate(char **argv, t_program *prog)
{
	int				np;
	int				i;

	i = 0;
	prog->dead_flag = 0;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
	np = ft_atoi(argv[1]);
	prog->philos[np];
	while (i < np)
	{
		prog->philos[i].id = i;
		prog->philos[i].eating = 0;
		prog->philos[i].meals_eaten = 0;
		if (argv[6] != '\0')
			prog->philos[i].last_meal = argv[6];
		prog->philos[i].time_to_die = ft_atoi(argv[2]);
		prog->philos[i].time_to_eat = ft_atoi(argv[3]);
		prog->philos[i].time_to_sleep = ft_atoi(argv[4]);
		prog->philos[i].num_of_philos = np;
		initiate_rest(argv, prog, i);
	}
}

int	main(int argc, char **argv)
{
	t_program	*prog;

	if (argc < 5)
		return (1);
	initiate(argv, prog);
}