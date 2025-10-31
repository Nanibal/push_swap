# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-10-30 09:48:31 by nayala            #+#    #+#             #
#   Updated: 2025-10-30 09:48:31 by nayala           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

SRCDIR = src
OBJDIR = obj

SRCS = main.c operations.c operations2.c operations3.c parsing.c \
		sort_big.c sort_small.c utils.c utils2.c utils3.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C libft

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re