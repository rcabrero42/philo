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
    int             id;
	int             is_eaten;
	int             is_sleep;
	int             is_dead;
    size_t          last_eat_time;
    size_t          last_sleep_time;
    pthread_mutex_t *dead;
    pthread_mutex_t *write;
    pthread_mutex_t *eat;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    t_actions       s_actions;        // Hilos de las acciones que va se van a poder realiizar...
}			t_philo;

//Informacion relevante sobre la ejecucion del programa
typedef struct s_philo_info
{
    int             num_philos;       // Número de filósofos, el numero de filosofos siempre es el mismo que el numero de tenedores!!
    t_philo			*philos;          //Esta info no se si quiero que este aqui......
	pthread_mutex_t *forks;           // Array de mutexes para los tenedores
    int             time_to_die;      // Tiempo en morir (en milisegundos)
    int             time_to_eat;      // Tiempo en comer (en milisegundos)
	int				time_to_sleep;	  // Tiempo en dormir (en milisegundos)
    int             max_meals;        // Veces máximas que cada filósofo debe comer
    int             is_dead;		  // Controla si un filosoof ha muerto para parar la ejecucion
    size_t          init_time;        // Tiempo en el que iniciamos todos los filosofos
}               t_philo_info;

typedef struct s_actions
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}               t_actions;

//UTILS Y CHECK_ERRORS
int     check_args(int argc,char **argv);
int     check_arg_content(char *arg);
int     ft_atoi_plus(char *str);
size_t	get_current_time(void);

//INIT_STRUCT
int     init_info(char **argv, int has_max_eat, t_philo_info *p_info);
//TODO: ESTOS DOS METODOS PODRIAMOS CONVERTILOS A INT PARA ASI PODER CONTROLAR LOSS ERRORES DE MEJOR FORMA?
void	init_philos(t_philo_info * philo_info);
void	init_forks(t_philo_info * philo_info);

#endif
