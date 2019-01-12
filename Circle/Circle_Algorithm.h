// header file
#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;


double r,h=0,k=0;        // r = radius  , h = x coordinate of center , k = y coordinate of center

// taking input 
void takeCircleInput()
{
    cout << "Enter Radius : ";
    cin >> r;
}

// set pixel of point
void setPixelCircle(double x,double y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

// draw coordinate axis
void drawCoordinateAxis()
{
    double vertical=0;
    double horizontal=0;

    while(vertical<=500)
    {
        setPixelCircle(0,vertical);

        setPixelCircle(0,-1*vertical);

        vertical++;
    }

    while(horizontal<=500)
    {
        setPixelCircle(horizontal,0);

        setPixelCircle(-1*horizontal,0);

        horizontal++;
    }
}

// draw circle
void drawCircle()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT );
    // draw coordinate axis
    drawCoordinateAxis();

    double x = 0;
    double y = r;

    double xprev,yprev;

    double p = 1-r;
    // runing loop till first octant
    while(x<y)
    {
        // setting pixel for each octant by symmetry
        setPixelCircle(x,y);
        setPixelCircle(y,x);
        setPixelCircle(x,-1*y);
        setPixelCircle(-1*y,x);
        setPixelCircle(-1*x,y);
        setPixelCircle(-1*x,-1*y);
        setPixelCircle(-1*y,-1*x);
        setPixelCircle(y,-1*x);
        xprev = x;
        yprev = y;

        x = x+1;
        if(p>=0)
            y = y-1;    // mid point lie outside circle

        p = p + 2*(xprev+1) + (y*y - yprev*yprev) - (y-yprev) + 1;    
    }
    glFlush();
}

