CC = g++
INCLUDES = -I ./src -I ./src/XPub -I ./src/XConfig
LIBS = -I ./lib
SRCS=$(wildcard ./src/*.cpp ./src/*/*.cpp)

all: smitm

smitm: $(SRCS)
	$(CC) -o ./bin/$@ $^ $(INCLUDES) $(LIBS)
