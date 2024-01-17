NAME = gausshimself
SRCS = main.cpp LGS.cpp ParsingUtils.cpp
CFLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(CFLAGS) $(SRCS) -o $@
