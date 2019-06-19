#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

#include "time.h"
#include <math.h>

int main()
{
	srand(time(NULL));

	int i;
	double x, y, z;

	screen s;
	color c;

	c.red = 0;
	c.green = MAX_COLOR;
	c.blue = 0;

	clear_screen(s);



	/* for (i = -950; i < 250; i += 50) { */
	/*     draw_line((int)(1. / 125 * (77 * i + 18000)), 288, 750, (int)((750. * i) / (i - 375)), s, c); */
	/* } */

	/*            DRAW GRID LINES         */
	//horizontal lines
	for (double p = 0.05; p < 4; p+=0.05) draw_line(350, (int)(361 - (288 / p)), 750, (int)(361 - (288 / p)), s, c);
	//vertical lines
	for (i = 375; i < 1000; i += 25) {
		if (i > 750) draw_line((int)(1. / 125 * (77 * i + 18000)), 288, 750, (int)((750. * (i - 750)) / (i - 375)), s, c);
		else draw_line((int)(1. / 125 * (77 * i + 18000)), 288, i, 0, s, c);
	}
	c.blue = MAX_COLOR;
	for (i = -230; i < 350; i += 1) {
		int r = (int)rand() % 100;
		c.red = c.green = r;
		if (i < 0) draw_line((int)(1. / 125 * (77 * i + 18000)), 288, 0, (int)((750. * i) / (i - 375)), s, c);
		else draw_line((int)(1. / 125 * (77 * i + 18000)), 288, i, 0, s, c);
	}



	c.red = 0;
	c.green = 0;
	c.blue = 0;

	/*        DRAW SPIRALS       */
	x = y = z = 0;
	double l = 0.1; //controls how compact the spirals are

	//draw galaxy
	for (int i = 0; i < 81; i++) {
		x = 6 * rand() % 100;
		y = 6 * rand() % 100;
		for (int j = 0; j < 81; j++) {
			z = x + l * y;
			y += l * (-x - y);
			x = z;
			c.red = (c.red + (int)rand() % 3) % 256;
			c.green = (c.green + (int)rand() % 3) % 256;
			c.blue = (c.blue + (int)rand() % 3) % 256;
			plot(s, c, (int)x + 130, (int)y / 2 + 680);
		}
	}

	c.red = 150;
	c.green = MAX_COLOR;
	c.blue = MAX_COLOR;

	x = y = z = 0;
	l = 0.7; //controls how compact the spirals are

	//draw galaxy
	for (int i = 0; i < 81; i++) {
		x = 6 * rand() % 100;
		y = 6 * rand() % 100;
		for (int j = 0; j < 81; j++) {
			z = x + l * y;
			y += l * (-x - y);
			x = z;
			plot(s, c, (int)x + 150, (int)y / 2 + 370);
		}
	}

	x = y = z = 0;
	l = 0.4; //controls how compact the spirals are

	//draw galaxy
	for (int i = 0; i < 81; i++) {
		x = 6 * rand() % 100;
		y = 6 * rand() % 100;
		for (int j = 0; j < 81; j++) {
			z = x + l * y;
			y += l * (-x - y);
			x = z;
			c.red = (int)rand() % 256;
			c.green = (int)rand() % 256;
			c.blue = (int)rand() % 256;
			plot(s, c, (int)x + 300, (int)y / 2 + 500);
		}
	}

	x = y = z = 0;
	l = 0.4; //controls how compact the spirals are

	c.red = MAX_COLOR;
	c.green = MAX_COLOR;
	c.blue = 0;

	//draw galaxy
	for (int i = 0; i < 81; i++) {
		x = 6 * rand() % 100;
		y = 6 * rand() % 100;
		for (int j = 0; j < 81; j++) {
			z = x + l * y;
			y += l * (-x - y);
			x = z;
			plot(s, c, (int)x + 600, (int)y / 2 + 670);
		}
	}



	/*     DRAW STARS     */

	c.red = MAX_COLOR;
	c.green = 165;
	c.blue = 0;

	for (i = 75; i > 0; i--) {
		draw_circle(600, 400, i, s, c);
		c.green += 2;
		c.blue += 2;
	}

	c.red = MAX_COLOR;
	c.green = 0;
	c.blue = 0;

	for (i = 50; i > 0; i--) {
		draw_circle(100, 500, i, s, c);
		c.green += 5;
		c.blue += 5;
	}

	c.red = 100;
	c.green = 100;
	c.blue = 100;

	for (i = 50; i > 0; i--) {
		draw_circle(400, 600, i, s, c);
		c.red += 3;
		c.green += 3;
		c.blue += 3;
	}



	/*     int f = 5; //spacing between points */
	/* int n = 55; //! of points */
	/* int g = 100; //range of gravity */

	/* double t = 5000; */

	/* x = 500 * sin(t); */
	/* y = 500 * cos(t); */

	/* for (i = 0; i < n; i++) { */
	/*     for (j = 0; j < n; j++) { */
	/*         int x2 = (f * i + f / 2 - f * n / 2); */
	/*         int y2 = (f * i + f / 2 - f * n / 2); */

	/*         double dist = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2)); */
	/*         dist = dist > g ? 0 : tan(((g - dist) / g) * M_PI  / 2) * (-g / 40); */

	/*         x = abs((int)x); */
	/*         y = abs((int)y); */

	/*         plot(s, c, x, y); */

	/*         draw_line(x, y, x, j + n * i, s, c); */
	/*         draw_line(x, y, j + n * i, y, s, c); */
	/*     } */
	/* } */

	/*
	//basic image showing line algo is working
	for (i = 0; i < 501; i += 50)
	draw_line(i, 0, i, 500, s, c);
	for (i = 0; i < 501; i += 50)
	draw_line(0, i, 500, i, s, c);
	draw_line(0, 500, 500, 0, s, c);
	draw_line(0, 500, 400, 0, s, c);
	draw_line(0, 500, 500, 100, s, c);
	draw_line(500, 500, 0, 0, s, c);
	draw_line(500, 500, 0, 100, s, c);
	draw_line(500, 500, 100, 0, s, c);*/

	display(s);
	save_extension(s, "lines.png");

	return 0;
}
