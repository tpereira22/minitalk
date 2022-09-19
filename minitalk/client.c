/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:13:31 by timartin          #+#    #+#             */
/*   Updated: 2022/09/19 17:13:36 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr_fd("Invalid Number of Arguments!\n", 1);
        ft_putstr_fd("./client [SERVER PID] [STRING]\n", 1);
        return (0);
    }
    ft_putstr_fd("Sent -> ", 1);
    ft_putstr_fd(argv[2], 1);
    ft_putchar_fd('\n', 1);
}