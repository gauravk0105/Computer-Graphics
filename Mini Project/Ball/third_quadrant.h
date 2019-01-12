void Quadrant3(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (0.0, 0.0, 1.0);
 	glBegin(GL_POINTS);
	int x=0,y=r,h=1-r;
	
	x=0;
	y=-r;
	while(-y>-x)
	{
		if(h<0)
		{
			h+=2*(-x) + 3;
		}
		else
		{
			h+=2*(-x+y) + 5;
			y++;
		}
		x--;
		glVertex2s(x+tx,y+ty);
	}
	glVertex2s(x+tx,y+ty);
	
	while(-y>0)
	{
		if(h<0)
		{
			h+=2*(-y) + 3;
		}
		else
		{
			h+=2*(-y+x) + 5;
			x--;
		}
		y++;
		glVertex2s(x+tx,y+ty);
	}
	glVertex2s(x+tx,y+ty);
	
}
