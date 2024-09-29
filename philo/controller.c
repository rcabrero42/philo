/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 14:32:21 by rcabrero          #+#    #+#             */
/*   Updated: 2024-09-28 14:32:21 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_program(t_philo_info * philo_info)
{
	int	i;

	if(philo_info != NULL)
	{
		i = 0;
		while (philo_info->num_philos > i)
			philo_controller(philo_info, &philo_info->philos[i]);
	}else{
		printf("ERROR...");
		return ;
	}
}

//Aqui lanzamos tooodos los fiilosofoss a realiiar  ss acciones
void philo_controller(t_philo_info * philo_info,t_philo * philo)
{
	if(philo->id % 2 == 0)
		usleep(1);
	while (!is_dead(philo))
	{
		eat(philo_info);
		sleep(philo_info);
		think(philo_info);
	}
	printf("El filosofo %d ha muerto x.x \n",philo);
}

//COmprueba si el filosofo ha muerto
int is_dead(t_philo * philo)
{
	int	is_dead;
	pthread_mutex_lock(philo->dead);
	is_dead = philo->is_dead;
	pthread_mutex_unlock(philo->dead);
	return (is_dead);
}
