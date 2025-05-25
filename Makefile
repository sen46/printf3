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
	srcs/process_bonus/x_process/process_lowerx_bonus.c \
	srcs/process_bonus/x_process/process_upperx_bonus.c \
	srcs/process_bonus/p_process/process_p_bonus.c \
	srcs/process_bonus/p_process/output_bonus.c \
	srcs/process_bonus/per_process/process_per_bonus.c

OBJ     = $(SRC:.c=.o)
B_OBJ   = $(BONUS_SRC:.c=.o)

########################################
#               Rules                  #
########################################

# デフォルトターゲット
all: $(NAME)

# ライブラリ作成: 通常 + bonusもまとめてアーカイブ
$(NAME): $(LIBFT) $(OBJ) $(B_OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(B_OBJ)

# bonusターゲットも一応定義（同じ内容）
bonus: $(NAME)

# Libftビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# オブジェクトファイル作成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# オブジェクト削除
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

# バイナリ・ライブラリ削除
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 全クリーン&再ビルド
re: fclean all

.PHONY: all bonus clean fclean re
