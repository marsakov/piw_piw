# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 22:54:38 by oevtushe          #+#    #+#              #
#    Updated: 2018/10/07 23:05:18 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	piw_piw_v0.9

CC		:= clang++
CFLAGS	:= -Wall -Werror -Wextra

DEPS	:= Player.hpp Enemy.hpp Bullet.hpp GameEntity.hpp
SRCS	:= Bullet.cpp Enemy.cpp Player.cpp GameEntity.cpp main.cpp
OBJS	:= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
