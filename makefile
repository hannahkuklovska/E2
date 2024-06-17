
#Hannah Kuklovská
#Emisia 2


CC = gcc
CFLAGS = -Wall -Wextra -pedantic

#Target
TARGET = main
OBJS = main.o mat.o



#Pravidla vykonania
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)  

main.o: main.c mat.h
	$(CC) $(CFLAGS) -c main.c

mat.o: mat.c mat.h
	$(CC) $(CFLAGS) -c mat.c 

clean:
	rm -f $(TARGET) $(OBJS)