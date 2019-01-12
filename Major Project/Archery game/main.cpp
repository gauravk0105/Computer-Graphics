/* 
    Name : Gaurav Khandelwal
    Batch : A1
    Roll Number : 2016KUCP1002
    Project : Board Hit

*/


// Header Files
#include<iostream>
#include<bits/stdc++.h>
#include<GL/glut.h>
#include <sstream>


using namespace std;

// fx = front , common_y = y-coordinate , bx = back , tx = arrow head
double fx = -300;
double common_y = 0;
double bx= -550;
double ty=20;
double tx=-270;
// motion status
bool motion=true;
// fow status
int fow=0;
// pressed status
bool pressed=false;
int yincre=0;
// count round
int cot=0;
// game status
bool gameStatus=true;
// hit mark
int hit=0;
// height of bars
int rpy=0,gpy=0,cpy=0,opy=0;
int final;
int valr,valg,valc,valo;
// values for hit
int dr=10,dg=8,dc=6,do1=4;
int count_r=0,count_g=0,count_c=0,count_o=0;

// initialize function
void init(string windowName)
{
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1000,1000);  
  int n = windowName.length(); 
  char name[n+1];
  strcpy(name, windowName.c_str()); 
  glutCreateWindow(name);
  glClearColor(0,0,1,0);  
  glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
  glColor3f(0.0f,1.0f,0.0f);   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1000,1000,-1000,1000);
}

// setting pixel
void setPixelEllipse(double x,double y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

// draw axis function to draw axis
void drawCoordinateAxis()
{
  double vertical=0;
  double horizontal=0;

  while(vertical<=1000)
  {
    setPixelEllipse(-560,vertical);

    setPixelEllipse(-560,-1*vertical);

    vertical++;
  }
}

// signum function
double sign(double num)
{
  return num/abs(num);
}

// mid point algo
void midPointAlgorithm(double xs,double ys,double xe,double ye)
{
  double sw;  
  double x = xs;
  double y = ys;
  // calculating slope  
  double dx = abs(xe-xs);
  double dy = abs(ye-ys);
  // check to positive or negative xincr and yincr
  double s1 = sign(xe-xs);
  double s2 = sign(ye-ys);  
  // status of slope
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
  setPixelEllipse(x,y);  
  while(n<=dx)  {
    if(p>=0){
        x=x+s1;
        y=y+s2;
        p=p+2*(dy-dx);
    }
    else{
        if(sw==1)
            y=y+s2;
        else
            x=x+s1;
        p=p+2*dy;    
    }
    setPixelEllipse(x,y);
    n++;
  }  
}

// draw ellipse function
void drawEllipse(double h,double k,double a,double b)
{
  double x = 0;
  double y = b;
  double xprev,yprev;
  // decision parameter
  int p1 = ((b*b) + ((a*a)/4) - (a*a*b));  
  while(2*b*b*x < 2*a*a*y)
  {
      // setting pixel coordinate
    setPixelEllipse(x+h,y+k);
    setPixelEllipse(x+h,-1*y+k);
    setPixelEllipse(-1*x+h,-1*y+k);
    setPixelEllipse(-1*x+h,y+k);
    xprev=x;
    yprev=y;
    x=x+1;
    if(p1>=0)
      y=y-1;  
    if(p1>=0)
      p1 = p1 + (b*b) +(2*b*b*x) - (2*a*a*y);
    else
      p1 = p1 + (b*b) + (2*b*b*x);
  }
  // setting decision parameter
  double p2 = (x+0.5)*(x+0.5)*b*b + ((y-1)*(y-1)*a*a) - a*a*b*b;
  while(y>0)
  {
      // setting pixel
    setPixelEllipse(x+h,y+k);
    setPixelEllipse(x+h,-1*y+k);
    setPixelEllipse(-1*x+h,-1*y+k);
    setPixelEllipse(-1*x+h,y+k);
     xprev=x;
     xprev=y;
     y=y-1;
     if(p2<0)
       x=x+1;
     if(p2>0)
       p2 = p2 + (a*a) - (2*a*a*y);
     else
       p2 = p2 + (a*a) - (2*a*a*y) + (2*b*b*x);
   }
}

void displayText( float x, float y, int r, int g, int b, const char *string ) {
	int j = strlen( string );
 
	//glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
	}
}


