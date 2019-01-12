#include<iostream>
#include<bits/stdc++.h>
#include<GL/glut.h>

#include "line.h"

using namespace std;

int w_width = 1200 , w_height = 900;
int builing=0; // false;
int incr=3;
int decr=-3;
int mini_width=1;
float alpha=5; // angle

static int drawing;
static int l_width;
static ColorMake CC;
static vector<BuildLine> linesPoints;

#define N 4 


void initalize()
{
  drawing=1;
  l_width=mini_width;
  CC = ColorMake();
  linesPoints = vector <BuildLine>();
}

void init(string windowName)
{
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
  glutInitWindowPosition(100,100);
  glutInitWindowSize(w_width,w_height);  
  int n = windowName.length(); 
  char name[n+1];
  strcpy(name, windowName.c_str()); 
  glutCreateWindow(name);
  glClearColor(0.0f,0.0f,0.0f,1.0f);  
  glClear(GL_COLOR_BUFFER_BIT);        
  glColor3f(1.0f,1.0f,0.0f);   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w_width,0,w_height);
  drawing=0;
  l_width=mini_width;
  CC = ColorMake();
  linesPoints = vector <BuildLine>();
}

int sign(int num)
{
  return num/abs(num);
}

void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void mainMultiply()
{
    // int mat1[N][N] = {{1, 0, 0, w_width/2}, 
    //                   {0, 1, 0, w_height/2}, 
    //                   {0, 0, 1, 0}, 
    //                   {0, 0, 0, 1}}; 
  
    // int mat2[N][N] = {{1, 0, 0, -w_width/2}, 
    //                   {0, 1, 0, -w_height/2}, 
    //                   {0, 0, 1, 0}, 
    //                   {0, 0, 0, 1}}; 

    // int rotate[N][N] = {{0.86, -0.25, 0, 0}, 
    //                   {-.25, 0.86, 0, 0}, 
    //                   {0, 0, 0.895, 0}, 
    //                   {0, 0, 0, 1}};


    // int res[N][N]={{0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}};
    // int i, j, k; 
    // for (i = 0; i < N; i++) 
    // { 
    //     for (j = 0; j < N; j++) 
    //     { 
    //         res[i][j] = 0; 
    //         for (k = 0; k < N; k++) 
    //             res[i][j] += rotate[i][k] * mat1[k][j]; 
    //     } 
    // } 


    // int ans[N][N]={{0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}, 
    //                   {0, 0, 0, 0}};

    // for (i = 0; i < N; i++) 
    // { 
    //     for (j = 0; j < N; j++) 
    //     { 
    //         ans[i][j] = 0; 
    //         for (k = 0; k < N; k++) 
    //             ans[i][j] += mat2[i][k] * res[k][j]; 
    //     } 
    // } 

    for(int i=0;i<linesPoints.size();i++)
    {
        linesPoints[i].fp.x+=(w_width/2);
        linesPoints[i].lp.x+=(w_width/2);

        linesPoints[i].fp.y+=(w_height/2);
        linesPoints[i].lp.y+=(w_height/2);
    } 
	glRotatef(alpha, 0, 0, 0.5);
	for(int i=0;i<linesPoints.size();i++)
    {
        linesPoints[i].fp.x-=(w_width/2);
        linesPoints[i].lp.x-=(w_width/2);

        linesPoints[i].fp.y-=(w_height/2);
        linesPoints[i].lp.y-=(w_height/2);
    }

    // int pfpx = linesPoints[i].fp.x;
    // int pfpy = linesPoints[i].fp.y;
    // int plpx = linesPoints[i].lp.x;
    // int plpy = linesPoints[i].lp.y;
    // for(int i=0;i<linesPoints.size();i++)
    // {
    //     linesPoints[i].fp.x = (int)(ans[0][0]*pfpx + ans[0][1]*pfpy + ans[0][3]);
    //     linesPoints[i].fp.y = (int)(ans[1][0]*pfpx + ans[1][1]*pfpy + ans[1][3]);

    //     linesPoints[i].lp.x = (int)(ans[0][0]*plpx + ans[0][1]*plpy + ans[0][3]);
    //     linesPoints[i].lp.y = (int)(ans[1][0]*plpx + ans[1][1]*plpy + ans[1][3]);
    // } 
}

void midPointAlgorithm(int xs,int ys,int xe,int ye)
{
  double sw;  

  double x = xs;
  int y = ys;
  // calculating slope
  int dx = abs(xe-xs);
  int dy = abs(ye-ys);
  // signum
  int s1 = sign(xe-xs);
  int s2 = sign(ye-ys);  


  if(dy>dx)  
  {
    // m>1
    swap(dx,dy);
    sw=1;
  }
  else
    // m<1
    sw=0;

  int n=1;
  int p = 2*dy-dx;

  setPixel(x,y);  
  
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
    setPixel(x,y);
    n++;
  }
}

