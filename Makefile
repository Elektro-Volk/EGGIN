CC=g++ -g
CFLAGS=-std=c++11 -c
LDFLAGS=
INCLUDES=
SOURCES=	\
	src/host.cpp \
	src/console.cpp \
	src/render/render.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=EGGIN

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	ar rc lib$(EXECUTABLE).a $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
