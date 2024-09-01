/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-01 18:20:40 by rcabrero          #+#    #+#             */
/*   Updated: 2024-09-01 18:20:40 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char *prueba_OK = "1234";
	char *prueba_DECIMAL = "12345.1";
	char *prueba_NEGATIVO = "-123";
	char *prueba_LETRAS = "23Hola";
	int	atoi_result;
	// printf("Prueba ok: \n");
	// atoi_result = ft_atoi(prueba_OK);
	// printf("Prueba ok: %d\n", atoi_result);
	// atoi_result = ft_atoi(prueba_DECIMAL);
	// printf("Prueba decimal: %d\n", atoi_result);	
	// atoi_result = ft_atoi(prueba_NEGATIVO);
	// printf("Prueba negativo: %d\n", atoi_result);
	atoi_result = ft_atoi(prueba_LETRAS);
	printf("Prueba letras: %d\n", atoi_result);
	return (0);
}