SOURCE = $(wildcard *.cpp)
OBJS = $(SOURCE:.cpp=.o)
HEADER = $(wildcard *.h)
SHADERS = $(wildcard *.glsl)
OUT = pixel
ZIP = 3DOpenGLHW.zip
CC = g++
CFLAGS = -ggdb -Wall -std=c99
LFLAGS = -lm -lGL -lGLU -lglut -lGLEW
all: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(OUT) $(LFLAGS)

clean:
		rm -f $(OBJS) $(OUT) $(ZIP) $(DAT)

zip:
		zip $(ZIP) $(HEADER) $(SOURCE) $(SHADERS) Makefile 
