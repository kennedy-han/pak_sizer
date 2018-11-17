CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=pak_sizer.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pak_sizer

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

