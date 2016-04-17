# Snake++

An exercise to learn C++ and SDL2 by implementing a simple game of snake in a test-driven way.

## Setup

- You'll need `make` and a recent `g++` - the 'MinGW' versions work fine on Windows.

That's all you need to build and run the unit tests, but to build and run the actual game, you also need to:

- Download and unpack SDL2 - I recommend following the tutorial here which covers various operating systems and development environments rather than me half-assedly repeating them here: [Lazy Foo](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php).

## Building

Make sure that `make` and `g++` are on your path.

On Windows I run:

```
set path=%path%;D:\Programs\mingw\bin
```

Now from the root directory of the repository run `make`:

```
mingw32-make.exe SDLLIB=D:\Programs\SDL\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\lib SDLINC=D:\Programs\SDL\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\include\SDL2
```

Obviously substituting for your relevant include / lib directories and make command (plain old `make` on Linux). You can make those extra variables environment variables so you don't have to specify them every time.

## Running

Make sure that the SDL shared libraries are on your path, plus any other standard system libraries.

On Windows I run:

```
set path=%path%;D:\Programs\mingw\bin;D:\Programs\SDL\SDL2-devel-2.0.4-mingw\SDL2-2.0.4\i686-w64-mingw32\bin
```

Finally just run the snake program with `snake.exe` / `./snake`.

## Building and running the tests

The unit tests use the [Catch](https://github.com/philsquared/Catch) framework.

The unit tests have no dependence on any graphics libraries so can just be built and run with:

```
mingw32-make unit_tests
unit_tests.exe
```

Or

```
make unit_tests
./unit_tests
```

## Todo

- I've started trying to make the Makefile OS agnostic, but it's not done.
- Also try running on other OSs (also Android?)
- Add an intro menu screen that you are returned to on game over.
- Improve the makefile so it only re
