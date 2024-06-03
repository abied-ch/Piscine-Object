CXX		 = c++

NAME		= relationship

RM		  = rm -rf

SRCS_DIR	= src

OBJS_DIR	= obj

CXXFLAGS	= -Wall -Wextra -Werror -MP -MD -std=c++98 -Iinc -g

SRCS		= \
		$(SRCS_DIR)/main.cpp \

OBJS		= $(SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o)

DEPS		= $(OBJS:%.o=%.d)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
