#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 15:05:20 by yfuks             #+#    #+#              #
#    Updated: 2015/06/21 20:04:45 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 			ft_retro

SRCS =			sources/main.cpp \
				sources/Window.class.cpp \
				sources/Sprite.class.cpp \
				sources/Penis.class.cpp \
				sources/Bullet.class.cpp \
				sources/Vagina.class.cpp


OBJS =			$(SRCS:sources/%.cpp=obj/%.o)

FLAGS =			-Wall -Wextra -Werror

INCLUDES =		-I includes/

INC = 			-lncurses

all:			$(NAME)

$(NAME):		obj $(OBJS)
				g++ $(FLAGS) -o $(NAME) $(OBJS) $(INC)
				@echo "[\033[1;32m√\033[m]" $@								

obj/%.o:		sources/%.cpp
				@g++ $(FLAGS) -o $@ $(INCLUDES) -c $<
				@echo "[\033[1;32m√\033[m]" $@

obj:
				@mkdir -p obj

clean:
				@/bin/rm -rf obj
				@echo "clean ;)"

fclean:			clean
				@/bin/rm -f $(NAME)
				@echo "fclean ;)"

re:				fclean all

.PHONY =		all clean fclean re
