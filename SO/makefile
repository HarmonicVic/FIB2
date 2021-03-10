all: fifo_to_exec.v print_things.v read_file.v test.v alarms.v lseek_file.v

fifo_to_exec.v: fifo_to_exec.c
	gcc -o fifo_to_exec.v fifo_to_exec.c

print_things.v: print_things.c
	gcc -o print_things.v print_things.c

read_file.v: read_file.c	
	gcc -o read_file.v read_file.c

test.v: test.c
	gcc -o test.v test.c

alarms.v: alarms.c
	gcc -o alarms.v alarms.c

lseek_file.v: lseek_file.c
	gcc -o lseek_file.v lseek_file.c

clean:
	rm -f *.v