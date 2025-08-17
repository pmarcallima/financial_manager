# Compiler and flags
CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -g


# External libs 
LIBS := -lncurses -ltinfo

#Linking flags
LDFLAGS := 

# Binary file 
BIN := bin/financial

# Directories
OBJ_DIR := obj
SRC_DIR := src
BIN_DIR:= bin

# .c files
SRC := $(wildcard $(SRC_DIR)/*.c)

# .o files
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# To disregard files named as such
.PHONY: all clean install help

all: build

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR) 
	$(CC) -c -o $@ $< $(CFLAGS) -MMD -MP 

-include $(OBJ:.o=.d)

$(BIN) : $(OBJ)
	@mkdir -p $(OBJ_DIR) 
	@mkdir -p $(BIN_DIR) 
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LIBS) 


dev: build
	./$(BIN)

build: $(BIN)

run:
	@echo "Running"
	@./$(BIN)

clean:
	@rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(BIN)
