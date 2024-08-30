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
    //Si no es esto, falla........
    if (argc != 5 && argc != 6 && check_arg_content(argv[0]))
    {
        write(2, "Wrong argument\n", 14);
        return (1);
    }

    return (0);
}