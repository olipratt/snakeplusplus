# MAke file for Snake.

#OBJS specifies which files to compile as part of the project
SNAKE_OBJS = main.cpp

TEST_OBJS = unit_test_main.cpp \
			snake.cpp \
			test_snake.cpp \
			location_source.cpp

#CC specifies which compiler we're using
CC = D:\Programs\mingw\bin\g++.exe

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -ID:\Programs\SDL\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\include\SDL2 \
                -ID:\Programming\C++\snake

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LD:\Programs\SDL\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wall -Wl,-subsystem,windows -std=c++11 -Wno-unknown-pragmas

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
SNAKE_OBJ_NAME = snake
TEST_OBJ_NAME = unit_tests

#This is the target that compiles our executable
snake : $(SNAKE_OBJS)
	$(CC) $(SNAKE_OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) \
	$(LINKER_FLAGS) -o $(SNAKE_OBJ_NAME)


unit_tests : $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) \
	$(LINKER_FLAGS) -o $(TEST_OBJ_NAME)

