test: test_cases.c muLaw.h
	gcc -mfpu=neon test_cases.c -o test

clean:
	rm -f *.o test