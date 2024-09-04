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
		if(p_info->max_meals != -1)
			return (-1);
	}
	if(p_info->num_philos == -1 || p_info->time_to_die == -1 
		|| p_info->time_to_eat == -1	|| p_info->time_to_sleep == -1)
		return (-1);
	return (0); 
}
