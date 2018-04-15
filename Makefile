CC=g++ -g
CFLAGS=-std=c++11 -c
LDFLAGS=
INCLUDES=-I./src
SOURCES=	\
	src/host.cpp \
	src/console.cpp \
	src/render/render.cpp \
	src/render/Camera.cpp \
	src/scenes.cpp \
	src/input.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=EGGIN

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	ar rc lib$(EXECUTABLE).a $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
