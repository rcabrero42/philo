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

int main(int argc, char **argv)
{
	t_philo_info	p_info;
	int				has_max_eaten;

	if(argc == 5)
		has_max_eaten = 0;
	else if(argc == 6)
		has_max_eaten = 1;
	else
	{
		write(2, "Wrong argument\n", 14);
		return (1);
	}
	if (init_info(argv, has_max_eaten, &p_info) != 0)
	{
		write(2, "Wrong argument\n", 14);
		return (1);
	}
	init_forks(&p_info);
	init_philos(&p_info);

    return (0);
}

void init_program(t_philo_info * p_info)
{

}


