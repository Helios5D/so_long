NAME = so_long

CC = cc

CFLAGS := -Wall -Wextra -Werror -g3

SRC =		core/so_long.c core/movement.c core/rendering.c\
			core/map_read.c core/map_check.c core/map_check_2.c core/exit.c\
			core/utils_1.c core/utils_2.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			ft_printf/ft_printf.c ft_printf/tools_1.c ft_printf/tools_2.c

BONUS_SRC =	bonus_core/so_long_bonus.c bonus_core/movement_bonus.c bonus_core/rendering_bonus.c\
			bonus_core/map_read_bonus.c bonus_core/map_check_bonus.c\
			bonus_core/map_check_2_bonus.c bonus_core/exit_bonus.c\
			bonus_core/utils_1_bonus.c bonus_core/utils_2_bonus.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			ft_printf/ft_printf.c ft_printf/tools_1.c ft_printf/tools_2.c

OBJ := $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

MLX_PATH = /home/hdaher/sgoinfre/hdaher/minilibx/

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

BLUE = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e '$(BLUE)Linking executable$(NC)'
	@$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)
	@echo -e '$(GREEN)Executable ./$(NAME) linked successfully$(NC)'

bonus: $(BONUS_OBJ)
	@echo -e '$(BLUE)Linking bonus executable$(NC)'
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo -e '$(GREEN)Bonus executable ./$(NAME) linked successfully$(NC)'

%.o: %.c
	@echo -e '$(BLUE)Compiling $<$(NC)'
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e '$(GREEN)Compiled $< successfully$(NC)'

clean:
	@echo -e '$(BLUE)Cleaning up object files$(NC)'
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@echo -e '$(GREEN)Object files cleaned up successfully$(NC)'

fclean: clean
	@echo -e '$(BLUE)Cleaning up object files and executable$(NC)'
	@rm -rf $(NAME)
	@echo -e '$(GREEN)Object files and executable cleaned up successfully$(NC)'

re: fclean all

.PHONY: all bonus clean fclean re
