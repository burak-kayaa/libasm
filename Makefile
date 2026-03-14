NAME = libasm.a
TEST = test_libasm

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test
INC_DIR = include

SRCS = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.s=.o))

TEST_SRCS = \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/test_strlen.c \
	$(TEST_DIR)/test_strcmp.c \
	$(TEST_DIR)/test_strcpy.c \
	$(TEST_DIR)/test_write.c \
	$(TEST_DIR)/test_read.c \
	$(TEST_DIR)/test_strdup.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	nasm -f elf64 $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME)
	gcc -no-pie -fsanitize=address -g $(TEST_SRCS) $(NAME) -I$(INC_DIR) -o $(TEST)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all