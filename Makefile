#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 15:05:20 by yfuks             #+#    #+#              #
#    Updated: 2015/06/21 19:31:57 by yfuks            ###   ########.fr        #
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
				@clang++ $(FLAGS) -o $(NAME) $(INC) $(OBJS)
				@echo "enjoy :)"

obj/%.o:		sources/%.cpp
				@clang++ $(FLAGS) -o $@ $(INCLUDES) -c $<

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