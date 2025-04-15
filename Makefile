NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = functions
OBJ_DIR = obj

PHILO = functions/check.c functions/main.c functions/running.c functions/simulation.c \
	functions/utils.c

OBJS = $(PHILO:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
