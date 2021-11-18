TARGET = main
EXENAME = main
DEPS = main.o Graph.o Vertex.o

CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
OBJS = $(TARGET).o
LIBS = 

all: $(TARGET)

install: $(TARGET) clean

$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $(EXENAME) $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
