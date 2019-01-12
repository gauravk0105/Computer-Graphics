/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Point Without Viewport

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
  // logic for window to view port
  gluOrtho2D(0,500,0,500);
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

// set pixel

void setPixel(double x,double y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


// conversion of window to viewport

void pointwithoutViewPort()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );
  glPointSize(2);  
  setPixel(xs,ys);
  glFlush();
}

// Main Function
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  cout << "\t\t\tChoose\n";
  cout << "\t\t Point Algorithm without View port\n";
  string windowName="";
  takeInput();
  windowName="Point Without View Port";
  init(windowName);
  glutDisplayFunc(pointwithoutViewPort);
  glutMainLoop();
  return 0;
}