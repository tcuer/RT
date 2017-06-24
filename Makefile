#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cluciani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 11:48:02 by cluciani          #+#    #+#              #
#    Updated: 2017/05/03 18:07:45 by tcuer            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rt

SRC = main.c parse1.c get_next_line.c init.c parse2.c parse3.c image.c \
	  sphere.c vec.c plan.c ft_atof.c cylinder.c light.c raytracing.c\
	  key.c cone.c parse.c parse_init.c get_parse.c fill_var.c tools.c\
	  light2.c check_parse.c fill_var2.c class_init.c ft_count_type.c\
	  ft_count_type2.c text.c loading.c fill_var3.c ft_count_type3.c\
	  interobjs.c vec2.c vec3.c bump_mapping.c rotate.c c_limit.c\
	  cy_limit.c light_tools.c light_tools_2.c light_tools_3.c\
	  bump_mapping2.c parse_textu.c hyper.c h_limit.c parse4.c\
	  interobj2.c

CC = clang

CFLAGS = -Wall -Werror -Wextra -O3

SRCDIR = src
OBJDIR = obj
INCDIR = ./includes/ ./libft/

OBJ = $(SRC:.c=.o)

MLIBX = -lmlx -framework OpenGL -framework AppKit
LIBFT = -Llibft/ -lft

LIBP =	$(addprefix -L, $(LIBNAME)/)
OBJP =	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP =	$(foreach dir, $(INCDIR), -I$(dir))

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@make -sC libft/
	@echo "\033[32;44mCompilation RT\033[0m"
	@$(CC) $(CFLAGS) -o $@ $^ $(INCP) $(MLIBX) $(LIBFT)

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@echo "\033[31;44mObject deleted\033[0m"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "\033[32;44mFolder cleanup successful\033[0m"

re: fclean all
