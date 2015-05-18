NAME		=		bomberman

CC		=		clang++ -g3

RM		=		rm -f

INCLUDES	=		-Icore/includes -Iscreen  -I./libgdl/includes/ -Iitem/includes/

CXXFLAGS	=		 $(INCLUDES) -Wall -Wextra -Werror 

GDL_LDFLAGS	=		-L./libgdl/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

SRCS		=		core/src/main.cpp \
				core/src/GameEngine.cpp \
				core/src/Exception.cpp \
				screen/Screen.cpp \
				item/src/Player.cpp \
				item/src/Bomb.cpp \
				item/src/Wall.cpp \
				item/src/AObject.cpp \

#SRCS		=		tp/main.cpp

OBJS		=		$(SRCS:.cpp=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(GDL_LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
