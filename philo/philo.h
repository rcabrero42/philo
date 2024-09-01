/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-25 14:03:24 by rcabrero          #+#    #+#             */
/*   Updated: 2024-08-25 14:03:24 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 201

//TODO: Esta estructura es pprovisional...
typedef struct s_philo
{
	int is_eaten;
	int	is_sleep;
	int	is_dead;
}			t_philo;

//Informacion relevante sobre la ejecucion del programa
typedef struct s_philo_info
{
    int            num_philos;       // Número de filósofos, el numero de filosofos siempre es el mismo que el numero de tenedores!!
    t_philo			*philos;        //Esta info no se si quiero que este aqui......
	pthread_mutex_t *forks;           // Array de mutexes para los tenedores
    int             time_to_die;      // Tiempo en morir (en milisegundos)
    int             time_to_eat;      // Tiempo en comer (en milisegundos)
	int				time_to_sleep;	  // Tiempo en dormir (en milisegundos)
    int             max_meals;        // Veces máximas que cada filósofo debe comer
    int             is_dead;		  // Controla si un filosoof ha muerto para parar la ejecucion
}               t_philo_info;

//UTILS Y CHECK_ERRORS
int check_args(int argc,char **argv);
int	check_arg_content(char *arg);
int	ft_atoi(char *str);


//INIT_STRUCT
int init_info(char **argv);

#endif
