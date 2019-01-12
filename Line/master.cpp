/*
@ Creater : Gaurav Khandelwal (2016KUCP1002)

Contain Following
1) Line Drawing Algorithm
      a) DDA Alorithm
      b) Mid Point Algorithm

master file
*/
#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include "LineAlgorithm/DDA_Algorithm.h"
#include "LineAlgorithm/midPoint_Algorithm.h"
#include "init.h"
// Signum Function
using namespace std;

// main function
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // taking choice from user
  int choice;
  cout << "\t\t\tChoose\n";
  cout << "\t\t1. 1 for DDA Algorithm\n\t\t2. 2 for Mid Point Algorithm";
  cout << "\nEnter Choice : ";
  cin >> choice;
  string windowName="";
  // depend on choice the function call 
  switch(choice)
  {
    case 1 :  takeInputDDA();
              windowName="DDA Alogithm";
              init(windowName);
              glutDisplayFunc(DDA_Algorithm);
              break;
    case 2 : takeInputMidPoint();
             windowName="Mid Point Alogithm";
             init(windowName);
             glutDisplayFunc(midPointAlgorithm); 
             break;
  }

  glutMainLoop();
  return 0;
}