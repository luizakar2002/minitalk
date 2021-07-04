SERVER = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = .

SERVER_FILE = server.c \
		utils.c

CLIENT_FILE = client.c \
		utils.c

OBJS_DIR = objs/

SERVER_OBJ = $(addprefix $(OBJS_DIR), $(SERVER_FILE:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJS_DIR), $(CLIENT_FILE:.c=.o))

all: $(OBJS_DIR) $(SERVER) $(CLIENT)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(SERVER): $(SERVER_OBJ)
	clang $(FLAGS) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT): $(CLIENT_OBJ)
	clang $(FLAGS) -o $(CLIENT) $(CLIENT_OBJ)

$(OBJS_DIR)%.o:%.c
	clang $(FLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: clean fclean re