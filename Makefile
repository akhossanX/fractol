
TARGET	=	fract

CFLAGS	=	-Werror -Wall -Wextra -g

CC		=	gcc

SRCDIR	=	src/

SRCS	=	$(shell ls $(SRCDIR))

INCDIR	=	inc/

LIBS	=	-pthread -lm -lmlx -lXext -lX11 ./libft/libft.a

INC		=	-I$(INCDIR)

OBJDIR	=	obj/

OBJS	=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

HEADERS	=	$(addprefix $(INCDIR), $(shell ls $(INCDIR)))

#DEFINE	=	-D STEP=0.05

all: $(OBJDIR) $(TARGET)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	$(CC) -c $(DEFINE) $(CFLAGS) $< $(INC) -o $@

$(OBJDIR):
	@mkdir -p $@

$(TARGET): $(OBJS) $(LIBS) 
	$(CC) $(CFLAGS) $^ -o $@

$(LIBS):
	@make -C libft/

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(TARGET)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
