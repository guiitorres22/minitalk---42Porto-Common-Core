/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:45:22 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/30 19:46:47 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	ft_signal_handler(int signal)
{
	static unsigned char    current_bit;
	static int				bit_index;

	current_bit |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", current_bit);
		bit_index = 0;
		current_bit = 0;
	}
	else
		current_bit <<= 1;
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("                    \033[33mSERVER\033[0m\n");
    ft_printf("\033[34mPID: %d\033[0m\n", pid);
    ft_printf("\033[33mWaiting for client...\033[0m\n");

    signal(SIGUSR2, ft_signal_handler);
    signal(SIGUSR1, ft_signal_handler);


    while (1)
    {
        pause();
    }
    return (0);
}
