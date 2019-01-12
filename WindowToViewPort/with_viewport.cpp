/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) With Viewport

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

// variable coordinate
double xs_dda,xe_dda,ys_dda,ye_dda;

// sigum
double signDDA(double num)
{
  return num/abs(num);
}

// get round function
double getRound(double val)
{
  return floor(val+0.5);
}

// take input
void takeInputDDA()
{
  cout << "\t______Enter Starting Point______\n";
  cout << "xs : ";
  cin >> xs_dda;
  cout << "ys : ";
  cin >> ys_dda;
  cout << "\n\t______Enter Ending Point______\n";
  cout << "xe : ";
  cin >> xe_dda;
  cout << "ye : ";
  cin >> ye_dda;
}

// set pixel
void setPixelDDA(double x,double y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

// draw coordinate
void drawCoordinateAxisDDA()
{
    double vertical=0;
    double horizontal=0;

    while(vertical<=500)
    {
        setPixelDDA(0,vertical);

        setPixelDDA(0,-1*vertical);

        vertical++;
    }

    while(horizontal<=500)
    {
        setPixelDDA(horizontal,0);

        setPixelDDA(-1*horizontal,0);

        horizontal++;
    }
}

// DDA algorithm
void DDA_Algorithm()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );

  // draw cordinate axis  
  drawCoordinateAxisDDA();

  double x = xs_dda;
  double y = ys_dda;

  double dx = abs(xe_dda-xs_dda);
  double dy = abs(ye_dda-ys_dda);

  // calculating steps      
  double step = max(dx,dy);

  double s1 = signDDA(xe_dda-xs_dda);
  double s2 = signDDA(ye_dda-ys_dda);

  // x increment and y increment  
  double x_incr = dx/step;
  double y_incr = dy/step;
  
  x_incr = s1*x_incr;
  y_incr = s2*y_incr;

  // step plotting  
  while(step>=0)
  {
    setPixelDDA(getRound(x),getRound(y));
    x = x+x_incr;
    y = y+y_incr;
    step--;
  }
  
  glFlush();
}

// main
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  cout << "\t\t for Mid Point Algorithm";
  string windowName="";
  takeInputDDA();
  windowName="DDA Alogithm";
  init(windowName);
  glutDisplayFunc(DDA_Algorithm);
  glutMainLoop();
  return 0;
}