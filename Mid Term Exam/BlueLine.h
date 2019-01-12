#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void setPixelBlue(double x,double y)
{
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2i(x,y);
    glEnd();
}


void midPointAlgorithmBlue(double xs,double ys,double xe,double ye)
{
  double sw;  

  double x = xs;
  double y = ys;

  double dx = abs(xe-xs);
  double dy = abs(ye-ys);

  double s1 = sign(xe-xs);
  double s2 = sign(ye-ys);  


  if(dy>dx)  
  {
    swap(dx,dy);
    sw=1;
  }
  else
    sw=0;

  double n=1;
  double p = 2*dy-dx;

  setPixelBlue(x,y);  

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
    setPixelBlue(x,y);
    n++;
  }
}