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

void *philo_thread(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_philo_info *philo_info = philo->philo_info;

    if (philo->id % 2 == 0)
        usleep(1);
    //Si no esta muerto y no ha comido las veces suficientes, sigue
    while (!is_dead(philo) && philo_info->has_max_eat && philo->meals_eaten <= philo_info->max_meals)
    {
        eat(philo_info, philo);
        philo->meals_eaten ++;
        ft_sleep(philo_info, philo);
        think(philo);
    }
    if(is_dead(philo))
    {
        printf("El filósofo %d ha muerto x.x \n", philo->id);
    }
    else if(philo->meals_eaten >= philo_info->max_meals)
    {
        printf("El filosofo %d ya ha comido suficiente", philo->id);
    }
    return NULL;
}

void init_program(t_philo_info *philo_info)
{
    int i;
    pthread_t *threads;

    if (philo_info != NULL)
    {
        threads = malloc(sizeof(pthread_t) * philo_info->num_philos);
        if (threads == NULL)
        {
            perror("Failed to allocate memory for threads");
            exit(EXIT_FAILURE);
        }

        i = 0;
        while (i < philo_info->num_philos)
        {
            philo_info->philos[i].philo_info = philo_info; // Añade esta línea para pasar philo_info a cada filósofo
            if (pthread_create(&threads[i], NULL, philo_thread, &philo_info->philos[i]) != 0)
            {
                perror("Failed to create thread");
                exit(EXIT_FAILURE);
            }
            i++;
        }

        i = 0;
        while (i < philo_info->num_philos)
        {
            pthread_join(threads[i], NULL);
            i++;
        }

        free(threads);
    }
}

//Aqui lanzamos tooodos los fiilosofoss a realiiar  ss acciones
/*
 * 1. Si el id del filosofo es par, dormimos 1 microsegundo
 * 2. Mientras que el filosofo no este muerto
 * 3. El filosofo come
 * 4. El filosofo duerme
 * 5. El filosofo piensa
 */
void philo_controller(t_philo_info * philo_info,t_philo * philo)
{
	if(philo->id % 2 == 0)
		usleep(1);
	while (!is_dead(philo))
	{
		eat(philo_info,philo);
		ft_sleep(philo_info,philo);
		think(philo);
	}
    printf("El filósofo %d ha muerto x.x \n", philo->id);
}

void	cleanup_philos(t_philo_info *philo_info)
{
    int	i;

    i = 0;
    while (i < philo_info->num_philos)
    {
        pthread_mutex_destroy(&philo_info->philos[i].dead);
        pthread_mutex_destroy(philo_info->philos[i].write);
        free(philo_info->philos[i].write);
        pthread_mutex_destroy(philo_info->philos[i].eat);
        free(philo_info->philos[i].eat);
        i++;
    }
    free(philo_info->philos);
}

//COmprueba si el filosofo ha muerto
int is_dead(t_philo *philo)
{
    int	is_dead;
    pthread_mutex_lock(&philo->dead); // Usa el operador & para pasar la dirección del mutex
    is_dead = philo->is_dead;
    pthread_mutex_unlock(&philo->dead); // Usa el operador & para pasar la dirección del mutex
    return (is_dead);
}
