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
	printf("Atoi plus para: %s\n" , str);
	unsigned long long	nb;
	int					sign;
	int					i;

	nb = 0;
	sign = 1;
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
		if (str[i] < '0' || str[i] > '9')  // Comprobar si el carácter no es un dígito
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0 || (str[0] == '+' && i == 1))
		return (-1);
	return (sign * nb);
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