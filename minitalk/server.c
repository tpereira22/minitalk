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
    int i;
    int final_str;

    ft_putstr_fd("adeus", 1);
    i = 0;
    if (sign == 10)
        str[i++] = '0';
    else if (sign == 12)
        str[i++] = '1';
    ft_putstr_fd(str, 1);
    if (i == 8)
    {
        str[i] = 48;
        final_str = convert_dec(str);
        ft_putchar_fd(final_str, 1);
    }
}

int main(void)
{
    ft_putstr_fd("Server PID -> ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);
    signal(SIGUSR1, handle_str);
    signal(SIGUSR2, handle_str);
    return (0);
}