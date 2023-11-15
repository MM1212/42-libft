# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martiper <martiper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:25:36 by martiper          #+#    #+#              #
#    Updated: 2023/11/15 22:20:16 by martiper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = Libft

SRCS_DIR = src

SRCS =	ft_atoi.c \
		ft_atol.c \
		ft_is_ascii.c \
		ft_isdigit.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strjoin_mult.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_ltoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_str_startswith.c \
		ft_strrep.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstfind.c \
		ft_lstremove.c \
		ft_lstsort.c \
		ft_lstgoto.c \
		ft_isnbr.c \
		ft_countchar.c \
		ft_abs.c \
		printf/vf/ft_vfprintf_putaddress.c \
		printf/vf/ft_vfprintf_putchar.c \
		printf/vf/ft_vfprintf_putnbrs.c \
		printf/vf/ft_vfprintf_putstr.c \
		printf/vf/ft_vfprintf_putfloat.c \
		printf/vf/ft_vfprintf.c \
		printf/vs/ft_vsprintf_putaddress.c \
		printf/vs/ft_vsprintf_putchar.c \
		printf/vs/ft_vsprintf_putnbrs.c \
		printf/vs/ft_vsprintf_putstr.c \
		printf/vs/ft_vsprintf_putfloat.c \
		printf/vs/ft_vsprintf.c \
		printf/ft_fprintf.c \
		printf/ft_printf.c \
		printf/ft_sprintf.c \
		printf/ft_vprintf.c \
		printf/ft_internal.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \


OBJ_DIR = objs

SRC_FILES = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

ARCH_DIR = bin
NAME =	$(addprefix $(ARCH_DIR)/, libft.a)

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = [$(CYAN)$(PROJECT_NAME)$(RESET)]

### END OF COLORS ###

all: $(NAME)

$(NAME) : $(OBJS)
	@mkdir -p $(dir $@)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(TAG) compiled version $(YELLOW)$$(cat VERSION)$(RESET)!"

$(OBJ_DIR)/%.o: %.c
	@echo "$(TAG) building $(YELLOW)$<$(RESET).."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(TAG) cleaned $(YELLOW)objects!$(RESET)\n"
	@rm -rf $(OBJS) $(OBJ_DIR)

fclean: clean
	@printf "$(TAG) cleaned $(YELLOW)archive!$(RESET)\n"
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all --no-print-directory -j $(shell nproc)

.PHONY : all clean fclean re
