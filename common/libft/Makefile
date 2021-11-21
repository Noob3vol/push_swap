# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iguidado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 11:15:40 by iguidado          #+#    #+#              #
#    Updated: 2021/11/21 18:10:50 by iguidado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Outing
NAME	=	libft.a

#Dir
HEADER	=	./include
D_OUT 	=	./outlib
D_MEM 	=	./mem
D_STR	=	./string
D_STD	=	./std
D_CTYPE	=	./ctype
D_LST	=	./list
D_BIT	=	./bitwise
D_TAB	=	./tab
D_TYPE	=	./type
D_UTIL	=	./utils
D_GNL	=	./gnl

#Files
S_OUT	=	ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putnbr_base.c\
		ft_putstr_non_printable.c\
		ft_print_value.c\
		ft_print_array.c\
		ft_print_memory.c 

S_MEM	= 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c 

S_STR	=	ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strindex.c \
		ft_strncmp.c \
		ft_strequ.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strmapi.c 

S_CTYPE =	ft_isindex.c\
		ft_isset.c\
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c 

S_STD	=	ft_atoi.c \
		ft_atoi_base.c \
		ft_itoa.c 

S_LST =		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstmap.c \
		ft_lstlen.c \
		ft_lstiter.c 

S_TAB	=	ft_print_tab.c\
			ft_free_tab.c

S_UTIL	=	ft_swap.c\
		ft_median_of_3.c

S_BIT	=	ft_isbit.c\
		ft_ismsk.c

S_TYPE	=	compute_int_max.c

S_GNL	=	get_next_line.c\
		get_next_line_utils.c

HFILE = $(addprefix $(HEADER), /$(addsuffix .h, $(basename $(NAME))))

#Compile
CC = clang
HFLAG = -I $(HEADER)
DEBUG = -g3 -fsanitize=address
WFLAG = -Wall -Werror -Wextra

#Auto
SRC = $(S_OUT) \
      $(S_LST) \
      $(S_STD) \
      $(S_MEM) \
      $(S_STR) \
      $(S_CTYPE) \
      $(S_TAB) \
      $(S_TYPE) \
      $(S_BIT) \
      $(S_UTIL)\
      $(S_GNL)

SRCS =	$(addprefix $(D_OUT)/, $(S_OUT)) \
	$(addprefix $(D_LST)/, $(S_LST)) \
	$(addprefix $(D_STD)/, $(S_STD)) \
	$(addprefix $(D_MEM)/, $(S_MEM)) \
	$(addprefix $(D_STR)/, $(S_STR)) \
	$(addprefix $(D_BIT)/, $(S_BIT)) \
	$(addprefix $(D_TAB)/, $(S_TAB)) \
	$(addprefix $(D_TYPE)/, $(S_TYPE)) \
	$(addprefix $(D_CTYPE)/, $(S_CTYPE)) \
	$(addprefix $(D_UTIL)/, $(S_UTIL)) \
	$(addprefix $(D_GNL)/, $(S_GNL))

OBJECT = $(SRCS:.c=.o) 


all: $(NAME)

$(NAME): $(OBJECT) $(SRCS)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(WFLAG) $(HFLAG) -o $@ -c $<

test: $(SRCS)
	$(CC) -o test $(WFLAG) $(HFLAG) $(SRCS)
	
debug: $(OBJECT)
	$(CC) -o debug $(DFLAG) $(WFLAG) $(HFLAG) $(SRCS)

clean:
	rm -f $(OBJECT) $(BONUS_OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
