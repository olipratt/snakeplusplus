# Make file for Snake.
#
# Requires the following variables in the environment or passed at the command
# line:
# $(SDLLIB) - The path to the SDL libraries for your system type, e.g.
#             <basedir>\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\lib
# $(SDLINC) - The path to the SDL include headers for your system type, e.g.
#     <basedir>\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\include\SDL2

#OBJS specifies which files to compile as part of the project
COMMON_OBJS = snake.cpp \
			snake_scene.cpp \
			location_source.cpp

SNAKE_OBJS = $(COMMON_OBJS) \
			main.cpp \
			main_loop.cpp \
			sdlrenderapi.cpp \
			window.cpp

TEST_OBJS = $(COMMON_OBJS) \
			test/unit_test_main.cpp \
			test/test_snake.cpp \
			test/test_snake_scene.cpp \
			test/test_scene_common.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I.
SNAKE_INCLUDE_PATHS = $(INCLUDE_PATHS) -I$(SDLINC)
TEST_INCLUDE_PATHS = $(INCLUDE_PATHS) -Itest

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS =
SNAKE_LIBRARY_PATHS = $(LIBRARY_PATHS) -L$(SDLLIB)

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -std=c++11 -Wno-unknown-pragmas -Og
# -Wl,-subsystem,windows gets rid of the console window
SNAKE_COMPILER_FLAGS = $(COMPILER_FLAGS) -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32
SNAKE_LINKER_FLAGS = $(LINKER_FLAGS) -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
SNAKE_OBJ_NAME = snake
TEST_OBJ_NAME = unit_tests

#This is the target that compiles our executable
snake : $(SNAKE_OBJS)
	$(CC) $(SNAKE_OBJS) $(SNAKE_INCLUDE_PATHS) $(SNAKE_LIBRARY_PATHS) \
	$(SNAKE_COMPILER_FLAGS)	$(SNAKE_LINKER_FLAGS) -o $(SNAKE_OBJ_NAME)

unit_tests : $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(TEST_INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) \
	$(LINKER_FLAGS) -o $(TEST_OBJ_NAME)

.DEFAULT_GOAL := snake
