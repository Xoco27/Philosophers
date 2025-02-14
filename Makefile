NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = functions
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

PHILO = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(PHILO:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
