// header File

#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

double xs_dda,xe_dda,ys_dda,ye_dda;

// Signum Function
double signDDA(double num)
{
  return num/abs(num);
}

// getting rounding
double getRound(double val)
{
  return floor(val+0.5);
}

// take end point coordinate input
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

// draw coordinate axis
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

// DDA Algo
void DDA_Algorithm()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );

  // calling coordinate axis draw function
  drawCoordinateAxisDDA();
  // calculating slope
  double x = xs_dda;
  double y = ys_dda;

  double dx = abs(xe_dda-xs_dda);
  double dy = abs(ye_dda-ys_dda);
  // calculating num. step
  double step = max(dx,dy);

  double s1 = signDDA(xe_dda-xs_dda);
  double s2 = signDDA(ye_dda-ys_dda);
  // finding xincr and yincr
  double x_incr = dx/step;
  double y_incr = dy/step;

  x_incr = s1*x_incr;
  y_incr = s2*y_incr;


  while(step>=0)
  {
    // running loop till number of step to plot line
    setPixelDDA(getRound(x),getRound(y));
    x = x+x_incr;
    y = y+y_incr;
    step--;
  }
  
  glFlush();
}
