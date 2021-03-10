all: exServerSocket exClientSocket sin_nombre

exServerSocket: exServerSocket.c socketMng.o
	gcc -o exServerSocket exServerSocket.c socketMng.o

exClientSocket: exClientSocket.c socketMng.o
	gcc -o exClientSocket exClientSocket.c socketMng.o

socketMng.o: socketMng.c
	gcc -c socketMng.c

sin_nombre: sin_nombre.c
	gcc -o sin_nombre sin_nombre.c

clean: 
	rm -f exServerSocket exClientSocket socketMng.o sin_nombre
