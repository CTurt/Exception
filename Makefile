sample: sample.c exception.c
	gcc sample.c exception.c -o sample -O2 -Wall

clean:
	@rm -f sample
	@rm -f sample.exe
