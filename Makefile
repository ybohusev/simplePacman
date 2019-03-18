NAME = Pacman
COMP = clang++
FLAGS = -std=c++98 -lncurses -Wall -Wextra -Werror

DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_HDR = ./includes

SRC = 
SRC += main.cpp
SRC += Core.cpp
SRC += Map.cpp

HDR = 
HDR += pacman.h
HDR += Core.h
HDR += Map.h

SRCS = $(addprefix $(DIR_SRC)/,$(SRC))
OBJS = $(addprefix $(DIR_OBJ)/,$(SRC:.cpp=.o))
# INC = $(addprefix $(DIR_HDR)/,$(HDR))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) -o $(NAME) $(OBJS) $(FLAGS) -I $(DIR_HDR)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(DIR_OBJ)
	@$(COMP) -I $(DIR_HDR) -o $@ -c $<

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all