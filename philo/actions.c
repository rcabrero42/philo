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

//Metodo que controla todo lo que hacen los filosofos
void write_info(t_philo *philo, char *message)
{
    pthread_mutex_lock(philo->write);
    if (check_dead(philo) == 0)
        printf("%zu philosopher %d %s\n", get_current_time(), philo->id, message);
    pthread_mutex_unlock(philo->write);
}

//Para el metodo de comer vamos a buscar los tenedores
//Pasamos la informacion de todos los filosofos y la de un filosofo en concreto
int eat(t_philo_info	*p_info, t_philo * philo)
{
	printf("FILOSOFO %d INTENTA COMER\n",philo->id);
	pthread_mutex_lock(philo->r_fork);
	write_info(philo, "has taken a fork");
	// printf("P_INFO NUM_PHILOS => %d\n",p_info->num_philos);
	// printf("p_info->has_max_eaten => %d\n ",p_info->has_max_eat);
	// printf("philo->meals_eaten => %d\n ",philo->meals_eaten);
	// printf("p_info->max_meals => %d\n ",p_info->max_meals);
	if(p_info->num_philos > 1 && ((p_info->has_max_eat && philo->meals_eaten <= p_info->max_meals) || !p_info->has_max_eat))
	{
		pthread_mutex_lock(philo->l_fork);
		write_info(philo, "has taken a SECOND fork");
		pthread_mutex_lock(philo->eat);

		//Contamos que ha comido... 
		philo->meals_eaten++;
		// TODO: IMPORTANTE!!!!!
		// El caso de que el filosofo tenga un maximo de veces qeu comer,
		// deberiamos controlarlo, antes de que coma
		philo->is_eaten = 1;
		write_info(philo, "is eaten");
		usleep(p_info->time_to_eat * 1000);
		philo->is_eaten = 0;
		pthread_mutex_unlock(philo->eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("EL FILOSOFO HA TERMINADO DE COMER %d \n", philo->id);
	}
	else if(p_info->has_max_eat && philo->meals_eaten >= p_info->max_meals)
	{
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		printf("No ha podido comer, no tiene tenedores suficientes\n ");
		usleep(p_info->time_to_die * 1000);
		check_dead(philo);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	return (0);
}

void ft_sleep(t_philo_info * philo_info, t_philo * philo)
{
	write_info(philo, "is sleeping");
	usleep(philo_info->time_to_sleep * 1000);
}

void think(t_philo * philo)
{
	write_info(philo, "is thinking");
}