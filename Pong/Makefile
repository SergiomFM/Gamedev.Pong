NAME = MLX_pong

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -ffast-math -O3 -Ofast
MLXLIB = minilibx-linux/minilibx-linux
MLXFLAGS = $(MLXLIB)/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS =   img.c Pong.c main.c colisions.c events.c delta_time.c score.c


OBJS = $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(MLXFLAGS):
	$(MAKE) -C $(MLXLIB)

$(NAME): $(MLXFLAGS) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLXLIB) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
