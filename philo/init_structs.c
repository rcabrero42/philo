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
 * Hacemmos el atoi de todos y convertimos lo que necesitemos.
 * 1.Guarda el numero de filosofos
 * 2.Guarda el tiempo que tarda en morir
 * 3.Guarda el tiempo que tarda en comer
 * 4.Guarda el tiempo que tarda en dormir
 * 5.Guarda el numero de comidas que debe hacer cada filosofo (No es obligatorio)
 * 6.Guarda el tiempo en el que se inicia el programa
 */
int init_info(char **argv, int has_max_eat, t_philo_info *p_info)
{
	p_info->num_philos = ft_atoi_plus(argv[1]);
	p_info->time_to_die = ft_atoi_plus(argv[2]);
	p_info->time_to_eat = ft_atoi_plus(argv[3]);
	p_info->time_to_sleep = ft_atoi_plus(argv[4]);
	if(has_max_eat)
	{
        p_info->has_max_eat = 1;
		p_info->max_meals = ft_atoi_plus(argv[5]);
		//TODO: REVISAR SI ESTA CONDICION ES NECESARIA
        if(p_info->max_meals == -1)
			return (-1);
	}else
    {
        p_info->max_meals = -1;
    }
	if(p_info->num_philos == -1 || p_info->time_to_die == -1 
		|| p_info->time_to_eat == -1 || p_info->time_to_sleep == -1)
		return (-1);
	p_info->init_time = get_current_time();
	return (0);
}

/**
 * Inicia los tenedores...
 * Mientras que i sea menor que el numero de filosofos, inicializamos los mutexes de los tenedores
 */
void	init_forks(t_philo_info *philo_info)
{
    int	i;

    // Asegúrate de que la memoria para los mutexes esté asignada
    philo_info->forks = malloc(sizeof(pthread_mutex_t) * philo_info->num_philos);
    if (philo_info->forks == NULL)
    {
        perror("Failed to allocate memory for forks");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i < philo_info->num_philos)
    {
        printf("Tenedor: %d\n", i);
        if (pthread_mutex_init(&philo_info->forks[i], NULL) != 0)
        {
            perror("Failed to initialize mutex");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

/*
 TODO: REVISAR ESTE METODO, NO ENTIENDO POR QUE TENGO QUE UTILIZAR LA VARIABLE PHILO, 
 Quizá para quitarle complejidad el codigo y hacerlo mas legible????
*/
void	init_philos(t_philo_info *philo_info)
{
    int		i;

    // Asegúrate de que la memoria para los filósofos esté asignada
    philo_info->philos = malloc(sizeof(t_philo) * philo_info->num_philos);
    if (philo_info->philos == NULL)
    {
        perror("Failed to allocate memory for philosophers");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < philo_info->num_philos)
    {
        printf("Filósofo %d:\n", i);
        philo_info->philos[i].id = i + 1;
        printf("  check_dead: %d\n", philo_info->philos[i].check_dead);
        philo_info->philos[i].check_dead = 0;
        printf("  is_sleep: %d\n", philo_info->philos[i].is_sleep);
        philo_info->philos[i].meals_eaten = 0;
        printf("  is_eaten: %d\n", philo_info->philos[i].is_eaten);
        philo_info->philos[i].is_sleep = 0;
        printf("  is_eaten: %d\n", philo_info->philos[i].is_eaten);
        philo_info->philos[i].is_eaten = 0;
        printf("  last_eat_time: %zu\n", philo_info->philos[i].last_eat_time);
        philo_info->philos[i].l_fork = &philo_info->forks[i]; // Acceso correcto a los tenedores
        printf("  last_sleep_time: %zu\n", philo_info->philos[i].last_sleep_time);
        philo_info->philos[i].last_eat_time = philo_info->init_time;
        printf("  l_fork: %p\n", (void *)philo_info->philos[i].l_fork);
        philo_info->philos[i].last_sleep_time = philo_info->init_time;

        if (i == 1)
            philo_info->philos[i].r_fork = &philo_info->forks[philo_info->num_philos - 1];
        else
            philo_info->philos[i].r_fork = &philo_info->forks[i - 1];
        printf("  r_fork: %p\n", (void *)philo_info->philos[i].r_fork);
        
        // Inicializa los mutexes de muerte de los filosofos
        if (pthread_mutex_init(&philo_info->philos[i].dead, NULL) != 0)
        {
            perror("Failed to initialize mutex");
            exit(EXIT_FAILURE);
        }
        printf("  dead: %p\n", (void *)&philo_info->philos[i].dead);

        printf("  hacemos el write: \n");
        // Inicializa los mutexes de escritura de los filosofos
        philo_info->philos[i].write = malloc(sizeof(pthread_mutex_t));
        if (philo_info->philos[i].write == NULL)
        {
            perror("Failed to allocate memory for write mutex");
            exit(EXIT_FAILURE);
        }
        printf("  write: %p\n", (void *)philo_info->philos[i].write);
        if (pthread_mutex_init(philo_info->philos[i].write, NULL) != 0)
        {
            perror("Failed to initialize mutex");
            exit(EXIT_FAILURE);
        }
        printf("  write: %p\n", (void *)philo_info->philos[i].write);
        // if (pthread_mutex_init(philo_info->philos[i].write, NULL) != 0)
        // {
        //     perror("Failed to initialize mutex");
        //     exit(EXIT_FAILURE);
        // }

        philo_info->philos[i].eat = malloc(sizeof(pthread_mutex_t));
        if (philo_info->philos[i].eat == NULL)
        {
            perror("Failed to allocate memory for eat mutex");
            exit(EXIT_FAILURE);
        }
        if (pthread_mutex_init(philo_info->philos[i].eat, NULL) != 0)
        {
            perror("Failed to initialize mutex");
            exit(EXIT_FAILURE);
        }
        printf("  eat: %p\n", (void *)philo_info->philos[i].eat);
        i++;
    }
}