# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martiper <martiper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:25:36 by martiper          #+#    #+#              #
#    Updated: 2024/03/26 20:03:38 by martiper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = Libft

SRCS_DIR = src

PRINTF_SRCS =	printf/ft_internal.c \
				printf/vf/ft_vfprintf_putaddress.c \
				printf/vf/ft_vfprintf_putchar.c \
				printf/vf/ft_vfprintf_putnbrs.c \
				printf/vf/ft_vfprintf_putstr.c \
				printf/vf/ft_vfprintf_putfloat.c \
				printf/vf/ft_vfprintf_putbool.c \
				printf/vf/ft_vfprintf_modifiers.c \
				printf/vf/ft_vfprintf.c \
				printf/vs/ft_vsprintf_putaddress.c \
				printf/vs/ft_vsprintf_putchar.c \
				printf/vs/ft_vsprintf_putnbrs.c \
				printf/vs/ft_vsprintf_putstr.c \
				printf/vs/ft_vsprintf_putfloat.c \
				printf/vs/ft_vsprintf_putbool.c \
				printf/vs/ft_vsprintf_modifiers.c \
				printf/vs/ft_vsprintf.c \
				printf/ft_fprintf.c \
				printf/ft_printf.c \
				printf/ft_sprintf.c \
				printf/ft_vprintf.c

GNL_SRCS =		gnl/get_next_line_utils.c \
				gnl/get_next_line.c

IO_SRCS = 		io/ft_putchar_fd.c \
				io/ft_putendl_fd.c \
				io/ft_putnbr_fd.c \
				io/ft_putstr_fd.c

LISTS_SRCS =	lists/ft_lstadd_back.c \
				lists/ft_lstadd_middle.c \
				lists/ft_lstdelone.c \
				lists/ft_lstgoto.c \
				lists/ft_lstlast.c \
				lists/ft_lstnew.c \
				lists/ft_lstsize.c \
				lists/ft_lstadd_front.c \
				lists/ft_lstclear.c \
				lists/ft_lstfind.c \
				lists/ft_lstiter.c \
				lists/ft_lstmap.c \
				lists/ft_lstremove.c \
				lists/ft_lstsort.c

MEMORY_SRCS =	memory/ft_bzero.c \
				memory/ft_calloc.c \
				memory/ft_memchr.c \
				memory/ft_memcmp.c \
				memory/ft_memcpy.c \
				memory/ft_memmove.c \
				memory/ft_memset.c

NBRS_SRCS =		numbers/ft_abs.c \
				numbers/ft_atoi.c \
				numbers/ft_atol.c \
				numbers/ft_isnbr.c \
				numbers/ft_nbrlen_base.c \

STRINGS_SRCS =	strings/ft_countchar.c \
				strings/ft_isdigit.c \
				strings/ft_isspace.c \
				strings/ft_split.c \
				strings/ft_strcpy.c \
				strings/ft_strjoin_sep.c \
				strings/ft_strncmp.c \
				strings/ft_strtrim.c \
				strings/ft_is_ascii.c \
				strings/ft_isprint.c \
				strings/ft_str_startswith.c \
				strings/ft_strdup.c \
				strings/ft_strlcat.c \
				strings/ft_strnstr.c \
				strings/ft_substr.c \
				strings/ft_isalnum.c \
				strings/ft_itoa.c \
				strings/ft_strchr.c \
				strings/ft_striteri.c \
				strings/ft_strlen.c \
				strings/ft_strrchr.c \
				strings/ft_tolower.c \
				strings/ft_isalpha.c \
				strings/ft_ltoa.c \
				strings/ft_strcmp.c \
				strings/ft_strjoin_mult.c \
				strings/ft_strmapi.c \
				strings/ft_strrep.c \
				strings/ft_toupper.c \
				strings/ft_strcase.c

PATTERN_MATCHING_SRCS = wildcards/bruteforce.c

DATE_SRCS = date/date.c date/mods/utils.c \
			date/mods/1.c date/mods/2.c date/mods/3.c \
			date/mods/4.c date/mods/5.c

DST_HASHTABLE_SRCS = data_structs/hashtable/hashes.c \
					data_structs/hashtable/hashtable.c \
					data_structs/hashtable/methods.c \
					data_structs/hashtable/methods2.c

DST_VECTOR_SRCS = data_structs/vector/vector.c \
					data_structs/vector/methods.c \
					data_structs/vector/methods2.c \
					data_structs/vector/methods3.c \
					data_structs/vector/methods4.c \
					data_structs/vector/sort.c

DST_SRCS =	$(DST_HASHTABLE_SRCS) \
			$(DST_VECTOR_SRCS)

SRCS =	$(PRINTF_SRCS) \
		$(GNL_SRCS) \
		$(IO_SRCS) \
		$(LISTS_SRCS) \
		$(MEMORY_SRCS) \
		$(NBRS_SRCS) \
		$(STRINGS_SRCS) \
		$(PATTERN_MATCHING_SRCS) \
		$(DST_SRCS) \
		$(DATE_SRCS)

OBJ_DIR = objs

SRC_FILES = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -gdwarf-2 -g3

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
	@ar -rcsP $(NAME) $^
	@echo "$(TAG) compiled version $(YELLOW)$$(cat VERSION)$(RESET)!"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
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
