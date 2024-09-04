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
	t_philo_info p_info;
    //Si no es esto, falla........
    //lo sacamos de aqui,
	printf("argc: %d\n",argc);
	if (argc == 5 && init_info(argv,0, &p_info))
		printf("5 Y OK\n");
	else if (argc == 6 && init_info(argv,1, &p_info))
		printf("6 Y OK\n");
    else
	{
		write(2, "Wrong argument\n", 14);
		return (1);
	}
	printf("P_info: %d",p_info.num_philos);
    return (0);
}