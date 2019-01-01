paint.out: main.o board_struct.o input_val.o 
	gcc -g -Wall -Werror -o paint.out main.o board_struct.o input_val.o
	
board_struct.o: board_struct.c Board.h board_struct.h
	gcc -g -Wall -Werror -c -o board_struct.o board_struct.c
	
main.o: main.c Board.h board_struct.h input_val.h
	gcc -g -Wall -Werror -c -o main.o main.c
	
	
input_val.o: input_val.c Board.h input_val.h
	gcc -g -Wall -Werror -c -o input_val.o input_val.c
	
clean:
	rm -f *.o *.out
