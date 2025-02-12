/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 12:39:34 by rcabrero          #+#    #+#             */
/*   Updated: 2024-09-28 12:39:34 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_dead(t_philo *philo)
{
    int is_dead;
    pthread_mutex_lock(&philo->dead);
    is_dead = philo->is_dead;
    pthread_mutex_unlock(&philo->dead);
    return is_dead;
}

//Metodo que controla todo lo que hacen los filosofos
void write_info(t_philo *philo, char *message)
{
    pthread_mutex_lock(philo->write);
    if (check_dead(philo) == 0)
        printf("%zu %d %s\n", get_current_time(), philo->id, message);
    pthread_mutex_unlock(philo->write);
}

//Para el metodo de comer vamos a buscar los tenedores
//Pasamos la informacion de todos los filosofos y la de un filosofo en concreto
void eat(t_philo_info	*p_info, t_philo * philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_info(philo, "has taken a fork");
	if(p_info->num_philos != 1)
	{
		pthread_mutex_lock(philo->l_fork);
		write_info(philo, "has taken a fork");
		pthread_mutex_lock(philo->eat);
		// TODO: IMPORTANTE!!!!!
		// El caso de que el filosofo tenga un maximo de veces qeu comer,
		// deberiamos controlarlo, antes de que coma
		philo->is_eaten = 1;
		write_info(philo, "is eaten");
		usleep(p_info->time_to_eat);
		philo->is_eaten = 0;
		pthread_mutex_unlock(philo->eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		usleep(p_info->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
	}
}

void ft_sleep(t_philo_info * philo_info, t_philo * philo)
{
	write_info(philo, "is sleeping");
	usleep(philo_info->time_to_sleep);
}

void think(t_philo * philo)
{
	write_info(philo, "is thinking");
}