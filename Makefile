########################################
#            Library Settings          #
########################################

# Name of the final archive
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
	srcs/is_ox_bonus.c \
	srcs/process_bonus/minus/minus_c_bonus.c \
	srcs/process_bonus/minus/minus_s_bonus.c \
	srcs/process_bonus/sharp/sharp_lowerx_bonus.c \
	srcs/process_bonus/sharp/sharp_o_bonus.c \
	srcs/process_bonus/sharp/sharp_upperx_bonus.c \
	srcs/process_bonus/width/width_c_bonus.c \
	srcs/process_bonus/width/width_s_bonus.c \
	srcs/process_bonus/width/width_ptr_bonus.c \
	srcs/process_bonus/width/width_d_bonus.c \
	srcs/process_bonus/width/width_i_bonus.c \
	srcs/process_bonus/width/width_lowerx_bonus.c \
	srcs/process_bonus/width/width_upperx_bonus.c \
	srcs/process_bonus/width/width_u_bonus.c \
	srcs/process_bonus/zero/0_s_bonus.c \
	srcs/process_bonus/zero/0_d_bonus.c \
	srcs/process_bonus/zero/0_i_bonus.c \
	srcs/process_bonus/zero/0_lowerx_bonus.c \
	srcs/process_bonus/zero/0_u_bonus.c \
	srcs/process_bonus/zero/0_upperx_bonus.c

OBJ  = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

########################################
#               Rules                  #
########################################

# Default build: only main objects
all: $(NAME)

# Build with bonus objects
bonus: $(NAME)_bonus

# Build main library
$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

# Build library with bonus
$(NAME)_bonus: $(LIBFT) $(OBJ) $(BOBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

# Ensure libft is built
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile source files into objects
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BOBJ)

# Clean all including archives
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Rebuild all
re: fclean all

.PHONY: all bonus clean fclean re
