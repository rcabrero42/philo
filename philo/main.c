/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-25 13:56:55 by rcabrero          #+#    #+#             */
/*   Updated: 2024-08-25 13:56:55 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void print_philos_info(t_philo_info *philo_info);

int main(int argc, char **argv)
{
	t_philo_info p_info;
	int has_max_eaten;

	if (argc == 5)
		has_max_eaten = 0;
	else if (argc == 6)
		has_max_eaten = 1;
	else
	{
		printf("Wrong argument\n");
		return (1);
	}
 	if (init_info(argv, has_max_eaten, &p_info) != 0)
	{
		printf("Wrong argument\n");
		return (1);
	}
	init_forks(&p_info);
	init_philos(&p_info);

	print_philos_info(&p_info);

	init_program(&p_info);
	return (0);
}

void print_philos_info(t_philo_info *philo_info)
{
    int i;

    printf("Información de los filósofos:\n");
    for (i = 0; i < philo_info->num_philos; i++)
    {
        t_philo *philo = &philo_info->philos[i];
        printf("Filósofo %d %d:\n",i, philo->id);
        printf("  is_dead: %d\n", philo->is_dead);
        printf("  is_sleep: %d\n", philo->is_sleep);
        printf("  is_eaten: %d\n", philo->is_eaten);
        printf("  last_eat_time: %zu\n", philo->last_eat_time);
        printf("  last_sleep_time: %zu\n", philo->last_sleep_time);
        printf("  l_fork: %p\n", (void *)philo->l_fork);
        printf("  r_fork: %p\n", (void *)philo->r_fork);
        printf("  write: %p\n", (void *)philo->write);
        printf("  eat: %p\n", (void *)philo->eat);
    }
}