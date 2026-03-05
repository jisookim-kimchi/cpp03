# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:52:34 by jisokim2          #+#    #+#              #
#    Updated: 2026/03/05 08:59:55 by jisokim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrapChild

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17

SRC_DIR = SRC/
OBJ_DIR = OBJ/
HEADER_DIR = HEADER/

# $(patsubst pattern, replacement, text)
# $(SRC_DIR)%.cpp
SRC = $(SRC_DIR)main.cpp \
		$(SRC_DIR)ClapTrap.cpp \
		$(SRC_DIR)ScavTrap.cpp \
		
OBJ = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re