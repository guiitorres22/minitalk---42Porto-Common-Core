/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:52:25 by gtinani-          #+#    #+#             */
/*   Updated: 2025/05/03 16:59:04 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define WAIT_TIME  300 // usleep()

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	setup_signal_handling(struct sigaction *sa);
void	send_integer_to_server(pid_t pid, int number);
void	send_char_to_server(pid_t pid, char character);
void	send_signal_to_client(pid_t pid, char bit, char pause_flag);

typedef struct s_protocol_state
{
	int		bits_received;
	int		current_char;
	int		message_received;
	char	*received_message;
}	t_protocol_state;

#endif
