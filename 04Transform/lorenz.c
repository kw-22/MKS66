#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>

int main()
{
	umask(0020);
	int f = open("mine", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	double x = 0.1;
	double y = 0.1;
	double z = 0.1;
	double dt = 0.001;

	double s = 10., r = 28., b = 8. / 3;
	double dx, dy, dz;

	for (int t = 0; t < 50000; t++) {
		char text[256];
		dx = s * (y - x);
		dy = x * (r - z) - y;
		dz = x * y - b * z;
		x += dt * dx;
		y += dt * dy;
		z += dt * dz;
		sprintf(text, "line\n%d %d %d %d %d %d\n",
				(int)(10 * x) + 200,
				(int)(10 * y) + 200,
				(int)(10 * z) + 200,
				(int)(10 * (x + dt * dx)) + 200,
				(int)(10 * (y + dt * dy)) + 200,
				(int)(10 * (z + dt * dz)) + 200);
		write(f, text, strlen(text));
	}
	write(f,"ident\n", 6);
	write(f,"rotate\n", 7);
	write(f,"x 110\n", 6);
	write(f, "apply\n", 6);
	write(f,"ident\n", 6);
	write(f,"move\n", 5);
	write(f,"0 500 0\n", 8);
	write(f, "apply\n", 6);
	write(f,"ident\n", 6);
	write(f,"rotate\n", 7);
	write(f,"z 160\n", 6);
	write(f, "apply\n", 6);
	write(f,"ident\n", 6);
	write(f,"move\n", 5);
	write(f,"500 320 0\n", 10);
	write(f, "apply\n", 6);
	write(f,"display\n", 8);
	write(f,"save\n", 5);
	write(f,"pic.png\n", 8);

	return 0;
}
