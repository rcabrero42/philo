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

//t_actions es una estructura que contiene los mutexes de las acciones que se pueden realizar
typedef struct s_actions
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}               t_actions;

typedef struct s_philo_info t_philo_info;

typedef struct s_philo
{
    int             id;
    int             is_eaten;
    int             is_sleep;
    int             check_dead;
    int             meals_eaten;
    size_t          last_eat_time;
    size_t          last_sleep_time;
    pthread_mutex_t *write;
    pthread_mutex_t *eat;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t dead;
    t_philo_info    *philo_info; // Añade este campo para pasar philo_info a cada filósofo
}               t_philo;

typedef struct s_philo_info
{
    int             num_philos;
    t_philo         *philos;
    pthread_mutex_t *forks;
    int          time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             has_max_eat; // Add this line
    int             max_meals;
    int             check_dead;
    size_t          init_time;
}               t_philo_info;

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

//CONTROLLER
void    init_program(t_philo_info * philo_info);

//ACTIONS
int  eat(t_philo_info	*p_info, t_philo * philo);
void ft_sleep(t_philo_info * philo_info, t_philo * philo);
void think(t_philo * philo);
int check_dead(t_philo *philo);

void write_info(t_philo * philo,char *message);
void philo_controller(t_philo_info * philo_info,t_philo * philo);

#endif
