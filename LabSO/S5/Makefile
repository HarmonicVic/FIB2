all: mem1_dynamic mem1_static

mem1_dynamic: mem1.c
	gcc -o mem1_dynamic mem1.c

mem1_static: mem1.c
	gcc -static -o mem1_static mem1.c

clean:
	rm -f *.o mem1_dynamic mem1_static