void game()
{
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT );
  //displayText(0,0,0,1,0,"ROUND");
  if(gameStatus==true)
  {
     // game is running
    // arrow 
    glColor3f(0.0f, 0.0f, 0.0f);
    midPointAlgorithm(bx+fow,common_y+yincre,fx+fow,common_y+yincre);
    midPointAlgorithm(fx+fow,ty+yincre,fx+fow,-ty+yincre);
    midPointAlgorithm(fx+fow,ty+yincre,tx+fow,common_y+yincre);
    midPointAlgorithm(fx+fow,-ty+yincre,tx+fow,common_y+yincre);  
    midPointAlgorithm(bx+fow,ty+yincre,bx+fow,-ty+yincre);  
    // axis vertical
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxis();
    // hit status == 0 , means yet to be hit 
    if(hit==0)
    {
        glColor3f(1.0f,0.0f,0.0f);
        for(int u=0;u<=rpy;u=u+2){
            glColor3f(1.0f, 0.0f, 0.0f);
            midPointAlgorithm(-1000,u,-900,u);
        }

        glColor3f(0.0f,1.0f,0.0f);
        for(int u=0;u<=gpy;u=u+2){
            glColor3f(0.0f, 1.0f, 0.0f);
            midPointAlgorithm(-890,u,-790,u);
        }

        glColor3f(0.0f,1.0f,1.0f);
        for(int u=0;u<=cpy;u=u+2){
            glColor3f(0.0f, 1.0f, 1.0f);
            midPointAlgorithm(-780,u,-680,u);
        }

        glColor3f(0.0f,0.0f,0.0f);
        for(int u=0;u<=opy;u=u+2){
            glColor3f(0.0f, 0.0f, 0.0f);
            midPointAlgorithm(-670,u,-570,u);
        }
    }
    // hit status == 1 , means hit Red section
    if(hit==1)
    {
        count_r++;
        glColor3f(1.0f, 0.0f, 0.0f);
        midPointAlgorithm(-1000,rpy,-900,rpy);
        int u;
        for(u=0;u<=rpy+50;u=u+2){
            glColor3f(1.0f, 0.0f, 0.0f);
            midPointAlgorithm(-1000,u,-900,u);
        }
        rpy=u;   
        hit=0;
    }
    // hit status == 2 , means hit Green section
    if(hit==2)
    {
        count_g++;
        glColor3f(0.0f, 1.0f, 0.0f);
        midPointAlgorithm(-890,gpy,-790,gpy);
        int u;
        for(u=0;u<=gpy+50;u=u+2){
            glColor3f(0.0f, 1.0f, 0.0f);
            midPointAlgorithm(-890,u,-790,u);
        }
        gpy=u;   
        hit=0;
    }
    // hit status == 3 , means hit Blue-voilet section
    if(hit==3)
    {
        count_c++;
        glColor3f(0.0f, 1.0f, 1.0f);
        midPointAlgorithm(-780,cpy,-680,cpy);
        int u;
        for(u=0;u<=cpy+50;u=u+2){
            glColor3f(0.0f, 1.0f, 1.0f);
            midPointAlgorithm(-780,u,-680,u);
        }
        cpy=u;   
        hit=0;
    }
    // hit status == 4 , means hit outside the board
    if(hit==4)
    {
        count_o++;
        glColor3f(0.0f, 0.0f, 0.0f);
        midPointAlgorithm(-670,opy,-570,opy);
        int u;
        for(u=0;u<=opy+50;u=u+2)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            midPointAlgorithm(-670,u,-570,u);
        }
        opy=u;   
        hit=0;    
    }
    // static code    
    // lines
    for(int i=0;i<=600;i++)
    {
        glColor3f(0.0f,0.0f,0.0f);
        midPointAlgorithm(710,i,890,i);
        midPointAlgorithm(710,-i,890,-i);   
    }
    // draw ellispe
    for(int i=0;i<=150;i++){
    glColor3f(1.0f, 0.0f, 0.0f);
    drawEllipse(800,0,60,i);
    }  
    // draw ellispe
    for(int i=152;i<=300;i++){
        glColor3f(0.0f, 1.0f, 0.0f);
        drawEllipse(800,0,70,i);
    }  
    // draw ellispe
    for(int i=302;i<=500;i++){
        glColor3f(0.5f, 0.3f, 0.8f);
        drawEllipse(800,0,80,i);
    }
  }
  else
  {
      // if game get over
      if(gameStatus==false)
      {
         // sort the result 
        vector< pair<int,char> > color_pair; 
        color_pair.push_back({count_r*dr,'r'});
        color_pair.push_back({count_g*dg,'g'});
        color_pair.push_back({count_c*dc,'c'});
        color_pair.push_back({count_o*do1,'o'});
        sort(color_pair.begin(),color_pair.end());
        int start=-400;
        // anddisplay according to the list of ordering
        for(int i=0;i<color_pair.size();i++)
        {
            if(color_pair[i].second == 'r')
            {
                glColor3f(1.0f,0.0f,0.0f);
                for(int u=0;u<=rpy;u=u+2){
                    glColor3f(1.0f, 0.0f, 0.0f);
                    midPointAlgorithm(start,u,start+200,u);
                }           
                start+=220;
            }   
            if(color_pair[i].second == 'g')
            {
                glColor3f(0.0f,1.0f,0.0f);
                for(int u=0;u<=gpy;u=u+2)
                {
                    glColor3f(0.0f, 1.0f, 0.0f);
                    midPointAlgorithm(start,u,start+200,u);
                }        
                start+=220;
            }
            if(color_pair[i].second == 'c')
            {
                glColor3f(0.0f,1.0f,1.0f);
                for(int u=0;u<=cpy;u=u+2)
                {
                    glColor3f(0.0f, 1.0f, 1.0f);
                    midPointAlgorithm(start,u,start+200,u);
                }        
                start+=220;
            }
            if(color_pair[i].second == 'o')
            {
                glColor3f(0.0f,0.0f,0.0f);
                for(int u=0;u<=opy;u=u+2){
                    glColor3f(0.0f, 0.0f, 0.0f);
                    midPointAlgorithm(start,u,start+200,u);
                }
                start+=220;
            }
        }
      }
  }
  glFlush();   
}

