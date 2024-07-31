CC=gcc
CC_flags = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: build/main

build:
	mkdir -p build

build/main: build
	$(CC) -o build/main src/main.c $(CC_flags)

clean:
	rm -rf build