CC = g++
CFLAGS = -Wall -Wextra
TARGET = add-nbo
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = main.h

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

run:
		./$(TARGET)

clean:
		rm -f $(OBJS) $(TARGET)
