# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:52:34 by jisokim2          #+#    #+#              #
#    Updated: 2026/02/28 13:12:01 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17

SRC = $(wildcard *.cpp)
OBJ_DIR = obj/
OBJ = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC))
HEADER = $(wildcard *.hpp)

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re