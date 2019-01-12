/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Ellipse Drawing Algorithm ALl Octant

master file
*/
#include<iostream>
#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

double r,h=0,k=0,a,b;

// init method
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

// taking input for ellipse
void takeEllipseInput()
{
    cout << "\nEnter X Ordinate : ";
    cin >> a;
    cout << "\nEnter Y Ordinate : ";
    cin >> b;
}

// setting pixel for a point
void setPixelEllipse(double x,double y)
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
    setPixelEllipse(0,vertical);

    setPixelEllipse(0,-1*vertical);

    vertical++;
  }

  while(horizontal<=500)
  {
    setPixelEllipse(horizontal,0);

    setPixelEllipse(-1*horizontal,0);

    horizontal++;
  }
}

// draw ellipse algo
void drawEllipse()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );
  // draw coordinate axis
  drawCoordinateAxis();

  // Quadrant 1 Region-1

  double x = 0;
  double y = b;

  double xprev,yprev;

  int p1 = ((b*b) + ((a*a)/4) - (a*a*b));  
  
  while(2*b*b*x < 2*a*a*y)
  {
    // set pixel
    setPixelEllipse(x,y);
    setPixelEllipse(x,-1*y);
    setPixelEllipse(-1*x,-1*y);
    setPixelEllipse(-1*x,y);
    xprev=x;
    yprev=y;
    x=x+1;
    // decision parameter
    if(p1>=0)
      y=y-1;
    // decision parameter  
    if(p1>=0)
      p1 = p1 + (b*b) +(2*b*b*x) - (2*a*a*y);
    else
      p1 = p1 + (b*b) + (2*b*b*x);
  }

  // Quadrant 1 Region -2
  
  double p2 = (x+0.5)*(x+0.5)*b*b + ((y-1)*(y-1)*a*a) - a*a*b*b;
  while(y>0)
  {
    // set pixel
    setPixelEllipse(x,y);
    setPixelEllipse(x,-1*y);
    setPixelEllipse(-1*x,-1*y);
    setPixelEllipse(-1*x,y);
     xprev=x;
     xprev=y;
     y=y-1;
     // decision parameter
     if(p2<0)
       x=x+1;
      // decision parameter
     if(p2>0)
       p2 = p2 + (a*a) - (2*a*a*y);
     else
       p2 = p2 + (a*a) - (2*a*a*y) + (2*b*b*x);
   }

  glFlush();
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="Ellipse Algorithm";
  takeEllipseInput();
  init(windowName);
  glutDisplayFunc(drawEllipse);
  glutMainLoop();
  return 0;  
}
