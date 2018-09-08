#define _CRT_SECURE_NO_WARNINGS
#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "matrix.h"
#include "qubit.h"
#include "gates.h"
#include "qubit2.h"
#include "gates2.h"

int a = 0, n = 0;
int L = 800;
double alph = 0.4;
int q = 0;
double l = 0;
int x0 = 0;
int Lmax = 225;
double verot = 0;
int y_0 = 0;
#include "gr_operations.h"

int arr1[100];
int arr2[100];

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 100 + l / 2 + verot);
	glVertex2i(1000, 100 + l / 2 + verot);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 600 - l / 2 - verot);
	glVertex2i(1000, 600 - l / 2 - verot);
	glEnd();

	int i;
	for (i = 0; i < q; i++) {
		switch (arr1[i]) {
		case 1:
			operNOT(1, i + 1);
			break;
		case 2:
			operY(1, i + 1);
			break;
		case 5:
			operCNOT(i + 1);
			break;
		case 3:
			operZ(1, i + 1);
			break;
		case 4:
			operH(1, i + 1);
			break;
		default:
			break;
		}

		switch (arr2[i]) {
		case 1:
			operNOT(2, i + 1);
			break;
		case 2:
			operY(2, i + 1);
			break;
		case 3:
			operZ(2, i + 1);
			break;
		case 4:
			operH(2, i + 1);
			break;
		default:
			break;
		}
	}

	glutSwapBuffers();
}

int main(int argc, char * argv[])
{
	comp a, b;
	printf("qbit1: ");
	scanf("%f %f %f %f", &a.x, &a.y, &b.x, &b.y);
	qbit x = mkqbit(a, b);
	printf("qbit2: ");
	scanf("%f %f %f %f", &a.x, &a.y, &b.x, &b.y);
	qbit y = mkqbit(a, b);

	printf("enter number of operations:\n");
	scanf("%d", &q);
	if (q != 0)
	{
		int kkk;
		printf("qubit 1 operations:\n1 - not\n2 - y\n3 - z\n4 - adamar\n5 - cnot\n0 - no operation\n");
		for (kkk = 0; kkk < q; ++kkk) {
			scanf("%d", &arr1[kkk]);
		}
		printf("qubit 2 operations:\n1 - not\n2 - y\n3 - z\n4 - adamar\n5 - cnot\n0 - no operation\n");
		for (kkk = 0; kkk < q; ++kkk) {
			scanf("%d", &arr2[kkk]);
		}
		qbit2 xy = mkqbit2(x, y);
		print2(xy);
		printf("\n");
		for (kkk = 0; kkk < q; ++kkk) {
			xy = gate2(xy, arr1[kkk], arr2[kkk]);
		}
		print2(xy);

		l = L / (q + (q - 1)*alph);
		if (l > Lmax) {
			l = Lmax;
		}
		verot = (500 - 2 * l) / 3;
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(1000, 700);
		glutCreateWindow("Quantum koMpykTep");
		glutReshapeFunc(reshape);
		glutDisplayFunc(display);
		glutMainLoop();
	}
	printf("ERROR!!!!!!\n");
	return 0;
}