void movement(int)
{
    // timer function
  glutPostRedisplay();
  glutTimerFunc(1000/5,movement,0);
  glClear (GL_COLOR_BUFFER_BIT);
  glClearColor(1,1,1,1);
  glBegin(GL_POINTS);
  if(cot>=10)
    // mark status of game over
    gameStatus=false;
  else{
      // running game
       // hit=0; 
        if(pressed==true)
        {
            // if key pressed
            if(common_y>=-500 && common_y<=500){
                if(fow<=900)
                    fow=fow+200;
                else{
                    cot++;
                    pressed=false;
                    fow=0;
                    // checking hitting area
                    if( (yincre>=0 && yincre<=150) || (yincre<=0 && yincre>=-150) )
                    {
                       hit=1;
                    }
                    else
                    {
                        if( (yincre>=151 && yincre<=300) || (yincre<=-151 && yincre>=-300) )
                        {
                            hit=2;
                        }
                        else
                        {
                            if( (yincre>=301 && yincre<=500) || (yincre<=-301 && yincre>=-500) )
                            {
                                hit=3;
                            }
                            else
                                hit=4;
                        }
                    }
                }
            }
            else
            {
                // again going to check hitting area
                if(fow<=950)
                    fow=fow+200;
                else{
                    cot++;
                    pressed=false;
                    fow=0;
                    if( (yincre>=0 && yincre<=150) || (yincre<=0 && yincre>=-150) )
                    {
                      hit=1;
                    }
                    else
                    {
                        if( (yincre>=151 && yincre<=300) || (yincre<=-151 && yincre>=-300) )
                        {
                            hit=2;
                        }
                        else
                        {
                            if( (yincre>=301 && yincre<=500) || (yincre<=-301 && yincre>=-500) )
                            {
                                hit=3;
                            }
                            else
                                hit=4;
                        }
                    }
                } 
            }
        }
        
        // if not pressed
        if(pressed==false)
        {
            // motion is true
            if(motion==true){
                if(yincre<=600 && motion==true)
                    yincre=yincre+230;
                else{
                    //cot++;
                    motion = false;
                    }
            }
            // if motion is false
            if(motion==false){
                if(yincre>=-600 && motion==false)
                    yincre=yincre-230;
                else
                    {
                        //cot++;
                        motion=true;
                    }
                }
        }    
  }
}

void withKeyboard(unsigned char ch,int x,int y)
{
    // on key pressed
    if(ch=='f')
    {
        // mark status of pressed
        pressed=true;    
    }
}

// main function
int main(int argc, char **argv)
{
  // calling keyboard , display and init
  glutInit(&argc, argv);
  string windowName="Ellipse Algorithm";
  init(windowName);
  glutDisplayFunc(game);
  glutTimerFunc(0,movement,0);
  glutKeyboardFunc(withKeyboard);
  glutMainLoop();
  return 0;  
}

/*
_____________________________________________________________________________________________________________________________________________________________________________*/