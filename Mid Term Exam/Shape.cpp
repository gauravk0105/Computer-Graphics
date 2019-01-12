/*
 Author : Gaurav Khandelwal
 Roll No. : 2016KUCP1002
 Implemention : Cube having Triangle on it which Translate 

*/

#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include "init.h"
#include "RedLine.h"
#include "BlackLine.h"
#include "GreenLine.h"
#include "BlueLine.h"

using namespace std;

void figure()
{
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT );


  midPointAlgorithmBlue(0,0,100,100);
  midPointAlgorithmBlue(200,0,300,100);
  midPointAlgorithmBlue(0,200,100,300);
  midPointAlgorithmBlue(200,200,300,300);

  midPointAlgorithmGreen(100,100,100,300);
  midPointAlgorithmGreen(100,300,300,300);
  midPointAlgorithmGreen(100,100,300,100);
  midPointAlgorithmGreen(300,300,300,100);
  
  if(i>=200)
    i=200;
  

  midPointAlgorithmRed(100+i,300,i+200,500);
  midPointAlgorithmRed(200+i,500,300+i,300);  
  midPointAlgorithmRed(300,300,300+i,300);

  midPointAlgorithmRandom(0,0,200,0);
  midPointAlgorithmRandom(200,0,200,200);
  midPointAlgorithmRandom(0,0,0,200);
  midPointAlgorithmRandom(0,200,200,200);


  glFlush();
}

void timer(int)
{
  glutPostRedisplay();
  glutTimerFunc(1000/30,timer,0);
  glClear (GL_COLOR_BUFFER_BIT);
  glClearColor(1,1,1,1);
  glBegin(GL_POINTS);
  if(i<=400)
     i++;
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="";
  windowName="Figure";
  init(windowName);
  glutDisplayFunc(figure);
  glutTimerFunc(0,timer,0);
  glutMainLoop();
  return 0;
}