NAME	=	minishell

SRCS	=	main.c \
				welcome_shell.c \
				sig_handler.c \
				initenv.c \

CMD_DIR	=	./cmd_handler
CMD_FILE	=	cmd_handler.c \
				parse_input.c \
				handler_utils.c \

CMD		= $(addprefix $(CMD_DIR)/, $(CMD_FILE))
OBJ_CMD = $(CMD:%.c=%.o)

EXE_DIR	=	./cmd_execute
EXE_FILE	=	cmd_env.c \
				cmd_export.c \
				cmd_exit.c \

EXE		= $(addprefix $(EXE_DIR)/, $(EXE_FILE))
OBJ_EXE = $(EXE:%.c=%.o)

LIB = -L ./ft_printf -lftprintf

all:	$(NAME)

$(NAME): $(OBJ_CMD) $(OBJ_EXE)
	@$(MAKE) -C ./ft_printf all
	gcc $(SRCS) $(OBJ_CMD) $(OBJ_EXE) $(LIB) -o minishell

clean:
	@$(MAKE) -C ./ft_printf clean
	rm -f $(OBJ_CMD) $(OBJ_EXE)
#여기다가 OBJ_CMD이 아닌 objs의 종합을 넣어야 함

fclean:
	@$(MAKE) -C ./ft_printf fclean
	rm -rf $(NAME) $(OBJ_CMD) $(OBJ_EXE)

re:
	@$(MAKE) fclean all

.PHONY: all fclean clean re