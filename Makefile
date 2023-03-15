# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:10:00 by mle-biha          #+#    #+#              #
#    Updated: 2023/03/15 18:50:09 by mle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------- Constant --------------------------- #

CC						= gcc
CFLAGS					= -Wall -Wextra -Werror -I.
NAME					= so_long
NAME_BONUS				= so_long_bonus
INCLUDES				= -I $(DIR_LIBFT) -I $(DIR_MLX) -I $(INC_DIR) -I $(DIR_LIBFT)/ft_printf -I \
							$(DIR_LIBFT)/gnl -I $(DIR_LIBFT)/libft
LIBS					= -L $(DIR_LIBFT) -lft -L $(DIR_MLX) -lmlx -lXext -lX11

# --------------------------- Sources --------------------------- #

# Files	
DIR_LIBFT			= Libft
LIBFT				= Libft/libft.a
DIR_MLX				= mlx
MLX					= mlx/libmlx_Linux.a

# Directories
SRC_DIR				= srcs
OBJ_DIR				= objs
INC_DIR				= includes
BONUS_DIR			= bonus

# Sources and objects
SRC					= $(SRC_DIR)/main.c \
						$(SRC_DIR)/map.c \
						$(SRC_DIR)/check_map.c \
						$(SRC_DIR)/display.c \
						$(SRC_DIR)/textures.c \
						$(SRC_DIR)/direction.c \
						$(SRC_DIR)/assign_char.c
OBJ					= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SRC_BONUS			= $(SRC_DIR)/$(BONUS_DIR)/main_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/map_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/check_map_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/display_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/textures_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/direction_bonus.c \
						$(SRC_DIR)/$(BONUS_DIR)/assign_char_bonus.c
OBJ_BONUS			= $(SRC_BONUS:$(SRC_DIR)/$(BONUS_DIR)/%.c=$(OBJ_DIR)/$(BONUS_DIR)/%.o)

# --------------------------- Colors --------------------------- #

GREEN				= \e[1;32m
YELLOW				= \e[1;33m
BLUE				= \e[1;34m
MAGENTA				= \e[1;35m
NO_COLOR			= \e[0m

# --------------------------- Rules --------------------------- #

all: $(NAME)

$(LIBFT):
	@echo "\n$(MAGENTA)Creating Libft...$(NO_COLOR)"
	@make -C $(DIR_LIBFT) --no-print-directory
	@echo "$(GREEN)Libft OK !$(NO_COLOR)\n"

$(MLX):
	@echo "\n$(MAGENTA)Creating MiniLibX...$(NO_COLOR)"
	@make -C $(DIR_MLX) --no-print-directory
	@echo "$(GREEN)MiniLibX OK!$(NO_COLOR)\n"
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(MAGENTA)Creating so_long...$(NO_COLOR)"	
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "$(GREEN)so_long OK !$(NO_COLOR)\n"

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(INCLUDES) -o $@ -c $< $(CFLAGS) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MLX)
	@echo "$(MAGENTA)Creating so_long_bonus...$(NO_COLOR)"	
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDES) $(LIBS) -o $(NAME_BONUS)
	@echo "$(GREEN)so_long_bonus OK !$(NO_COLOR)\n"

$(OBJ_BONUS): $(OBJ_DIR)/$(BONUS_DIR)/%.o: $(SRC_DIR)/$(BONUS_DIR)/%.c
	@$(CC) $(INCLUDES) -o $@ -c $< $(CFLAGS) 

clean:
	@echo "\n$(YELLOW)Cleaning objects !$(NO_COLOR)"
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(DIR_LIBFT) --no-print-directory clean
	@make -C $(DIR_MLX) --no-print-directory clean
	@echo "$(GREEN)Objects cleaned !$(NO_COLOR)\n"

fclean: clean
	@echo "$(YELLOW)Cleaning everything !$(NO_COLOR)"
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(DIR_LIBFT) --no-print-directory fclean
	@echo "$(GREEN)Everything cleaned !$(NO_COLOR)\n"

re: fclean all

.PHONY : clean fclean re