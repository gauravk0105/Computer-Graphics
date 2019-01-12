// Header file

#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// init function
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

// signum function
double signMidPoint(double num)
{
  return num/abs(num);
}

// set pixel
void setPixelMID(double x,double y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

// draw coordinate axiss

void drawCoordinateAxisMid()
{
    double vertical=0;
    double horizontal=0;

    while(vertical<=780)
    {
        setPixelMID(0,vertical);

        setPixelMID(0,-1*vertical);

        vertical++;
    }

    while(horizontal<=780)
    {
        setPixelMID(horizontal,0);

        setPixelMID(-1*horizontal,0);

        horizontal++;
    }
}


// mid point line drawing algo
void midPointAlgorithm(double xs,double ys,double xe,double ye)
{
  double sw;  

  double x = xs;
  double y = ys;

  double dx = abs(xe-xs);
  double dy = abs(ye-ys);

  double s1 = signMidPoint(xe-xs);
  double s2 = signMidPoint(ye-ys);  


  if(dy>dx)  
  {
    swap(dx,dy);
    sw=1;
  }
  else
    sw=0;

  double n=1;
  double p = 2*dy-dx;

  setPixelMID(x,y);  

  while(n<=dx)  
  {
    if(p>=0)
    {
        x=x+s1;
        y=y+s2;
        p=p+2*(dy-dx);
    }
    else
    {
        if(sw==1)
            y=y+s2;
        else
            x=x+s1;
        p=p+2*dy;    
    }
    setPixelMID(x,y);
    n++;
  }
}

// draw polygen
void polygonDrawing()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT );

    //drawCoordinateAxisMid();

    midPointAlgorithm(-1*150,0,150,300);

    midPointAlgorithm(300-150,300,600-150,300);

    midPointAlgorithm(300-150,0,600-150,300);

    midPointAlgorithm(300-150,0,600-150,-1*300);

    midPointAlgorithm(300-150,-1*300,600-150,-1*300);

    midPointAlgorithm(0-150,0,300-150,-1*300);

    glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="";
  windowName="Polygon";
  init(windowName);
  glutDisplayFunc(polygonDrawing);
  glutMainLoop();
  return 0;
}