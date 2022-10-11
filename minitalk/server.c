/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:13:46 by timartin          #+#    #+#             */
/*   Updated: 2022/09/19 17:13:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int glob_i = 0;

int power(int nb, int p)
{
    int result;

    result = 1;
    while (p != 0)
    {
        result *= nb;
        p--;
    }
    return (result);
}

int convert_dec(char *str)
{
    int i;
    int dec;
    int res;
    int bit;

    bit = ft_atoi(str);
    dec = 0;
    res = 0;
    i = 0;
    while (bit != 0)
    {
        res = bit % 10;
        bit /= 10;
        dec += res * power(2, i);
        i++;
    }
    return (dec);
}

void    handle_str(int sign)
{
    char    str[9];
    int final_str;

    if (sign == 10)
        str[glob_i++] = '0';
    else if (sign == 12)
        str[glob_i++] = '1';
    if (glob_i == 8)
    {
        str[glob_i] = 0;
        final_str = convert_dec(str);
        ft_putchar_fd(final_str, 1);
        glob_i = 0;
    }
}

int main(void)
{
    ft_putstr_fd("Server PID -> ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd(10, 1);
    signal(SIGUSR1, handle_str);
    signal(SIGUSR2, handle_str);
    while (1);
}