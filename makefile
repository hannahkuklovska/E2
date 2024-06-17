#Makefile pre program na výpočet mtej odmocniny
#Hannah Kuklovská
#Emisia 2


CC = gcc
CFLAGS = -Wall -Wextra -pedantic

#Target
TARGET = mat
OBJS = main.o mat.o



#Pravidla vykonania
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET)  $(OBJS)

main.o: mat.c mat.h
	$(CC) $(CFLAGS) -c mat.c -o mat.o

main.o: mat.c mat.h
	$(CC) $(CFLAGS) -c mat.c -o main.o

clean:
	rm -f $(TARGET) $(OBJS)