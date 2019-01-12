// header File

#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

double xs,xe,ys,ye;

// Signum Function 

double signMidPoint(double num)
{
  return num/abs(num);
}

// Function to Set Coordinate

void setPixelMID(double x,double y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

// Draw Coordinate Axis

void drawCoordinateAxisMid()
{
    double vertical=0;
    double horizontal=0;

    while(vertical<=500)
    {
        setPixelMID(0,vertical);

        setPixelMID(0,-1*vertical);

        vertical++;
    }

    while(horizontal<=500)
    {
        setPixelMID(horizontal,0);

        setPixelMID(-1*horizontal,0);

        horizontal++;
    }
}

// Mid Point Line Algorithm

void midPointAlgorithm()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );

  // draw coordinate axis  
  drawCoordinateAxisMid();

  double sw;  

  double x = xs;
  double y = ys;

  // calculating slope  
  double dx = abs(xe-xs);
  double dy = abs(ye-ys);

  // check to positive or negative xincr and yincr
  double s1 = signMidPoint(xe-xs);
  double s2 = signMidPoint(ye-ys);  


  if(dy>dx)  
  {
    // m>1  
    swap(dx,dy);
    sw=1;
  }
  else
    // m<1
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
  glFlush();
}

// Taking Coordinate of end point from user

void takeInputMidPoint()
{
  cout << "\t______Enter Starting Point______\n";
  cout << "xs : ";
  cin >> xs;
  cout << "ys : ";
  cin >> ys;
  cout << "\n\t______Enter Ending Point______\n";
  cout << "xe : ";
  cin >> xe;
  cout << "ye : ";
  cin >> ye;
}

