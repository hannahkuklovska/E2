#Makefile pre program na výpočet mtej odmocniny
#Hannah Kuklovská
#Emisia 2


CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Source files
MATICOVA_ROVNICA_SOURCE = maticova_rovnica.c

# Executables

MATICOVA_ROVNICA_OUTPUT = maticova_rovnica

all: $(MATICOVA_ROVNICA_OUTPUT) 

$(MATICOVA_ROVNICA_OUTPUT) : $(MATICOVA_ROVNICA_SOURCE)
	$(CC) $(CFLAGS) -o $(MATICOVA_ROVNICA_OUTPUT)  $(MATICOVA_ROVNICA_SOURCE)



clean:
	rm -f $(MATICOVA_ROVNICA_OUTPUT)