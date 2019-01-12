#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

int i=0;

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
  gluOrtho2D(-780,780,-780,780);
}

double sign(double num)
{
  return num/abs(num);
}

double getRound(double val)
{
  return floor(val+0.5);
}