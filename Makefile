#colors

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
BOLDBLACK	= \033[1m\033[30m
BOLDRED		= \033[1m\033[31m
BOLDGREEN	= \033[1m\033[32m
BOLDYELLOW	= \033[1m\033[33m
BOLDBLUE	= \033[1m\033[34m
BOLDMAGENTA	= \033[1m\033[35m
BOLDCYAN	= \033[1m\033[36m
BOLDWHITE	= \033[1m\033[37m

NAME 			= 	class
CC 				= 	c++

SRC_FOLDER		=	./
INC_FOLDER		=	./
OBJS_FOLDER		=	objs/

SRC_FILES		= class_generator.cpp

INCLUDES_FILES	= include.hpp

SRC 			= 	$(addprefix $(SRC_FOLDER), $(SRC_FILES))
INCLUDES 		= 	$(addprefix $(INC_FOLDER), $(INCLUDES_FILES))

OBJ 			= 	${SRC_FILES:.cpp=.o}
CFLAGS 			= -Wall -Werror -Wextra -std=c++98#-g3 -fsanitize=address
OBJS			= 	$(addprefix $(OBJS_FOLDER), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS_FOLDER) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(CYAN)$(CC) $(BOLDGREEN)$(CFLAGS) $(BLACK)-o $(MAGENTA)$(NAME) $(YELLOW)$(OBJS)"

$(OBJS_FOLDER)%.o : $(SRC_FOLDER)%.cpp $(INCLUDES) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_FOLDER)
	@echo "$(CYAN)$(CC) $(BOLDGREEN)$(CFLAGS) $(BLACK)-o $(YELLOW)$@ $(BLACK)-c $(BOLDBLUE)$< $(BLACK)-I $(RED)$(INC_FOLDER)"


$(OBJS_FOLDER):
	@mkdir $(OBJS_FOLDER)
	@echo "$(BLUE)mkdir $(YELLOW)$(OBJS_FOLDER)"

clean :
	@-rm -rf $(OBJS_FOLDER)
	@echo "$(BOLDRED)-rm $(RED)-rf  $(YELLOW)$(OBJS_FOLDER)"
fclean : clean
	@-rm -f $(NAME)
	@echo "$(BOLDRED)-rm $(RED)-f  $(MAGENTA)$(NAME)"

re : fclean all

.PHONY: all clean fclean re
