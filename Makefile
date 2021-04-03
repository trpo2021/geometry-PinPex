  
APP_NAME = geometry
LIB_NAME = libgeometry

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Isrc -MP -MMD 
CCFLAGS = -Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter -O3

LDFLAGS =
LDLIBS =

CC = g++
CXX=clang++
CL=clang

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.cpp')
LIB_OBJECTS = $(find $(SRC_DIR)/$(LIB_NAME) -name '*.cpp':$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
APP_PATH = $(BIN_DIR)/$(APP_NAME)

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.cpp')
APP_OBJECTS = $(find $(SRC_DIR)/$(LIB_NAME) -name '*.cpp':$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)


OBJ_APP = $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)
OBJ_LIB = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)
EXE_PATH = $(BIN_DIR)/$(APP_NAME)
SRC_APP = $(SRC_DIR)/$(APP_NAME)
SRC_LIB = $(SRC_DIR)/$(LIB_NAME)

FIND_LIB = $(shell find $(SRC_LIB) -name '*.cpp')

SRC_EXT = cpp


.PHONY: all
all: $(EXE_PATH).exe

$(EXE_PATH).exe: $(OBJ_APP)/$(APP_NAME).o $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJ_APP)/$(APP_NAME).o: $(SRC_APP)/$(APP_NAME).cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<


	


	
	
$(LIB_PATH): $(OBJ_LIB)/Find.o $(OBJ_LIB)/Calc.o $(OBJ_LIB)/libgeometry.o $(OBJ_LIB)/Input.o $(OBJ_LIB)/output.o $(OBJ_LIB)/CheckIntersection.o
	ar rcs $@ $^


	
	
$(OBJ_LIB)/Find.o: $(SRC_LIB)/Find.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
$(OBJ_LIB)/Calc.o: $(SRC_LIB)/Calc.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<	
$(OBJ_LIB)/libgeometry.o: $(SRC_LIB)/libgeometry.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
$(OBJ_LIB)/Input.o: $(SRC_LIB)/Input.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
$(OBJ_LIB)/output.o: $(SRC_LIB)/output.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
$(OBJ_LIB)/CheckIntersection.o: $(SRC_LIB)/CheckIntersection.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: test

test: bin/test.exe

bin/test.exe: obj/test/main.cpp.o obj/test/test.cpp.o $(LIB_PATH)
	$(CC) -Isrc -Ithirdparty -MP -MMD  obj/test/main.cpp.o obj/test/test.cpp.o $(LIB_PATH) -o bin/test.exe

obj/test/test.cpp.o: test/test.cpp thirdparty/ctest.h
	$(CC) -Isrc -Ithirdparty -MP -MMD  -c -o $@ $<

obj/test/main.cpp.o: test/main.cpp thirdparty/ctest.h
	$(CC) -Isrc -Ithirdparty -MP -MMD  -c -o $@ $<


.PHONY: clean
OBJ_TEST = obj/test

clean:
	find $(OBJ_APP) -name "*.o" -type f -delete
	find $(OBJ_APP) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.o" -type f -delete
	find $(OBJ_LIB) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.a" -type f -delete
	find $(OBJ_TEST) -name "*.o" -type f -delete
	find $(OBJ_TEST) -name "*.d" -type f -delete
	find $(OBJ_TEST) -name "*.o" -type f -delete
	find $(OBJ_TEST) -name "*.d" -type f -delete
	find $(OBJ_TEST) -name "*.a" -type f -delete
