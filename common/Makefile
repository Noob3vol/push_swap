NAME = libcommon.a
CC = clang

LIB = libft/libft.a

TEST=test

INC = include/
HDR = common.h\
	stack.h\
	stack_wrap.h

SRC = ft_check_arg.c\
      ft_inst_exec.c\
	ft_stack.c\
	ft_stack_utils.c\
	ft_stack_ruler.c\
	ft_stack_op.c\
	ft_stack_wrapper_a.c\
	ft_stack_wrapper_b.c\
	ft_stack_wrapper_all.c\
	ft_print_stacks.c\
	ft_link_op.c

WFLAG = -Werror -Wextra -Wall

TEST_SRC = test.c

OBJ_DIR = obj/

HEADER = $(addprefix $(INC), $(HDR))

#OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ = $(SRC:.c=.o)

all : makelib $(NAME)

$(NAME) : $(LIB) $(OBJ)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

%.o : %.c $(HEADER)
	$(CC) -I$(INC) -o $@ -c $< $(WFLAG)

makelib : 
	$(MAKE) -C libft/

test : $(NAME) $(TEST_SRC)
	$(CC) -I$(INC) $(TEST_SRC) $(NAME) -o test

clean :
	-rm -f $(OBJ)

fclean : clean
	-rm -f $(NAME)

re : fclean $(NAME)

.PHONY: clean fclean re makelib
