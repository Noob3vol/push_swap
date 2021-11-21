#COMPILATION

CC = clang
GFLAG = -g
WFLAG = -Werror -Wextra -Wall

#NAME

CHECKER = checker

PUSH = push_swap


INC = include

# CHECKER

CHECK_SRC = checker.c\
	    ft_store_inst.c

CHECK_SRC_DIR = Checker/

CHECK_OBJ_DIR = check_obj/

CHECK_OBJ = $(addprefix $(CHECK_OBJ_DIR), $(CHECK_SRC:.c=.o))

CHECK_HEADER = checker.h

# LIB

LIB = common/libcommon.a

#PUSH

PUSH_DIR = Source_push_swap/

PUSH_SRC = ft_inst_utils.c \
	   ft_inst_clean.c \
	ft_node_detection.c\
	ft_stack_checker.c \
	ft_stack_utils.c \
	ft_stack_adv_inst.c \
	ft_stack_gather_info.c \
	ft_bubble_sort.c \
	ft_stack_sort_slct.c \
	ft_stack_sort_insrt.c \
	ft_quickprep.c \
	ft_stack_quickpart.c \
	ft_part_gather_info.c \
	ft_part_checker.c \
	ft_part_init_info.c \
	ft_stack_to_tab.c \
	ft_part_bubble_sort.c \
	ft_part_sort_insrt.c \
	ft_part_sort_slct.c \
	ft_stack_quickrecurse.c \
	ft_stack_quicksort.c \
	push_swap.c

#	ft_choose_part_sort.c

PUSH_OBJ_DIR = Push_obj/

PUSH_OBJ = $(addprefix $(PUSH_OBJ_DIR), $(PUSH_SRC:.c=.o))

all : makelib $(PUSH)

makelib :
	make -C common/

#PUSH INSTRUCTION

$(PUSH) : $(PUSH_OBJ_DIR) $(PUSH_OBJ) $(LIB)
	$(CC) $(GFLAG) $(WFLAG) -v -o $(PUSH) -I$(INC) $(PUSH_OBJ) $(LIB) $(WFLAG)

$(PUSH_OBJ_DIR) :
	mkdir $(PUSH_OBJ_DIR)

$(PUSH_OBJ_DIR)%.o : $(PUSH_DIR)%.c
	clang -I$(INC) -o $@ -c $< $(WFLAG)

#CHECKER INSTRUCTION

$(CHECK_OBJ_DIR) :
	mkdir $(CHECK_OBJ_DIR)

$(CHECK_OBJ_DIR)%.o : $(CHECK_SRC_DIR)%.c
	$(CC) -I$(INC) -o $@ -c $< $(WFLAG)

$(CHECKER) : $(LIB) $(CHECK_OBJ_DIR) $(CHECK_OBJ) $(INC)/$(CHECK_HEADER)
	$(CC) -o $(CHECKER) -I$(INC) $(CHECK_OBJ) $(LIB) $(WFLAG)

bonus : all $(CHECKER)

clean :
	@- make clean -C ./common
	@- rm -rf $(CHECK_OBJ_DIR) $(PUSH_OBJ_DIR) 

fclean : clean
	@- make fclean -C ./common
	@- rm -f $(CHECKER) $(PUSH)

re : fclean all

re-bonus : fclean bonus

.PHONY: all bonus clean fclean re re-bonus makelib
