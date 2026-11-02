CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = projeto_redes_4b
SRC = src/projeto_redes_4b.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean
