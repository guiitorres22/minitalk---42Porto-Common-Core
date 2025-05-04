/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:54:42 by gtinani-          #+#    #+#             */
/*   Updated: 2025/05/03 17:20:36 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\e[36m---> Signal received from server. <---\n\e[0m");
	else if (signal == SIGUSR2)
	{
		ft_printf("\e[32m---> Message fully received by server."
			"Exiting. <---\n\e[0m");
		exit(0);
	}
}

static void	send_message_to_server(int server_pid, char *message)
{
	int	index;

	index = 0;
	ft_printf("\e[32mMessage length: %d\n\e[0m", ft_strlen(message));
	send_integer_to_server(server_pid, ft_strlen(message));
	ft_printf("\e[34mSending message...\n\e[0m");
	while (message[index] != '\0')
		send_char_to_server(server_pid, message[index++]);
	ft_printf("\e[34mSending null terminator for the message.\n\e[0m");
	send_char_to_server(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	signal_action;

	if (argc != 3)
	{
		ft_printf("\e[31m## Error - Invalid arguments ##\n\e[0m");
		ft_printf("\e[33mUsage: ./client <server PID> <message>\n\e[0m");
		return (1);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_printf("\e[31m## Error - Invalid server PID ##\n\e[0m");
		return (1);
	}
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_RESTART;
	signal_action.sa_handler = client_handle_signal;
	setup_signal_handling(&signal_action);
	ft_printf("\e[35mClient running with PID: %d\n\e[0m", getpid());
	send_message_to_server(ft_atoi(argv[1]), argv[2]);
	return (0);
}
