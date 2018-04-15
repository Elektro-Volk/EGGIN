CC=g++ -g
CFLAGS=-std=c++11 -c
LDFLAGS= -lSDL2 -lGL -pthread -ldl -lGLU -lglut
INCLUDES=
SOURCES=	\
	src/host.cpp \
	src/console.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=EGGIN

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	ar rc lib$(EXECUTABLE).a $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
