CC=g++
RM:=rm -rf

all: threshold_scan createDummyMip

threshold_scan : threshold_scan.cpp
	$(CC)  threshold_scan.cpp -o threshold_scan `root-config --cflags --glibs`

createDummyMip : createDummyMip.cpp
	$(CC)  createDummyMip.cpp -o  createDummyMip `root-config --cflags --glibs`

clean:
	$(RM) threshold_scan createDummyMip


