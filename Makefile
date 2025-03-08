# Compiler options
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I./philo -g3

# Source and binary directories
SRC_DIR     = philo
BIN_DIR     = bin

# Project details
NAME        = philo_exec

# Define the source files here
PHILO       = main.c \
              utils.c \
			  init_structs.c \
			  actions.c \
			  controller.c

# Full paths to source files
PHILO_SRC   = $(PHILO:%=$(SRC_DIR)/%)

# Full paths to object files (in bin directory)
OBJ         = $(PHILO:%.c=$(BIN_DIR)/%.o)

# Colors for output
NC          = \033[0m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[1;33m
TITLE       = \033[38;5;33m

# Triggers
all: $(NAME)

# Compile .c files into .o files in the bin directory
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

# Link the object files to create the executable
$(NAME): $(OBJ)
	@echo "\n${TITLE}Linking${NC} ${YELLOW}$(NAME)${NC}"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

# Clean up object files and binary directory
clean:
	@echo "- ${RED}Cleaning${NC} object files and binary directory"
	@rm -rf $(BIN_DIR)

# Remove object files, binary, and any other build artifacts
fclean: clean
	@echo "- ${RED}Removing${NC} $(NAME)"
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Mark targets as phony to avoid conflicts with files named clean or fclean
.PHONY: all clean fclean re
