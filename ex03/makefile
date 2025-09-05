# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 16:05:46 by yel-bouk          #+#    #+#              #
#    Updated: 2025/09/05 16:15:02 by yel-bouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CC = c++
SRCS = Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \
		main.cpp

CFLAGS = -g -Wall -Wextra -Werror -std=c++98
LDFLAGS = -fsanitize=address
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re