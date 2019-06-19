#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <complex.h>

#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <errno.h>

//compute next term
double complex mandelbrot(double complex z, double complex c)
{
	return (pow(creal(z), 2) - pow(cimag(z), 2)) + (2 * creal(z) * cimag(z)) * I + c;
}

//compute next term
double complex fractal(double complex z, double complex c)
{
	return (pow(creal(z), 4) - 6 * pow(creal(z), 2) * pow(cimag(z), 2) + pow(cimag(z), 4)) + (4 * pow(creal(z), 3) * cimag(z) - 4 * creal(z) * pow(cimag(z), 3)) * I + c;
}

double modulus(double complex z)
{
	return sqrt(pow(creal(z), 2) + pow(cimag(z), 2));
}

int brightness(double complex c)
{
	int iter = 0;
	double complex z = 0;
	for (iter; iter < 21; iter++) {
		if (modulus(z) > 2) break;
		z = fractal(z, c);
	}
	return iter;
}

int main()
{
	int fd, column, row;
	char header[] = "P3 900 900 255\n";
	char line[20];
	int rgb[3];
	double x,y;

	fd = open("squiggle.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	write(fd, header, strlen(header));

	//fractal
	for (row = 0; row < 900; row++) {
		for (column = 0; column < 900; column++) {
			int level = ((int)(255 / 20 * brightness((column / 500. - 1) + ((row / 450. - 1) * I))));
			rgb[0] = rgb[2] = 0;
			rgb[1] = level % 256;
			snprintf(line, sizeof(line), "%d %d %d\n", rgb[0], rgb[1], rgb[2]);
			write(fd, line, strlen(line));
		}
	}

	/*     FIRST ATTEMPT
	for (column = 0; column < 500; column++) {
		for (row = 0; row < 500; row++) {
			rgb[0] = column % 256;
			rgb[1] = row % 256;
			rgb[2] = (column - row) % 256;
			snprintf(line, sizeof(line), "%d %d %d\n", rgb[0], rgb[1], rgb[2]);
			write(fd, line, strlen(line));
		}
	}
	*/

	close(fd);

	return 0;
}
