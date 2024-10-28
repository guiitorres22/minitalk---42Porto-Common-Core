# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

# Program for compiling C programs
CC := cc -g

# Extra flags to give to the C compiler
CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

# =============================================================================
#	MANDATORY PART
# =============================================================================

SRC_SERVER := server.c minitalk-utils.c
SRC_CLIENT := client.c minitalk-utils.c

INCLUDES := -I. -Ilibft -I./ft_printf

LIBFT := ./libft/libft.a
PRINTF := ./ft_printf/libftprintf.a

LIBFT_PATH := ./libft
PRINTF_PATH := ./ft_printf

# =============================================================================
#	RULES
# =============================================================================

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

$(NAME_SERVER): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

# Clean object files (*.o) - not used on this project
clean:
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Clean object files (*.o) and the binary file
fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re: fclean all

# =============================================================================
#	PHONY
# =============================================================================

.PHONY: all clean fclean re
