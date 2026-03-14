NAME        = libasm.a
TEST_NAME   = test_libasm
BONUS_TEST  = test_bonus

CC          = gcc
ASM         = nasm

CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=address
ASMFLAGS    = -f elf64
LDFLAGS     = -no-pie

INC_DIR     = include
SRC_DIR     = src
OBJ_DIR     = obj
BONUS_DIR   = src_bonus
BONUS_OBJ   = obj_bonus
TEST_DIR    = test

SRCS        = ft_strlen.s \
              ft_strcmp.s \
              ft_strcpy.s \
              ft_write.s \
              ft_read.s \
              ft_strdup.s

OBJS        = $(addprefix $(OBJ_DIR)/,$(SRCS:.s=.o))

BONUS_SRCS  = ft_list_size_bonus.s ft_list_push_front_bonus.s ft_list_sort_bonus.s ft_list_remove_if_bonus.s ft_atoi_base_bonus.s
BONUS_OBJS  = $(addprefix $(BONUS_OBJ)/,$(BONUS_SRCS:.s=.o))

TEST_SRCS   = $(TEST_DIR)/main.c \
              $(TEST_DIR)/test_strlen.c \
              $(TEST_DIR)/test_strcmp.c \
              $(TEST_DIR)/test_strcpy.c \
              $(TEST_DIR)/test_write.c \
              $(TEST_DIR)/test_read.c \
              $(TEST_DIR)/test_strdup.c

BONUS_TEST_SRCS = $(TEST_DIR)/main_bonus.c \
                  $(TEST_DIR)/test_list_size_bonus.c \
                  $(TEST_DIR)/test_list_push_front_bonus.c \
                  $(TEST_DIR)/test_list_sort_bonus.c \
                  $(TEST_DIR)/test_list_remove_if_bonus.c \
                  $(TEST_DIR)/test_atoi_base_bonus.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(BONUS_OBJ)/%.o: $(BONUS_DIR)/%.s | $(BONUS_OBJ)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ):
	mkdir -p $(BONUS_OBJ)

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(NAME) -I$(INC_DIR) $(LDFLAGS) -o $(TEST_NAME)

test_bonus: bonus
	$(CC) $(CFLAGS) $(BONUS_TEST_SRCS) $(NAME) -I$(INC_DIR) $(LDFLAGS) -o $(BONUS_TEST)

clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_NAME) $(BONUS_TEST)

re: fclean all

.PHONY: all bonus test test_bonus clean fclean re