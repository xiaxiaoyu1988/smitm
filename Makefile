CC = g++
INCLUDES = -I ./lib -I ./lib/libevent -I ./src -I ./src/XPub -I ./src/XConfig -I ./src/XHttpClient -I ./src/XLog 
LIBS = -L ./lib -lpthread
SRCS=$(wildcard ./src/*.cpp ./src/*/*.cpp) ./lib/*/*.a

all: smitm

smitm: $(SRCS)
	$(CC) -o ./bin/$@ $^ $(INCLUDES) $(LIBS)
