CC=g++ -g
CFLAGS=-std=c++11 -fPIC
LDFLAGS=-L../../ -lEGGIN -ldl
INCLUDES=-I../../src
SOURCES=	\
	main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=GAME

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS)  $(LDFLAGS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