void drawThem(BuildLine line)
{
    ColorMake c = line.cc;

    glColor3d(c.r,c.g,c.b);

    CreatePoint fp = line.fp;
    CreatePoint lp = line.lp;

    // check for point
    if(fp==lp)
    {
        glPointSize(l_width);
        setPixel(fp.x,lp.y);
        //glBegin(GL_POINTS);
		//glVertex2i(fp.x, fp.y);
    }
    else
    {
        //glPointSize(l_width);
        glLineWidth(l_width);
         glBegin(GL_LINES);
		 glVertex2i(fp.x, fp.y);
		 glVertex2i(lp.x, lp.y);
        //midPointAlgorithm(fp.x,fp.y,lp.x,lp.y);
    }
    glEnd();
}

void draw_point_line()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0;i<linesPoints.size();i++)
    {
        drawThem(linesPoints[i]);
    }

    glutSwapBuffers();
}

void withKeyboard(unsigned char ch,int x,int y)
{
    switch (ch)
    {
        // scale down width
        case '-' : 
                    if(l_width > mini_width)    l_width = l_width - 1;
                    break;
        
        // scale up width
        case '+' : l_width = l_width + 1;
                   break;

        // left move
        case '1' : 
                   for(int i=0;i<linesPoints.size();i++)
                   {
                       linesPoints[i].fp.x+=decr;
                       linesPoints[i].lp.x+=decr;
                   } 
                   break;
        
        // right move
        case '3' : 
                   for(int i=0;i<linesPoints.size();i++)
                   {
                       linesPoints[i].fp.x+=incr;
                       linesPoints[i].lp.x+=incr;
                   } 
                   break;

        // up move
        case '5' : 
                   for(int i=0;i<linesPoints.size();i++)
                   {
                       linesPoints[i].fp.y+=incr;
                       linesPoints[i].lp.y+=incr;
                   } 
                   break;    

        // down move
        case '2' :
                   for(int i=0;i<linesPoints.size();i++)
                   {
                       linesPoints[i].fp.y+=decr;
                       linesPoints[i].lp.y+=decr;
                   } 
                   break;

        case 'q' : 
                    exit(0);
                    return;
        
        default : 
                    return;
    }

    glutPostRedisplay();
}

void withMouse(int whichButton,int buttonState , int x ,int y)  
{
    if(whichButton == GLUT_LEFT_BUTTON)
    {
        if(buttonState == GLUT_DOWN && !drawing)
        {
            linesPoints.push_back(BuildLine(CreatePoint(x,w_height-y),CreatePoint(),CC));
            drawing=1;
        }
        else
        {
            if(buttonState == GLUT_UP)
            {
                if(drawing==1)
                {
                    linesPoints[linesPoints.size()-1].lp = CreatePoint(x,w_height-y);
                    drawing = 0;
                    glutPostRedisplay();
                }
            }    
        }
    }
}

void motionnn(int x,int y)
{
    if(drawing==1)
    {
        linesPoints[linesPoints.size()-1].lp.y = w_height - y;
        linesPoints[linesPoints.size()-1].lp.x = x;
        glutPostRedisplay();
    }
}

void menuBar(int itemList)
{
    switch(itemList)
    {
        case 1 : CC = ColorMake(1,0,0);break;
        case 2 : CC = ColorMake(0,1,0);break;
        case 3 : CC = ColorMake(0,0,1);break;
        case 4 : CC = ColorMake(1,1,0);break;
        case 5 : CC = ColorMake(1,0,1);break;
        case 6 : exit(0);
                 return ;
        default:return ;   
    }
    glutPostRedisplay();
}

void pushBackItems()
{
    glutAddMenuEntry("---COLORS----",499);
    glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Yellow", 4);
	glutAddMenuEntry("Voilet", 5);
    glutAddMenuEntry("---ANY Other",499);
    glutAddMenuEntry("Exit",6);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="___BUILD___LINE___";
  init(windowName);
  
  glutDisplayFunc(draw_point_line);
  glutKeyboardFunc(withKeyboard);
  glutMouseFunc(withMouse);
  glutMotionFunc(motionnn);

  glutCreateMenu(menuBar);
  pushBackItems();
  glutAttachMenu(GLUT_RIGHT_BUTTON);  

  glutMainLoop();
  return 0;  
}