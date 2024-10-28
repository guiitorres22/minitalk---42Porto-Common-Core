#include "minitalk.h"

void setup_signal_handling(struct sigaction *sa)
{
    if (sigaction(SIGUSR1, sa, NULL) < 0)
    {
        ft_printf("\e[31m## Error - Unable to handle SIGUSR1 ##\n\e[0m");
        exit(1);
    }
    if (sigaction(SIGUSR2, sa, NULL) < 0)
    {
        ft_printf("\e[31m## Error - Unable to handle SIGUSR2 ##\n\e[0m");
        exit(1);
    }
}

void send_integer_to_server(pid_t pid, int number)
{
    int     shift;
    char    bit;

    shift = (sizeof(int) * 8) - 1;
    while (shift >= 0)
    {
        bit = (number >> shift) & 1;
        send_signal_to_client(pid, bit, 1);
        shift--;
    }
}

void send_char_to_server(pid_t pid, char character)
{
    int     shift;
    char    bit;

    shift = (sizeof(char) * 8) - 1;
    while (shift >= 0)
    {
        bit = (character >> shift) & 1;
        send_signal_to_client(pid, bit, 1);
        shift--;
    }
}

void send_signal_to_client(pid_t pid, char bit, char pause_flag)
{
    if (bit == 0)
    {
        if (kill(pid, SIGUSR1) < 0)
        {
            ft_printf("\e[31m## Error - Failed to send SIGUSR1 ##\n\e[0m");
            exit(1);
        }
    }
    else if (bit == 1)
    {
        if (kill(pid, SIGUSR2) < 0)
        {
            ft_printf("\e[31m## Error - Failed to send SIGUSR2 ##\n\e[0m");
            exit(1);
        }
    }
    if (pause_flag != 0)
        pause();
}
