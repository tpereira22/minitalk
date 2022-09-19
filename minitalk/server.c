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

int main(void)
{
    ft_putstr_fd("Server PID -> ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);

    return (0);
}