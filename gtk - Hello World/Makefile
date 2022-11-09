# Compiling settings

# Method 1

# final:
# 	gcc $( pkg-config --cflags gtk4 ) -o main main.c $( pkg-config --libs gtk4 )

# Method 2

CC = gcc
FLAG1 = $( pkg-config --cflags gtk4 )
FLAG2 = $( pkg-config --libs gtk4 )
final:
	$(CC) $(FLAG1) -o app main.c $(FLAG2)

Clean:
	rm *.o app