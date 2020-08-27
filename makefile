OBJ = switcherbox.o bitaux.o validators.o

switcherbox: $(OBJ)
	gcc $(OBJ) -o switcherbox

bitaux.o: bitaux.h bitaux.c
	gcc -c bitaux.c

validators.o: validators.h validators.c
	gcc -c validators.c

clean:
	rm *.o switcherbox
