/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Point With Viewport

master file
*/
#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// init
void init(string windowName)
{
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);  
  int n = windowName.length(); 
  char name[n+1];
  strcpy(name, windowName.c_str()); 
  glutCreateWindow(name);
  glClearColor(0,0,1,0);  
  glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
  glColor3f(0.0f,1.0f,0.0f);   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500,500,-500,500);
}

double xs,ys;

// take input
void takeInput()
{
  cout << "\t______Enter Point______\n";
  cout << "xs : ";
  cin >> xs;
  cout << "ys : ";
  cin >> ys;
}

// function to set pixel
void setPixel(double x,double y)
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
        setPixel(0,vertical);

        setPixel(0,-1*vertical);

        vertical++;
    }

    while(horizontal<=500)
    {
        setPixel(horizontal,0);

        setPixel(-1*horizontal,0);

        horizontal++;
    }
}

// pointView Port Algo

void pointViewPort()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );
  drawCoordinateAxis();
  glPointSize(2);
  setPixel(xs,ys);
  
  glFlush();
}

// main Function
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  cout << "\t\t\tChoose\n";
  cout << "\t\t Point Algorithm with View port\n";
  string windowName="";
  takeInput();
  windowName="Point with ViewPort";
  init(windowName);
  glutDisplayFunc(pointViewPort);
  glutMainLoop();
  return 0;
}