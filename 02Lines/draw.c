#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c)
{
	//swap values if necessary
	if (x0 > x1) {
		int temp = x1;
		x1 = x0;
		x0 = temp;

		temp = y1;
		y1 = y0;
		y0 = temp;
	}

	int x = x0;
	int y = y0;
	int a = y1 - y0;
	int b = - (x1 - x0);

	double slope = (double)a / -b;

	if (slope >= 0 && slope <= 1) {
		int d = 2 * a + b;
		while (x <= x1) {
			plot(s, c, x, y);
			if (d > 0) {
				y++;
				d += 2 * b;
			}
			x++;
			d += 2 * a;
		}
	} else if (slope > 1) {
		int d = a + 2 * b;
		while (y <= y1) {
			plot(s, c, x, y);
			if (d < 0) {
				x++;
				d += 2 * a;
			}
			y++;
			d += 2 * b;
		}
	} else if (slope < -1) {
		int d = a - 2 * b;
		while (y >= y1) {
			plot(s, c, x, y);
			if (d > 0) {
				x++;
				d += 2 * a;
			}
			y--;
			d -= 2 * b;
		}
	} else if (slope >= -1) {
		int d = 2 * a - b;
		while (x <= x1) {
			plot(s, c, x, y);
			if (d < 0) {
				y--;
				d -= 2 * b;
			}
			x++;
			d += 2 * a;
		}
	}
}

void draw_circle(int x0, int y0, int radius, screen s, color c)
{
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y) {
		plot(s, c, x0 + x, y0 + y);
		plot(s, c, x0 + y, y0 + x);
		plot(s, c, x0 - y, y0 + x);
		plot(s, c, x0 - x, y0 + y);
		plot(s, c, x0 - x, y0 - y);
		plot(s, c, x0 - y, y0 - x);
		plot(s, c, x0 + y, y0 - x);
		plot(s, c, x0 + x, y0 - y);

		if (err <= 0) {
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0) {
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}
