#include<iostream>
#include<bits/stdc++.h>
#include<GL/glut.h>
	
	using namespace std;
	
	// limbs length
	float upper_middle_leg_length = 4.0f;
	float lower_leg_length = 1.0f;
	float upper_middle_arm_length = 3.0f;
	float lower_arm_length = 1.0f;
	
	// general angles
	float upper_torso_angle = 0.0f;
	float lower_torso_angle = 0.0f;
	float head_angle = 0.0f;
	
	// right side angles
	float r_shoulder_angle = 0.0f;
	float r_elbow_angle = 0.0f;
	float r_wrist_angle = 0.0f;
	float r_hip_angle = 0.0f;
	float r_knee_angle = 0.0f;
	float r_ankle_angle = 0.0f;
	
	// left side angles
	float l_shoulder_angle = 0.0f;
	float l_elbow_angle = 0.0f;
	float l_wrist_angle = 0.0f;
	float l_hip_angle = 0.0f;
	float l_knee_angle = 0.0f;
	float l_ankle_angle = 0.0f;
	
	// limb selection
	char limb;
	
	void changeSize(int w, int h) { // callback to render nicely if the screen gets resized by the user
		// Prevent a divide by zero, when window is too short
		// (you cant make a window of zero width).
		if (h == 0) h = 1;
	
		float ratio = w * 1.0 / h;
	
		// Use the Projection Matrix
		glMatrixMode(GL_PROJECTION);
	
		// Reset Matrix
		glLoadIdentity();
	
		// Set the viewport to be the entire window
		glViewport(0, 0, w, h);
	
		// Set the correct perspective
		gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	
		// Get Back to the Modelview
		glMatrixMode(GL_MODELVIEW);
	}
	
	void modify_world(float x, float y, float direction, float angle) {
		// move the world to the right position and rotate it
		glTranslatef(direction*x, y, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
	}
	
	void draw_junction(float x, float y) { // draw body part's intersection point
		glColor3f(1.0f, 0.0f, 0.0f);
	 glBegin(GL_POINTS);
	 glVertex2f(x, y);
	 glEnd();
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	
	void color_white_if(char right_limb, char left_limb, int direction) {
		// set color to white if the limb got selected. 'limb' is the limb selected by the user (a char '1'-'6')
		// direction=1 := right limb | direction=2 := left limb
		if ((limb == right_limb && direction == 1) || (limb == left_limb && direction == -1)) 
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	
	void draw_limb(int direction, float angle, float world_x, float world_y,
		float right_limb, float left_limb, float limb_x, float limb_y) {
		modify_world(world_x, world_y, direction, angle);
		color_white_if(right_limb, left_limb, direction);
	
		glBegin(GL_LINES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(direction*limb_x, limb_y);
		glEnd();
	
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	
	void draw_middle_limb(int direction, float angle, float world_x, float world_y,
		float right_limb, float left_limb, float limb_x, float limb_y) {
		draw_limb(direction, angle, world_x, world_y, right_limb, left_limb, limb_x, limb_y);
		draw_junction(direction*limb_x, limb_y);
	}
	
	void draw_upper_torso() {
		draw_limb(1, upper_torso_angle, 0.0f, 0.0f, '6', '6', 0.0f, 3.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0.0f, 3.0f);
		glVertex2f(3.0f, 3.0f);
		glVertex2f(-3.0f, 3.0f);
		glEnd();
		draw_junction(3.0f, 3.0f);
		draw_junction(-3.0f, 3.0f);
		draw_junction(0.0f, 0.0f);
		draw_junction(0.0f, 3.0f);
	}
	
	
	// ARM FUNCTIONS
	void draw_elbow(int direction, float angle) 
	{ draw_middle_limb(direction, angle, 3.0f, 3.0f, '4', '3', upper_middle_arm_length, 0.0f); }
	
	void draw_wrist(int direction, float angle) 
	{ draw_middle_limb(direction, angle, upper_middle_arm_length, 0.0f, '4', '3', upper_middle_arm_length, 0.0f); }
	
	void draw_hand(int direction, float angle) 
	{ draw_limb(direction, angle, upper_middle_arm_length, 0.0f, '4', '3', 0.0f, lower_arm_length); }
	
	void draw_arm(int direction, float shoulder_angle, float elbow_angle, float wrist_angle) {
		glPushMatrix();
		glPushMatrix();
		draw_elbow(direction, shoulder_angle);
		glPushMatrix();
		draw_wrist(direction, elbow_angle);
		draw_hand(direction, wrist_angle);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	
	void draw_right_arm() {	draw_arm(1, r_shoulder_angle, r_elbow_angle, r_wrist_angle); }
	void draw_left_arm() { draw_arm(-1, l_shoulder_angle, l_elbow_angle, l_wrist_angle); }
	
	
	// LEG FUNCTIONS
	void draw_lower_torso() {
		glBegin(GL_LINES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -3.0f);
		glVertex2f(2.0f, -3.0f);
		glVertex2f(-2.0f, -3.0f);
		glEnd();
	
		draw_junction(2.0f, -3.0f);
		draw_junction(-2.0f, -3.0f);
	}
	
	void draw_knee(int direction, float angle) 
	{ draw_middle_limb(direction, angle, 2.0f, -3.0f, '2', '1', 0.0f, -upper_middle_leg_length); }
	
	void draw_ankle(int direction, float angle) 
	{ draw_middle_limb(direction, angle, 0.0f, -upper_middle_leg_length, '2', '1', 0.0f, -upper_middle_leg_length); }
	
	void draw_foot(int direction, float angle) 
	{ draw_limb(direction, angle, 0.0f, -upper_middle_leg_length, '2', '1', lower_leg_length, 0.0f); }
	
	void draw_leg(int direction, float hip_angle, float knee_angle, float ankle_angle) {
		glPushMatrix();
		glPushMatrix();
		draw_knee(direction, hip_angle);
		glPushMatrix();
		draw_ankle(direction, knee_angle);
		draw_foot(direction, ankle_angle);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	
	void draw_right_leg() { draw_leg(1, r_hip_angle, r_knee_angle, r_ankle_angle); }
	void draw_left_leg() { draw_leg(-1, l_hip_angle, l_knee_angle, l_ankle_angle); }
	
	
	// HEAD FUNCTION
	void draw_head() {
		glColor3f(0.0f, 1.0f, 0.0f);
		color_white_if('5', '5', 1);
		modify_world(0.0f, 3.0f, 1, head_angle);
	
		// draw neck
		glBegin(GL_LINES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);
		glEnd();
	
		glTranslatef(0.0f, 3.0f, 0.0f);
	
		// we draw a gluDisk with same inner and outer 
		// radius' to get a circle for the head
		GLUquadric *quad = gluNewQuadric();
		gluDisk (quad, 2.0f, 2.1f, 100.0f, 1.0f);
	
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	
	
	void render(){ // Function to be called by openGL in every cycle of the main loop
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		// clear transformations
		glLoadIdentity();
	
		// set camera
		gluLookAt(0.0f, 0.0f, 30.0f, // camera position
		0.0f, 0.0f, 0.0f, // look at this point
		0.0f, 1.0f, 0.0f); // camera's "tilt vector"
	
		// configurations
		glLineWidth(3);
		glPointSize(10);
	
		// draw uppder side of the doll
		glPushMatrix();
		draw_upper_torso();
	
		glPushMatrix();
		draw_head();
		glPopMatrix();
	
		draw_right_arm();
		draw_left_arm();
		glPopMatrix();
	
		//// draw lower side of the doll
		glPushMatrix();
		draw_lower_torso();
		draw_right_leg();
		draw_left_leg();
		glPopMatrix();
	
		glutSwapBuffers();
	}
	
	void processKeys(unsigned char key, int x, int y) {
		float magnitude = 10.0f; // angle modification magnitude
	
		if (key == 27) exit(0);
		else if (key <= '6' && key >= '1') limb = key;
		else switch(key) {
		case 'A':
		case 'a':	
		switch(limb) {
		case '6': upper_torso_angle += magnitude; break;
		case '5': head_angle += magnitude;	break;
		case '4': r_shoulder_angle += magnitude; break;
		case '3': l_shoulder_angle += magnitude; break;
		case '2': r_hip_angle += magnitude;	break;
		case '1': l_hip_angle += magnitude;	break;
		}
		break;
		case 'Z':
		case 'z':
		switch(limb) {
		case '6': upper_torso_angle -= magnitude; break;
		case '5': head_angle -= magnitude;	break;
		case '4': r_shoulder_angle -= magnitude; break;
		case '3': l_shoulder_angle -= magnitude; break;
		case '2': r_hip_angle -= magnitude;	break;
		case '1': l_hip_angle -= magnitude;	break;
		}
		break;
		case 'S':
		case 's':
		switch(limb) {
		case '4': r_elbow_angle += magnitude; break;
		case '3': l_elbow_angle += magnitude; break;
		case '2': r_knee_angle += magnitude; break;
		case '1': l_knee_angle += magnitude; break;
		}
		break;
		case 'X':
		case 'x':
		switch(limb) {
		case '4': r_elbow_angle -= magnitude; break;
		case '3': l_elbow_angle -= magnitude; break;
		case '2': r_knee_angle -= magnitude; break;
		case '1': l_knee_angle -= magnitude; break;
		}
		break;
		case 'D':
		case 'd':
		switch(limb) {
		case '4': r_wrist_angle += magnitude; break;
		case '3': l_wrist_angle += magnitude; break;
		case '2': r_ankle_angle += magnitude; break;
		case '1': l_ankle_angle += magnitude; break;
		}
		break;
		case 'C':
		case 'c':
		switch(limb) {
		case '4': r_wrist_angle -= magnitude; break;
		case '3': l_wrist_angle -= magnitude; break;
		case '2': r_ankle_angle -= magnitude; break;
		case '1': l_ankle_angle -= magnitude; break;
		}
		break;
		}
	}
	
	int main (int argc, char** argv) {
		// initialize glut
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(800,600);
		glutCreateWindow("Opengl");
	
		// register callbacks
		glutDisplayFunc(render);
		glutIdleFunc(render);
		glutKeyboardFunc(processKeys);
		glutReshapeFunc(changeSize);
	
		// enable points to be circles
		glEnable(GL_POINT_SMOOTH);
	 glEnable(GL_BLEND);
	 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		// enter main loop
		glutMainLoop();
		return 1;
	}