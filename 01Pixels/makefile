all: picmaker.c
	gcc -o pic picmaker.c -lm
	./pic

clean:
	shred -u *.ppm
	shred -u ./pic
