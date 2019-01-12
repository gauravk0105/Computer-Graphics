/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Circle Drawing Algorithm

master file
*/
#include<iostream>
#include<bits/stdc++.h>
#include<GL/glut.h>
#include "init.h"
#include "Circle_Algorithm.h"

using namespace std;

// main function
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="Circle Algorithm";
  takeCircleInput();
  init(windowName);
  glutDisplayFunc(drawCircle);
  glutMainLoop();
  return 0;  
}
