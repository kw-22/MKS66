#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#include <math.h>

int main()
{
	screen s;
	struct matrix *edges, *edges2, *identity;

	edges = new_matrix(4, 4);
	edges2 = new_matrix(4, 2);
	identity = new_matrix(4, 4);
	edges->lastcol = 4;
	edges2->lastcol = 2;
	identity->lastcol = 4;

	printf("===================\nEMPTY EDGES MATRIX\n===================\n");
	print_matrix(edges);
	printf("===================\nIDENTITY MATRIX\n===================\n");
	ident(identity);
	print_matrix(identity);

	printf("===================\nMULTIPLYING IDENTITY TO ITSELF\n===================\n");
	matrix_mult(identity, identity);
	print_matrix(identity);

	printf("===================\nPOPULATING EDGES MATRIX\n===================\n");
	int row, col;
	for(row = 0; row < edges->rows; row++)
		for(col = 0; col < edges->cols; col++) {
			edges->m[row][col] = row + col;
			if (col <= 1) edges2->m[row][col] = row + col;
		}
	print_matrix(edges);

	printf("===================\nMULTIPLYING IDENTITY TO EDGES\n===================\n");
	matrix_mult(identity, edges);
	printf("===================\nEDGES MATRIX\n===================\n");
	print_matrix(edges);
	printf("===================\nIDENTITY MATRIX\n===================\n");
	print_matrix(identity);

	printf("===================\nMULTIPLYING EDGES TO IDENTITY\n===================\n");
	matrix_mult(edges, identity);
	printf("===================\nEDGES MATRIX\n===================\n");
	print_matrix(edges);
	printf("===================\nIDENTITY MATRIX\n===================\n");
	print_matrix(identity);

	printf("===================\nMULTIPLYING EDGES TO EDGES2\n===================\n");
	printf("===================\nEDGES2 MATRIX\n===================\n");
	print_matrix(edges2);
	matrix_mult(edges, edges2);
	printf("===================\nEDGES MATRIX\n===================\n");
	print_matrix(edges);
	printf("===================\nEDGES2 MATRIX\n===================\n");
	print_matrix(edges2);

	printf("*******************\nPOINTS AND EDGES STUFF\n*******************\n");
	printf("===================\nADDING (1, 2, 3), (4, 5, 6)\n*******************\n");
	add_edge(edges, 1, 2, 3, 4, 5, 6);
	print_matrix(edges);
	free_matrix(edges);



	clear_screen(s);
	color c;
	c.green = MAX_COLOR;

	struct matrix *translate_m, *scale_m, *rotate_m, *shear_x, *shear_y;
	translate_m = new_matrix(4, 4);
	scale_m = new_matrix(4, 4);
	rotate_m = new_matrix(4, 4);
	shear_x = new_matrix(4, 4);
	shear_y = new_matrix(4, 4);

	translate_m->lastcol = 4;
	scale_m->lastcol = 4;
	rotate_m->lastcol = 4;
	shear_x->lastcol = 4;
	shear_y->lastcol = 4;

	translate_m->m[0][0] = 1;
	translate_m->m[0][2] = 200; //200 units right
	translate_m->m[1][1] = 1;
	translate_m->m[1][2] = 500; //500 units up
	translate_m->m[2][2] = 1;

	scale_m->m[0][0] = 0.3; //scale width by 0.3
	scale_m->m[1][1] = 0.3; //scale height by 0.3
	scale_m->m[2][2] = 1;

	rotate_m->m[0][0] = cos(M_PI); //rotate 180 degress
	rotate_m->m[0][1] = sin(M_PI);
	rotate_m->m[1][0] = -sin(M_PI);
	rotate_m->m[1][1] = cos(M_PI);
	rotate_m->m[2][2] = 1;

	shear_x->m[0][0] = 1;
	shear_x->m[0][1] = tan(M_PI / 6);
	shear_x->m[1][1] = 1;
	shear_x->m[2][2] = 1;

	shear_y->m[0][0] = 1;
	shear_y->m[1][0] = tan(M_PI / 18);
	shear_y->m[1][1] = 1;
	shear_y->m[2][2] = 1;

	edges = new_matrix(4, 0);
	add_edge(edges, 150, 200, 1, 150, 500, 1);
	add_edge(edges, 150, 200, 1, 175, 200, 1);
	add_edge(edges, 150, 500, 1, 120, 500, 1);
	add_edge(edges, 120, 500, 1, 120, 530, 1);
	add_edge(edges, 120, 530, 1, 260, 530, 1);
	add_edge(edges, 260, 530, 1, 260, 500, 1);
	add_edge(edges, 260, 500, 1, 230, 500, 1);
	add_edge(edges, 230, 500, 1, 230, 370, 1);
	add_edge(edges, 175, 200, 1, 475, 500, 1);
	add_edge(edges, 230, 375, 1, 355, 500, 1);
	add_edge(edges, 355, 500, 1, 325, 500, 1);
	add_edge(edges, 325, 500, 1, 325, 530, 1);
	add_edge(edges, 325, 530, 1, 475, 530, 1);
	add_edge(edges, 475, 530, 1, 475, 500, 1);
	add_edge(edges, 270, 280, 1, 250, 280, 1);
	add_edge(edges, 250, 200, 1, 270, 280, 1);
	add_edge(edges, 250, 280, 1, 255, 290, 1);
	add_edge(edges, 255, 290, 1, 290, 290, 1);
	add_edge(edges, 290, 290, 1, 270, 210, 1);
	add_edge(edges, 270, 210, 1, 290, 210, 1);
	add_edge(edges, 290, 210, 1, 285, 200, 1);
	add_edge(edges, 285, 200, 1, 250, 200, 1);
	add_edge(edges, 285, 300, 1, 290, 320, 1);
	add_edge(edges, 260, 300, 1, 285, 300, 1);
	add_edge(edges, 290, 320, 1, 265, 320, 1);
	add_edge(edges, 265, 320, 1, 260, 300, 1);
	add_edge(edges, 320, 200, 1, 330, 290, 1);
	add_edge(edges, 330, 290, 1, 450, 290, 1);
	add_edge(edges, 450, 290, 1, 440, 200, 1);
	add_edge(edges, 343, 200, 1, 350, 260, 1);
	add_edge(edges, 320, 200, 1, 343, 200, 1);
	add_edge(edges, 440, 200, 1, 417, 200, 1);
	add_edge(edges, 417, 200, 1, 423, 260, 1);
	add_edge(edges, 350, 260, 1, 372, 260, 1);
	add_edge(edges, 423, 260, 1, 398, 260, 1);
	add_edge(edges, 398, 260, 1, 393, 200, 1);
	add_edge(edges, 372, 260, 1, 367, 200, 1);
	add_edge(edges, 367, 200, 1, 393, 200, 1);
	draw_lines(edges, s, c);

	matrix_mult(scale_m, edges);
	matrix_mult(shear_x, edges);
	draw_lines(edges, s, c);
	matrix_mult(translate_m, edges);
	matrix_mult(shear_y, edges);
	draw_lines(edges, s, c);
	matrix_mult(rotate_m, edges);
	draw_lines(edges, s, c);
	translate_m->m[0][2] = 800;
	translate_m->m[1][1] = 1;
	translate_m->m[1][2] = 800;
	matrix_mult(translate_m, edges);
	matrix_mult(shear_x, edges);
	draw_lines(edges, s, c);

	free_matrix(edges);
	free_matrix(edges2);
	free_matrix(identity);

	free_matrix(translate_m);
	free_matrix(scale_m);
	free_matrix(rotate_m);
	free_matrix(shear_x);
	free_matrix(shear_y);

	display(s);
	save_extension(s, "matrix.png");
}
