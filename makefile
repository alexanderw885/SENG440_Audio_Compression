test: test_cases.o muLaw.o
	gcc -mfpu=neon test_cases.o muLaw.o -o test

muLaw.o: muLaw.h muLaw.c
	gcc -mfpu=neon -c muLaw.c -o muLaw.o

test_cases.o: test_cases.c muLaw.h
	gcc -mfpu=neon -c test_cases.c -o test_cases.o

clean:
	rm -f *.o test