NAME = avm
FILES = AbstractVM.cpp main.cpp Factory.cpp Exception.cpp Parser.cpp
FLAGS = -std=c++11 -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(FILES) -o $(NAME)
	@echo $(NAME) "has compiled successfuly"

fclean:
	@rm -f $(NAME)
	@echo $(NAME) "o files has been cleaned"

re: fclean all