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

void    send_signal(int pid, int *binary)
{
    int i;

    i = 0;
    while (i <= 7)
    {
        if (binary[i] == 0)
        {
            kill(pid, SIGUSR1);
            usleep(100);
        }
        else if (binary[i] == 1)
        {
            kill(pid, SIGUSR2);
            usleep(100);
        }
        i++;
    }
    free(binary);
}

int *convert_bit(int c)
{
    int *binary;
    int i;

    binary = malloc(sizeof(int) * 8);
    i = 7;
    while (c != 0)
    {
        binary[i] = c % 2;
        c /= 2;
        i--;
    }
    while (i >= 0)
        binary[i--] = 0;
    return (binary);
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    if (argc != 3)
    {
        ft_putstr_fd("Invalid Number of Arguments!\n", 1);
        ft_putstr_fd("./client [SERVER PID] [STRING]\n", 1);
        return (0);
    }
    pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i] != '\0')
    {
        send_signal(pid, convert_bit(argv[2][i]));
        i++;
    }
    send_signal(pid, convert_bit(10));
}