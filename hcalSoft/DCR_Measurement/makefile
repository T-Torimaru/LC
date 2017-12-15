CC=g++

FLAGS=$(shell root-config --glibs --cflags)

all : noise

noise : noise_measurement.cpp
	$(CC) noise_measurement.cpp -o noise_measurement $(FLAGS)

clean :
	rm noise_measurement
