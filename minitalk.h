#ifndef MINITALK_H
# define MINITALK_H

# define WAIT_TIME  300 // usleep()

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void    setup_signal_handling(struct sigaction *sa);
void    send_integer_to_server(pid_t pid, int number);
void    send_char_to_server(pid_t pid, char character);
void    send_signal_to_client(pid_t pid, char bit, char pause_flag);

typedef struct s_protocol_state
{
    int     bits_received;     // Bits currently received
    int     current_char;      // Current data being received (either integer or char)
    int     message_received;  // Flag to indicate if we're receiving a message or length
    char    *received_message; // Pointer to store the received message
}   t_protocol_state;

#endif
