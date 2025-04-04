/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-25 14:06:45 by rcabrero          #+#    #+#             */
/*   Updated: 2024-08-25 14:06:45 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Este atoi solo funciona para numeros positivos....
 */
int	ft_atoi_plus(char *str)
{
	unsigned long long	nb;
	int					i;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return(-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		if (nb > 2147483647)
			return (-1);
		i++;
	}
	if (i == 0 || (str[0] == '+' && i == 1))
		return (-1);
	return (nb);
}

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (-1);
}

size_t get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        write(2, "gettimeofday() error\n", 22);
    // printf("TIEMPO: %zu \n", time.tv_sec * 1000 + time.tv_usec / 1000);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}