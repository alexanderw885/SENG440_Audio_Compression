test:
	gcc -mfpu=neon test_cases.c mulaw_neon.c -o test
clean:
	rm test