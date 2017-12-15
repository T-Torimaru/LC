# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all : gain_all

gain_all: Gain_Mean.cpp
	$(CC) -o gain_mean Gain_Mean.cpp $(shell root-config --glibs --cflags)

clean:
	rm -rf gain_mean
