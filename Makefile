# Compiling settings

# Compiler used
CC = gcc

# Define flags
FLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

# Compile this file
CODENAME = 'xml-interface.c'

compile:
	echo "Compiling..."
	$(CC) $(FLAGS) -o ./gtk\ -\ Hello\ World/app ./gtk\ -\ Hello\ World/$(CODENAME) $(LIBS)
	echo "Sucessfully compiled! :D"

clean:
	echo "Removing last compilings"
	rm *.o ./gtk\ -\ Hello\ World/app

execute:
	echo "Executing application"
	./gtk\ -\ Hello\ World/app

compileandexec:
	# Compile and executes the app
	$(MAKE) compile

	echo "Executing application"
	./gtk\ -\ Hello\ World/app

