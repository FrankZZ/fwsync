CC=g++
CFLAGS=-w -std=c++11 -c -Wall
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard Commands/*.cpp)
SOURCES+=$(wildcard ../Shared/Models/*.cpp)
SOURCES+=$(wildcard ../Shared/Commands/*.cpp)
SOURCES+=$(wildcard ../Shared/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Release/fwsync-svr

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -Rf $(OBJECTS) $(EXECUTABLE)