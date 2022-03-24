# File paths
CPP_SRC_DIR := ./
CPP_OBJ_DIR := ./
C_SRC_DIR := ./
C_OBJ_DIR := ./

# Compilation flags
CC := g++
CPPFLAGS := -std=c++17
CFLAGS :=

# Files to be compiled
CPP_SRCS := $(wildcard $(CPP_SRC_DIR)/*.cc)
CPP_OBJS := $(CPP_SRCS:$(CPP_SRC_DIR)/%.cc=$(CPP_OBJ_DIR)/%.o)
C_SRCS := $(wildcard $(C_SRC_DIR)/*.c)
C_OBJS := $(C_SRCS:$(C_SRC_DIR)/%.c=$(C_OBJ_DIR)/%.o)

all: $(CPP_OBJS) $(C_OBJS)

cpp: $(CPP_OBJS)

c: $(C_OBJS)

# Compile each *.cc file as *.o files
$(CPP_OBJ_DIR)/%.o: $(CPP_SRC_DIR)/%.cc
	@echo "$(CC) $(CPPFLAGS) -o $@ $<"
	@$(CC) $(CPPFLAGS) -o $@ $<

# Compile each *.c file as *.o files
$(C_OBJ_DIR)/%.o: $(C_SRC_DIR)/%.c
	@echo "gcc $(CFLAGS) -o $@ $<"
	@gcc $(CFLAGS) -o $@ $<

.PHONY:all clean cpp c
clean:
	@echo "Cleaning *.o"
	@rm -rf *.o
	@rm -rf output
