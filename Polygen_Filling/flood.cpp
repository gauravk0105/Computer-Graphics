#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;


// structure for Point
struct Point {
	GLint x;
	GLint y;
};

// structure for Color
struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

// draw line
void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
}

// init method
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

// get Pixel Color 
Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

// setting pixel color
void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}

// main algo of flood fill
void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		// recursive algo to plot color on pixle
		setPixelColor(x, y, newColor);
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	return;
}

// on click event
void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};
	// call flood fill
	floodFill(300, 100, oldColor, newColor);
}

// display call
void display(void) {
	Point p1 = {100, 100}, // bottom-right
		p2 = {200,50}, // bottom-left
		p3 = {400, 50}, // top-right
		p4 = {300, 200},
		p21 = {400,50}, // bottom-left
		p31 = {600, 50}, // top-right
		p41 = {500, 200}; // top-left
		
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		// triangle
		draw_dda(p2,p3);
		draw_dda(p3,p4);
		draw_dda(p4,p2);
	glEnd();
	glFlush();
}

// main method
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}