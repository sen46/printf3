########################################
#            Library Settings          #
########################################

NAME        = libftprintf.a

# Path to the existing libft archive
LIBFT       = ./srcs/libft/libft.a
LIBFT_DIR   = ./srcs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./includes -I$(LIBFT_DIR)/includes

########################################
#       Source & Object Files          #
########################################

SRC = \
	srcs/ft_printf.c \
	srcs/is_spec.c \
	srcs/run.c \
	srcs/spec_judge.c \
	srcs/process/process_c.c \
	srcs/process/process_d.c \
	srcs/process/process_i.c \
	srcs/process/process_lowerx.c \
	srcs/process/process_per.c \
	srcs/process/process_ptr.c \
	srcs/process/process_s.c \
	srcs/process/process_u.c \
	srcs/process/process_upperx.c

BSRC = \
	srcs/flag1_bonus.c \
	srcs/flag2_bonus.c \
	srcs/spec1_judge_bonus.c \
	srcs/spec2_judge_bonus.c \
	srcs/is_option_bonus.c \
	srcs/process_bonus/minus/minus_c_bonus.c \
	srcs/process_bonus/minus/minus_di_bonus.c \
	srcs/process_bonus/minus/minus_lowerx_bonus.c \
	srcs/process_bonus/minus/minus_ptr_bonus.c \
	srcs/process_bonus/minus/minus_s_bonus.c \
	srcs/process_bonus/minus/minus_u_bonus.c \
	srcs/process_bonus/minus/minus_upperx_bonus.c \
	srcs/utils/ft_strncpy_bonus.c \
	srcs/process_bonus/plus/plus_di_bonus.c \
	srcs/process_bonus/blank/blank_di_bonus.c \
	srcs/process_bonus/hash/hash_lowerx_bonus.c \
	srcs/process_bonus/hash/hash_upperx_bonus.c \
	srcs/process_bonus/zero/zero_u_bonus.c \
	srcs/process_bonus/zero/zero_di_bonus.c \
	srcs/process_bonus/zero/zero_lowerx_bonus.c \
	srcs/process_bonus/zero/zero_upperx_bonus.c \
	srcs/process_bonus/dot/dot_u_bonus.c \
	srcs/process_bonus/dot/dot_s_bonus.c \
	srcs/process_bonus/dot/dot_di_bonus.c \
	srcs/process_bonus/dot/dot_lowerx_bonus.c \
	srcs/process_bonus/dot/dot_upperx_bonus.c \
	srcs/process_bonus/width/width_s_bonus.c \
	srcs/process_bonus/width/width_c_bonus.c \
	srcs/process_bonus/width/width_ptr_bonus.c \
	srcs/process_bonus/width/width_di_bonus.c \
	srcs/process_bonus/width/width_u_bonus.c \
	srcs/process_bonus/width/width_upperx_bonus.c \
	srcs/process_bonus/width/width_lowerx_bonus.c

OBJ  = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

########################################
#               Rules                  #
########################################

all: $(NAME)

bonus: $(NAME)_bonus

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(NAME)_bonus: $(LIBFT) $(OBJ) $(BOBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
