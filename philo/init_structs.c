/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-01 18:01:56 by rcabrero          #+#    #+#             */
/*   Updated: 2024-09-01 18:01:56 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Inicializa la estructura de informacion
 *	Hacemmos el atoi de todos y convertimos lo que necesitemos.
 */
int init_info(char **argv, int has_max_eat, t_philo_info *p_info)
{
	p_info->num_philos = ft_atoi_plus(argv[1]);
	p_info->time_to_die = ft_atoi_plus(argv[2]);
	p_info->time_to_eat = ft_atoi_plus(argv[3]);
	p_info->time_to_sleep = ft_atoi_plus(argv[4]);
	if(has_max_eat)
	{
		p_info->max_meals = ft_atoi_plus(argv[5]);
		if(p_info->max_meals == -1)
			return (-1);
	}
	if(p_info->num_philos == -1 || p_info->time_to_die == -1 
		|| p_info->time_to_eat == -1 || p_info->time_to_sleep == -1)
		return (-1);
	p_info->init_time = get_current_time();
	return (0);
}

/**
 * Inicia los tenedores...
 */
void	init_forks(t_philo_info * philo_info)
{
	int	i;

	i = 0;
	while (i < philo_info->num_philos)
	{
		pthread_mutex_init(&philo_info->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_philo_info * philo_info)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < philo_info->num_philos)
	{
		philo = philo_info->philos[i];
		philo.id = i; //TODO: DEBERIA SER I + 1? O PUEDE SER EL ID 0....
		philo.is_dead = 0;
		philo.is_sleep = 0;
		philo.is_eaten = 0;
		philo.l_fork = &philo_info->forks[i - 1]; //Por que aqui tengo el & y en philo.eat_without_eating NO
		philo.last_eat_time = philo_info->init_time; //Contara de este momento hasta el final
		philo.last_sleep_time = philo_info->init_time; //Ultima vez en dormir, se inicializa a la fecha actual DIria que no hace ni falta inicializarla...
		if(i == 0)
			philo.r_fork = &philo_info->forks[philo_info->num_philos - 1];
		else
			philo.r_fork = &philo_info->forks[i - 1];
		i ++;
	}
}
