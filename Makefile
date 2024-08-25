# Compiler options
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I./philo -g3

# Source and binary directories
SRC		    	= philo
BIN				= bin

# Project details
NAME			= philo

# Define the source files here
PHILO		=	main.c \
				check_errors.c \
				utils.c

PHILO_SRC 	=   $(PHILO:%=philo/%)

SOURCE		=	$(PHILO_SRC)
SRC_CODE    =   $(SOURCE:%=$(SRC)/%)
OBJ         =   $(SRC_CODE:$(SRC)/%.c=$(BIN)/%.o)
# OBJ			=	$(SRC_CODE:.c=.o)

# Colors for output
NC          = \033[0m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[1;33m
TITLE       = \033[38;5;33m

# Triggers
all: $(NAME)

$(BIN)/%.o: $(SRC)/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(NAME): $(OBJ)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}$(NAME)${NC}"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

.PHONY: all clean fclean re philo

# Clean up object files and binary directory
clean:
	@echo "- ${RED}Cleaning${NC} object files and binary directory"
	@rm -rf $(BIN)

# Remove object files, binary, and any other build artifacts
fclean: clean
	@echo "- ${RED}Removing${NC} $(NAME)"
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Mark targets as phony to avoid conflicts with files named clean or fclean
.PHONY: all clean fclean re