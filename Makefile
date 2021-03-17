  
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
SOURCES = $(SRC_APP).cpp $(SRC_LIB).cpp\

OBJ_APP = $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)/$(APP_NAME)
OBJ_LIB = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME)
EXE_PATH = $(BIN_DIR)/$(APP_NAME)
SRC_APP = $(SRC_DIR)/$(APP_NAME)/$(APP_NAME)
SRC_LIB = $(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME)

SRC_EXT = cpp
.PHONY: all
all: $(EXE_PATH).exe

$(EXE_PATH).exe: $(OBJ_APP).o $(OBJ_LIB).o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_LIB).o: $(SRC_APP).cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(OBJ_APP).o: $(SRC_LIB).cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm $(OBJ_APP).o $(OBJ_APP).d 
	rm $(OBJ_LIB).o $(OBJ_LIB).d 
	
	
	