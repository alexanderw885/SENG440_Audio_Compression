test:
	gcc -mfpu=neon test_cases.c muLaw.c -o test
clean:
	rm test