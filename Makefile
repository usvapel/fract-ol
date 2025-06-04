# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 21:55:46 by jpelline          #+#    #+#              #
#    Updated: 2025/05/15 19:46:55 by jpelline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors and formatting
BOLD		:= $(shell tput bold)
GREEN		:= $(shell tput setaf 2)
YELLOW		:= $(shell tput setaf 3)
BLUE		:= $(shell tput setaf 4)
MAGENTA		:= $(shell tput setaf 5)
CYAN		:= $(shell tput setaf 6)
WHITE		:= $(shell tput setaf 7)
RESET		:= $(shell tput sgr0)

# Name target
NAME	:=	fractol

# Compiler flags
CC				:=	cc
CFLAGS			:=	-Wextra -Wall -Werror

# Directories
OBJ_DIR			:=	obj
SRC_DIR			:=	src

# Dependencies tracking
DEP_DIR			:=	$(OBJ_DIR)/.deps
DEPFLAGS		=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

# Libraries
LIBFT_DIR		:=	./libft
LIBFT			:=	$(LIBFT_DIR)/libft.a

MLX_PATH		:=	./MLX42/build/
MLX_NAME		:=	libmlx42.a
MLX_BPATH		:=	./MLX42/
MLX				:=	$(MLX_PATH)$(MLX_NAME)

# Additional flags
LDFLAGS			:=	-L$(LIBFT_DIR) -lft -L$(MLX_PATH) -lmlx42 \
					-lglfw -lXext -lX11 -lm -ldl -pthread

# Include paths
INC				:=	-I./include -I./MLX42/include/MLX42 -I$(LIBFT_DIR)

# Sources
SRCS			:=	fractol.c color.c zoom.c utils.c init.c julia.c \
					mandelbrot.c burningship.c keys.c julia_utils.c

# Objects
OBJS			:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
TOTAL_SRCS		:=	$(words $(SRCS))

# Calculating SRCS amount
COMPILED_COUNT	:=	0

# Default target / checks if rebuild is needed
all:
	@if [ -f $(NAME) ] && [ "$(NAME)" -nt $(word 1,$(sort $(wildcard $(SRC_DIR)/*.c))) ] && \
		[ "$(NAME)" -nt $(LIBFT) ] && [ "$(NAME)" -nt $(MLX) ]; then \
		echo "$(BOLD)$(YELLOW)🔄 $(NAME) is already up to date.$(RESET)"; \
	else \
		echo "$(BOLD)$(WHITE)🌀 Starting to build $(NAME)...$(RESET)"; \
		$(MAKE) $(NAME) --no-print-directory; \
		echo "$(BOLD)$(GREEN)✅ All components built successfully!$(RESET)"; \
	fi

# Main executable target - links all objects and libraries
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(BOLD)$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) -O3 -march=native -ffast-math
	@echo "$(BOLD)$(GREEN)✅ $(NAME) successfully compiled!$(RESET)"

# Create necessary directories if they don't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	@mkdir -p $@

# Compilation rule for each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(eval COMPILED_COUNT := $(shell echo $$(($(COMPILED_COUNT)+1))))
	@printf "🔧 [%3d%%] $(BOLD)$(BLUE)Compiling $<...$(RESET)\n" \
		$(shell echo $$(($(COMPILED_COUNT)*100/$(TOTAL_SRCS))))
	@$(CC) $(CFLAGS) $(DEPFLAGS) -O3 -march=native -ffast-math -c $< -o $@ $(INC)

# Include auto-generated dependency files
-include $(wildcard $(DEP_DIR)/*.d)

# build libft if needed
$(LIBFT):
	@echo "$(MAGENTA)📚 Building libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Build MLX42 if needed
$(MLX):
	@echo "$(CYAN)📚 Building MLX42 library...$(RESET)"
	@git clone -q --depth 1 \
	--branch v2.4.1 \
	--single-branch \
	https://github.com/codam-coding-college/MLX42.git > /dev/null 2>&1
	@echo "$(BOLD)$(GREEN)✅ ./MLX42 successfully cloned!$(RESET)"
	@cd $(MLX_BPATH) && cmake -B build > /dev/null 2>&1
	@echo "$(BOLD)$(GREEN)✅ ./MLX42 successfully built to ./MLX42/build$(RESET)"
	@$(MAKE) -C $(MLX_PATH) --no-print-directory
	@echo "$(BOLD)$(GREEN)✅ $(MLX) successfully compiled!$(RESET)"

# Remove object files and dependency files
clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(YELLOW)✅ Object files cleaned!$(RESET)"

# Remove everything including the executable
fclean: clean
	@echo "$(YELLOW)🧹 Removing $(NAME)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(YELLOW)✅ $(NAME) removed!$(RESET)"

# Full rebuild from scratch
re: fclean
	@echo "$(BOLD)$(WHITE)🔄 Rebuilding from scratch...$(RESET)"
	@$(MAKE) all

# Prevent intermediate files from being deleted
.SECONDARY: $(OBJS)
.PHONY: all clean fclean re
