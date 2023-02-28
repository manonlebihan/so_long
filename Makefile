# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:10:00 by mle-biha          #+#    #+#              #
#    Updated: 2023/02/28 11:28:20 by mle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------- Constant --------------------------- #

CC						= gcc
CFLAGS					= -Wall -Wextra -Werror -I.
NAME					= so_long
NAME_BONUS				= so_long_bonus
INCLUDES				= -I $(DIR_LIBFT) -I $(DIR_MLX) -I includes -I $(DIR_LIBFT)/ft_printf -I \
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

# Sources and objects
SRC					= $(SRC_DIR)/main.c \
						$(SRC_DIR)/memory_map.c
OBJ					= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# old OBJ = $(SRC:.c=.o)

# SRC_BONUS			= server_bonus.c
# OBJ_BONUS			= $(SRC_SERVER_BONUS:.c=.o)

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
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBS) -o $(NAME)
	@echo "$(GREEN)so_long OK !$(NO_COLOR)\n"

#$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
#	@echo "$(BLUE)Creating Server Bonus...$(NO_COLOR)"
#	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(INCLUDE) $(LIB) -o $(NAME_BONUS)
#	@echo "$(GREEN)Server Bonus OK !$(NO_COLOR)\n"

#bonus: $(NAME_BONUS) $(CLIENT_NAME_BONUS) $(LIBFT)

#%.o: %.c
#	@$(CC) $(INCLUDE) -o $@ -c $< $(CFLAGS)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(INCLUDES) -o $@ -c $< $(CFLAGS) 

clean:
	@echo "\n$(YELLOW)Cleaning objects !$(NO_COLOR)"
	@rm -f $(OBJ)
	@make -C $(DIR_LIBFT) --no-print-directory clean
	@make -C $(DIR_MLX) --no-print-directory clean
	@echo "$(GREEN)Objects cleaned !$(NO_COLOR)\n"

fclean: clean
	@echo "$(YELLOW)Cleaning everything !$(NO_COLOR)"
	@rm -f $(NAME)
	@make -C $(DIR_LIBFT) --no-print-directory fclean
	@echo "$(GREEN)Everything cleaned !$(NO_COLOR)\n"

re: fclean all

.PHONY : clean fclean re