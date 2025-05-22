# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourname <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 00:00:00 by yourname          #+#    #+#              #
#    Updated: 2025/05/22 00:00:00 by yourname         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
#            Library Settings          #
########################################

NAME        = libftprintf.a

LIBFT       = ./srcs/libft/libft.a
LIBFT_DIR   = ./srcs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./includes -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRC = \
	srcs/ft_printf.c \
	srcs/is_spec.c \
	srcs/main_process.c \
	srcs/spec_judge.c \
	srcs/process/process_c.c \
	srcs/process/process_d.c \
	srcs/process/process_i.c \
	srcs/process/process_lowerx.c \
	srcs/process/process_per.c \
	srcs/process/process_ptr.c \
	srcs/process/process_s.c \
	srcs/process/process_u.c \
	srcs/process/process_o.c \
	srcs/process/process_upperx.c \
	srcs/utils/free_padding.c \
	srcs/utils/ft_strjoin_free.c

BONUS_SRC = \
	srcs/flag_handle_bonus.c \
	srcs/is_flag_bonus.c \
	srcs/process_bonus/c_process/process_c_bonus.c \
	srcs/process_bonus/s_process/process_s_bonus.c \
	srcs/process_bonus/di_process/process_di_bonus.c \
	srcs/process_bonus/u_process/process_u_bonus.c \
	srcs/process_bonus/o_process/process_o_bonus.c \
	srcs/process_bonus/x_process/process_lowerx_bonus.c \
	srcs/process_bonus/x_process/process_upperx_bonus.c \
	srcs/process_bonus/p_process/process_p_bonus.c \
	srcs/process_bonus/per_process/process_per_bonus.c

OBJ     = $(SRC:.c=.o)
B_OBJ   = $(BONUS_SRC:.c=.o)

########################################
#               Rules                  #
########################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: $(LIBFT) $(OBJ) $(B_OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(B_OBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

