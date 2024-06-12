# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 13:34:31 by bgolding          #+#    #+#              #
#    Updated: 2024/01/26 13:50:00 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

B_NAME			=	checker

LIB				=	lib/
INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
B_OBJ_DIR		=	obj_bonus/
INC_DIR			=	inc/
LIBFT_DIR		=	$(LIB)libft/

SRC_FILES		=	main \
					cleaners \
					input_check \
					stack_utils_1 \
					stack_utils_2 \
					stack_utils_3 \
					instructions_1 \
					instructions_2 \
					instructions_3 \
					shazam_sort \
					shazam_sort_utils \
					mini_sort \
					push_slice \
					push_slice_utils

B_SRC_FILES		=	checker_bonus \
					cleaners \
					input_check \
					stack_utils_1 \
					stack_utils_2 \
					stack_utils_3 \

STATIC_LIBS		=	$(LIB)libft/libft.a

OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJS			=	$(addprefix $(B_OBJ_DIR), $(addsuffix .o, $(B_SRC_FILES)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar -r

DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m

all:			$(NAME) $(B_NAME)

$(NAME):		$(STATIC_LIBS) $(OBJ_DIR) $(OBJS)
				@$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft $(OBJS) -o $@
				@echo "$(GREEN)Successfully created program: $(NAME) $(DEF_COLOR)"

$(STATIC_LIBS):
				@echo "$(YELLOW)Creating archives...$(DEF_COLOR)"
				@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(B_OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(B_OBJ_DIR)
					@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $@

$(B_OBJ_DIR):
				@mkdir -p $@

$(B_NAME):		$(STATIC_LIBS) $(B_OBJ_DIR) $(B_OBJS)
				@$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft $(B_OBJS) -o $(B_NAME)
				@echo "$(GREEN)Successfully created program: $(B_NAME)$(DEF_COLOR)"

bonus:			$(B_NAME)

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) -r $(B_OBJ_DIR)
				@make clean -C $(LIBFT_DIR)
				@echo "$(GREEN)clean complete $(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME) $(B_NAME)
				@make fclean -C $(LIBFT_DIR)
				@echo "$(GREEN)fclean complete $(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re