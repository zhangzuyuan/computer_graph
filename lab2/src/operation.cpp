#include "operation.h"

void init()
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(1080, 768);
	glutInitWindowPosition(0, 0);
	int window = glutCreateWindow("Stick man");
}

void InitGL(int width, int height)
{
	glClearColor(0.1f, 0.6f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void ReSizeGLScene(int width, int height)
{
	if(height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void DrawBody()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	//forward           
	glVertex3f(-0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, -1.0f, 0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.5f, 1.0f, 0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, 0.25f);
	//bottom  
	glVertex3f(0.5f, -1.0f, 0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	glEnd();
}

void DrawShoulder()
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//forward           
	glVertex3f(-1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, -0.2f, 0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	//left  
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, 0.25f);
	//back  
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	//right  
	glVertex3f(-1.0f, 0.2f, 0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	//top  
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(1.0f, -0.2f, 0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	glEnd();
}
void DrawHip()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//forward             
	glVertex3f(-0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, -0.2f, 0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	//left  
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, 0.25f);
	//back  
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	//right  
	glVertex3f(-0.7f, 0.2f, 0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	//top  
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(0.7f, -0.2f, 0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	glEnd();
}

void DrawArmA() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(0.2f, -0.2f, 0.25f);
	glVertex3f(0.2f, -0.2f, -0.25f);
	glVertex3f(-0.2f, -0.2f, -0.25f);
	glVertex3f(-0.2f, -0.2f, 0.25f);

	glEnd();
}
void DrawArmB() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(-0.2f, -1.0f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glEnd();
}
void DrawLegB() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//left  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	//back  
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	//right  
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//top  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, 0.255f);
	//bottom  
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);

	glEnd();
}
void DrawLegA() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//left  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	//back  
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	//right  
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//top  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, 0.255f);
	//bottom  
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);

	glEnd();
}
void DrawHead() {
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, -0.6f, 0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	//left  
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, 0.35f);
	//back  
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	//right  
	glVertex3f(-0.6f, 0.6f, 0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	//top  
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, 0.35f);
	//bottom  
	glVertex3f(0.6f, -0.6f, 0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	glEnd();
}
void DrawNeck() {
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, -0.1f, 0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.1f, 0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, 0.25f);
	//bottom  
	glVertex3f(0.2f, -0.1f, 0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);

	glEnd();
}

//主画图函数
void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -35.0f);
		//glTranslatef(0.0f, 0.0f, -30.0f);
	glRotatef(angle, 0, 1, 0);
	//glTranslatef(trans, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -15.0f);
	//glTranslatef(25.0, 0.0, 0.0);
	glRotatef(-90, 0, 1, 0);
		glPushMatrix();
		glTranslatef(0.0f, 1.2f, 0.0f);
			glPushMatrix();
			glTranslatef(0.8, 0.0, 0.0);
			glTranslatef(0.0, -0.4, 0.0);
			glRotatef(angleoflarmb, 1, 0, 0);
				glPushMatrix();
				glTranslatef(0.0, -0.8, 0.0);
				glTranslatef(0.0, -0.3, 0.0);
				glRotatef(angleoflarma, 1, 0, 0);
				DrawArmA();
				glPopMatrix();
			DrawArmB();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-0.8, 0.0, 0.0);
			glTranslatef(0.0, -0.4, 0.0);
			glRotatef(angleofrarmb, 1, 0, 0);
				glPushMatrix();
				glTranslatef(0.0, -0.8, 0.0);
				glTranslatef(0.0, -0.3, 0.0);
				glRotatef(angleofrarma, 1, 0, 0);
				DrawArmA();
				glPopMatrix();
			DrawArmB();
			glPopMatrix();

			//return shoulder  
			glPushMatrix();
			glTranslatef(0.0, 0.3, 0.0);
				glPushMatrix();
				glTranslatef(0.0, 0.7, 0.0);
				DrawHead();
				glPopMatrix();
			DrawNeck();
			glPopMatrix();
		DrawShoulder();
		glPopMatrix();

		//return body  
		glPushMatrix();
		glTranslatef(0.0f, -1.2f, 0.0f);
			glPushMatrix();
			glTranslatef(0.4, 0.0, 0.0);
			glTranslatef(0.0, -0.4, 0.0);
			glRotatef(angleofllegb, 1, 0, 0);
				glPushMatrix();
				glTranslatef(0.0, -1.5, 0.0);
				glRotatef(angleofllega, 1, 0, 0);
				DrawLegA();
				glPopMatrix();
			DrawLegB();
			glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-0.4, 0.0, 0.0);
		glTranslatef(0.0, -0.4, 0.0);
		glRotatef(angleofrlegb, 1, 0, 0);
			glPushMatrix();
			glTranslatef(0.0, -1.5, 0.0);
			glRotatef(angleofrlega, 1, 0, 0);
			DrawLegA();
			glPopMatrix();
		DrawLegB();
		glPopMatrix();
	DrawHip();
	glPopMatrix();
	DrawBody();
	glPopMatrix();
	glPopMatrix();

	angleoflarma += la;
	angleofrarma += ra;
	angleoflarmb += a;
	angleofrarmb -= a;

	angleofllega += ll;
	angleofrlega += rl;
	angleofllegb -= b;
	angleofrlegb += b;
	angle += c;

	if (50 > angleoflarmb && angleoflarmb > 0 && a > 0) {
		a = angle1;
		b = angle2;
		la = -angle1 * 0.75;
		ra = -angle1;
		ll = 0.75*angle2;
		rl = angle2 * 1.5;
	}
	if (angleoflarmb >= 50 && a > 0) {
		a = -angle1;
		b = -angle2;
	}
	if (angleoflarmb > 0 && a < 0) {
		a = -angle1;
		b = -angle2;
		la = angle1 * 0.75;
		ra = angle1;
		ll = -angle2 * 0.75;
		rl = -angle2 * 1.5;
	}
	if (-50 < angleoflarmb && angleoflarmb <= 0 && a < 0) {
		a = -angle1;
		b = -angle2;
		la = -angle1;
		ra = -angle1 * 0.75;
		ll = angle2 * 1.5;
		rl = angle2 * 0.75;
	}
	if (angleoflarmb <= -50 && a < 0) {
		a = angle1;
		b = angle2;
	}
	if (angleoflarmb < 0 && a>0) {
		a = angle1;
		b = angle2;
		la = angle1;
		ra = angle1 * 0.75;
		ll = -angle2 * 1.5;
		rl = -angle2 * 0.75;
	}
	glutSwapBuffers();

}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y)
{
	Sleep(2000);  //pause 2 seconds
}