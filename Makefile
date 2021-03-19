  
APP_NAME = geometry
LIB_NAME = libgeometry

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS =
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.cpp')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
APP_PATH = $(BIN_DIR)/$(APP_NAME)

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.cpp')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)


OBJ_APP = $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)
OBJ_LIB = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)
EXE_PATH = $(BIN_DIR)/$(APP_NAME)
SRC_APP = $(SRC_DIR)/$(APP_NAME)
SRC_LIB = $(SRC_DIR)/$(LIB_NAME)

FIND_LIB = $(shell find $(SRC_LIB) -name '*.cpp')

SRC_EXT = cpp
.PHONY: all
all: $(EXE_PATH).exe

$(EXE_PATH).exe: $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJ_APP)/$(APP_NAME).o: $(SRC_APP)/$(APP_NAME).cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
	
$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^
	
$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	find $(OBJ_APP) -name "*.o" -type f -delete
	find $(OBJ_APP) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.o" -type f -delete
	find $(OBJ_LIB) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.a" -type f -delete
	