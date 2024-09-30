/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:44:39 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/30 15:51:09 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void ft_sendbit(int pid, unsigned char character)
{
    int bit;
    // unsigned char    temp;

    // temp = character,

    bit = 8;
    while (bit-- > 0)
    {
        // temp = character >> bit;
        if ((character >> bit) & 1)  
        {
            kill(pid, SIGUSR1); 
        }
        else 
        {
            kill(pid, SIGUSR2); 
        }
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    int i;
    char *str;

    i = 0;
    if (argc == 3)
    {
        pid = (pid_t)ft_atoi(argv[1]);
        str  = argv[2];
        while (str[i] != '\0')
        {
            ft_sendbit(pid, str[i]);
            i++;
        }
        ft_sendbit(pid, '\n'); 
    }
    else
    {
        ft_printf("\033[91mERROR: The received parameters are not valid\033[0m\n");
    }
    return (0);
}