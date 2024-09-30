/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:45:22 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/30 15:46:18 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void ft_signal_handler(int signal)
{
    static int bit_storage;
    static unsigned char  bit;

    bit_storage = 0;
    bit = 0;
    if (signal == SIGUSR1)
        bit_storage |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", bit_storage);
        bit = 0;
        bit_storage = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("                    \033[33mSERVER\033[0m\n");
    ft_printf("\033[34mPID: %d\033[0m\n", pid);
    ft_printf("\033[33mWaiting for client...\033[0m\n");

    signal(SIGUSR1, ft_signal_handler);
    signal(SIGUSR2, ft_signal_handler);


    while (1)
    {
        pause();
    }
    return (0);
}
