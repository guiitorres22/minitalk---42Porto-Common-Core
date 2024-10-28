#include "minitalk.h"

static void process_message_end(
    t_protocol_state *protocol,
    int *msg_index,
    pid_t client_pid)
{
    if (protocol->bits_received == 8 && protocol->message_received == 1)
    {
        protocol->received_message[*msg_index] = protocol->current_char;
        (*msg_index)++;
        if (protocol->current_char == '\0')
        {
            ft_printf("\e[32mMessage received: %s\n\e[0m", protocol->received_message);
            free(protocol->received_message);
            protocol->received_message = NULL;
            protocol->message_received = 0;
            *msg_index = 0;
            send_signal_to_client(client_pid, 1, 0);
        }
        protocol->bits_received = 0;
    }
}

static void process_message_length(t_protocol_state *protocol)
{
    if (protocol->bits_received == sizeof(int) * 8 && protocol->message_received == 0)
    {
        protocol->message_received = 1;
        ft_printf("\e[32mMessage length received: %d\n\e[0m", protocol->current_char);
        protocol->received_message = ft_calloc(protocol->current_char + 1, sizeof(char));
        if (protocol->received_message == NULL)
        {
            ft_printf("\e[31m## Error - Memory allocation failed ##\n\e[0m");
            exit(1);
        }
        protocol->bits_received = 0;
    }
}

static void server_handle_signal(int signal, siginfo_t *info, void *context)
{
    static t_protocol_state protocol;
    static int              msg_index;

    usleep(WAIT_TIME);
    (void)context;
    (void)info;
    if (protocol.bits_received == 0)
        protocol.current_char = 0;
    if (signal == SIGUSR2 && protocol.message_received == 0)
        protocol.current_char |= 1 << (((sizeof(int) * 8) - 1) - protocol.bits_received);
    else if (signal == SIGUSR2 && protocol.message_received == 1)
        protocol.current_char |= 1 << (((sizeof(char) * 8) - 1) - protocol.bits_received);
    protocol.bits_received++;
    process_message_length(&protocol);
    process_message_end(&protocol, &msg_index, info->si_pid);
    send_signal_to_client(info->si_pid, 0, 0);
}

int main(void)
{
    struct sigaction signal_action;

    sigemptyset(&signal_action.sa_mask);
    signal_action.sa_sigaction = server_handle_signal;
    signal_action.sa_flags = SA_SIGINFO | SA_RESTART;
    setup_signal_handling(&signal_action);
    ft_printf("\e[35mServer running with PID: %d\n\e[0m", getpid());
    while (1)
    {
        pause();
    }
    return (0);
}
