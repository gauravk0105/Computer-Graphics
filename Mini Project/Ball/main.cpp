

/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Ball Moving

Main file
*/

// header file
#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
#include <math.h>

using namespace std;

// declaring function or constant variable
#define ROUND(x) ((int)(x+0.5))
#define pi 3.14159265359

int xa,xb,ya,yb,r,flag=1;
float tx,ty,x12=0,y12=0,angle=0;
float t=0,t1=0;

// include additional file
#include "first_quadrant.h"
#include "second_quadrant.h"
#include "third_quadrant.h"
#include "fourth_quadrant.h"
#include "Ball.h"

int r1=150;
int x11=0,y11=r1,h=1-r1;		
float x22,y22;
int xvmin,xvmax,yvmax,yvmin;

// draw horizontal line function
void horizontalLine1(void)
{
 	int dx=xb-xa,dy=yb-ya,steps,k;
 	float xIncrement,yIncrement,x=xa,y=ya;
 	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 0.0, 0.0);
 	if(abs(dx)>abs(dy))
 	steps=abs(dx);
 	else steps=abs(dy);
 	xIncrement=dx/(float)steps;
 	yIncrement=dy/(float)steps;
 	glBegin(GL_POINTS);
 	glVertex2s(ROUND(x),ROUND(y));
	for(k=0;k<steps;k++)
 	{
 		x+=xIncrement;
 		y+=yIncrement;
 		glVertex2s(ROUND(x),ROUND(y));
 	}
}

void DDA1()
{
	
}


// init method
void init(string windowName)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,500);  
    int n = windowName.length(); 
    char name[n+1];
    strcpy(name, windowName.c_str()); 
    glutCreateWindow(name);
    glClearColor(0,0,0,0);  
    glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
    glColor3f(0.0f,1.0f,0.0f);   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 	gluOrtho2D(0,1000,0,500);
}

void drawBall()
{
	Ball1();Ball2();Ball3();Ball4();
}

// display rolling ball function
void rollBall()
{
	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 0.0, 0.0);
 	glBegin(GL_POINTS);

	// LEFT PORTION	
	// fixed radius 
 	r=50; 
	// end point 
 	tx=900;ty=150;
 	// right stop
	Quadrant1();	
	Quadrant4();


	// breaker 
	tx=500;ty=100;
 	r=100;
 	// breaker
	Quadrant1();
 	Quadrant2();

    // RIGHT PORTION
	// intial point
	tx=150;ty=150;
	r=50;
	// left stop
	Quadrant2();
	Quadrant3();

	
	// end point cordinate
	xa=150;ya=100;
 	xb=400;yb=100;
	// calling horizontal line function
	// left horizontal line
	horizontalLine1();
 	

	// end point cordinate
	xa=600;ya=100;
 	xb=900;yb=100;
	// calling horizontal lin function 
 	// right horizontal line
	horizontalLine1();

	// draw ball
	tx=150+t;ty=150+t1;
 	//drawing part of ball
	// by quadrant 
	drawBall();
 	
	tx-=t;
 	ty-=t1;


	glEnd();
 	glFlush();
}

void condition1()
{
	        if(t<244)
			{
				x22=t+150+0.5;
				y22=t1+151;
				if((x22-500)*(x22-500) + (y22-100)*(y22-100) -152*151 >=0)
				{
					t++;
				}
				t1++;
			}
			else
			{
				// condition to roll over the obstacle on another side 
				x22=t+151;
				y22=t1+150+0.5;
				if((x22-500)*(x22-500) + (y22-100)*(y22-100) -150*150 <=0)
				{
					
					t1++;
				}
				t++;
			}
}

void condition2()
{
			if(y11>x11)
			{	
				// condition to roll over the obstacle on another side 
				if(h<0)
				{
					h+=2*x11 + 3;
				}
				else
				{
					h+=2*(x11-y11) + 5;
					y11--;
				}
				x11++;
				t=x11 + 500-150;
				t1=y11 +100-150;
			}
			else if(y11>=47&& x11>=y11)
			{
				// stop constarint
				if(h<0)    
				{
					h+=2*(y11) + 3;
				}
				else
				{
					h+=2*(y11-x11) + 5;
					x11++;
				}
				y11--;
					t=x11 + 500-150;
					t1=y11 +100-150;
			}
}

void mainCondition()
{
	   if(t<350)
		{
			//cout << "game" << t << endl;
			// left part of breaker
			// condition to roll over the obstacle
			condition1();
		}
		else
		{
			cout << "game" << t << endl;
			// Right part of breaker
			end:
			condition2();
		}
}

// timer function
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/30,timer,0);
	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 0.0, 0.0);
 	glBegin(GL_POINTS);
	cout << t << endl;
	
	// move ball i.e translation before breaker
	if(t<203)
	{
		t++;
	}
	
	else if(t<493)
	{  
		//cout << "game" << t << endl;
		// at breaker :: as breaker on 100
		// between 204 to 494
		// when ball reached the obstacle  
		mainCondition();
	}
	
	else
	{
		// right of breaker i.e after breaker
		// translate on straight route
		if(t<750)
		{
			//cout << "game" << t << endl;
			t++;
		}
	}
}

// main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
  	string windowName="Ball Rolling";
  	init(windowName);
    glutDisplayFunc(rollBall);
    glutTimerFunc(0,timer,0);
 	glutMainLoop();
 	return 0;
}
