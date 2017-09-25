/*
	������������ ������ �3
	���������� �.�.
	������� � 8
	IT - 631

	����������: w, s, a, d, q, e - �������
	f1, f2, f3, f4, f5, f6 - ���������������
	�������, PgUp, PgDn - ������� �� ����
	x - ��������� �������, z - ��������� �������
	"������" - �����.
	*/
#include <GL/glut.h>
#include <stdio.h>
#include "loadbmp.h"

float Width = 800, Height = 800;
float ambient[] = { 0.5, 0.5, 0.5, 1 }; //���������
float xb = 0; //��� ���������� �����

GLuint texture[8];

void TextureInit(char strFile[], GLuint *text)
{
	IMAGE img;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(8, text);
	if (!LoadBMP(strFile, &img))
		return;
	glBindTexture(GL_TEXTURE_2D, *text);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img.width, img.height, GL_RGB, GL_UNSIGNED_BYTE, img.data);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

//������
void Match()
{
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	//���� ������
	glTexCoord2f(1, 1);	glVertex3f(240, 20, 20);
	glTexCoord2f(0, 1);	glVertex3f(240, 20, 0);
	glTexCoord2f(0, 0);	glVertex3f(-240, 20, 0);
	glTexCoord2f(1, 0);	glVertex3f(-240, 20, 20);
	//��� ������
	glTexCoord2f(1, 1);	glVertex3f(240, 0, 20);
	glTexCoord2f(0, 1);	glVertex3f(240, 0, 0);
	glTexCoord2f(0, 0);	glVertex3f(-240, 0, 0);
	glTexCoord2f(1, 0);	glVertex3f(-240, 0, 20);
	//������� ������� ������
	glTexCoord2f(1, 1);	glVertex3f(240, 20, 20);
	glTexCoord2f(1, 0);	glVertex3f(-240, 20, 20);
	glTexCoord2f(0, 0);	glVertex3f(-240, 0, 20);
	glTexCoord2f(0, 1);	glVertex3f(240, 0, 20);
	//������� ������� ������
	glTexCoord2f(1, 1);	glVertex3f(240, 20, 0);
	glTexCoord2f(1, 0);	glVertex3f(-240, 20, 0);
	glTexCoord2f(0, 0);	glVertex3f(-240, 0, 0);
	glTexCoord2f(0, 1);	glVertex3f(240, 0, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	//�����
	glTexCoord2f(0, 0);	glVertex3f(240, 20, 20);
	glTexCoord2f(1, 0);	glVertex3f(240, 0, 20);
	glTexCoord2f(1, 1);	glVertex3f(240, 0, 0);
	glTexCoord2f(0, 1);	glVertex3f(240, 20, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	//���
	glTexCoord2f(0, 0);	glVertex3f(-240, 20, 20);
	glTexCoord2f(1, 0);	glVertex3f(-240, 0, 20);
	glTexCoord2f(1, 1);	glVertex3f(-240, 0, 0);
	glTexCoord2f(0, 1);	glVertex3f(-240, 20, 0);
	glEnd();
}

void Display(void)
{
	GLUquadricObj *quadObj;
	quadObj = gluNewQuadric(); //��������� ������

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();

	glScalef(0.8, 1, 1);

	//������� ����� �������
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);	//���
	glTexCoord2f(0, 0);	glVertex3f(-255, 0, 0);
	glTexCoord2f(1, 0);	glVertex3f(-255, 0, 256);
	glTexCoord2f(1, 1);	glVertex3f(256, 0, 256);
	glTexCoord2f(0, 1);	glVertex3f(256, 0, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3f(-255, 64, 0);
	glTexCoord2f(1, 0);	glVertex3f(-255, 64, 256);
	glTexCoord2f(1, 1);	glVertex3f(256, 64, 256);
	glTexCoord2f(0, 1);	glVertex3f(256, 64, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
	//������� �������
	glTexCoord2f(0, 0);	glVertex3f(-255, 0, 256);
	glTexCoord2f(1, 0);	glVertex3f(256, 0, 256);
	glTexCoord2f(1, 1);	glVertex3f(256, 64, 256);
	glTexCoord2f(0, 1);	glVertex3f(-255, 64, 256);
	//������� �������
	glTexCoord2f(0, 0);	glVertex3f(-255, 0, 0);
	glTexCoord2f(1, 0);	glVertex3f(256, 0, 0);
	glTexCoord2f(1, 1);	glVertex3f(256, 64, 0);
	glTexCoord2f(0, 1);	glVertex3f(-255, 64, 0);
	glEnd();

	//���������� ����� �������
	glTranslatef(xb, 4, -22);
	
	//���������� ������
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			glTranslatef(0, 0, 25);
			Match();	//������
		}
		glTranslatef(0, 24, -25 * 10);
	}
	glTranslatef(0, -50, 25 * 6);
	//����
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	//���
	glTexCoord2f(0, 1);	glVertex3f(-255, 0, 127);
	glTexCoord2f(0, 0);	glVertex3f(256, 0, 127);
	glTexCoord2f(1, 0);	glVertex3f(256, 0, -127);
	glTexCoord2f(1, 1);	glVertex3f(-255, 0, -127);
	//������� �������
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexCoord2f(0, 1);	glVertex3f(-255, 0, 127);
	glTexCoord2f(0, 0);	glVertex3f(256, 0, 127);
	glTexCoord2f(1, 0);	glVertex3f(256, 60, 127);
	glTexCoord2f(1, 1);	glVertex3f(-255, 60, 127);
	//������� �������
	glTexCoord2f(0, 1);	glVertex3f(-256, 0, -127);
	glTexCoord2f(0, 0);	glVertex3f(256, 0, -127);
	glTexCoord2f(1, 0);	glVertex3f(256, 60, -127);
	glTexCoord2f(1, 1);	glVertex3f(-256, 60, -127);
	//������ ������
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexCoord2f(0, 0);	glVertex3f(256, 60, 127);
	glTexCoord2f(1, 0);	glVertex3f(256, 0, 127);
	glTexCoord2f(1, 1);	glVertex3f(256, 0, -127);
	glTexCoord2f(0, 1);	glVertex3f(256, 60, -127);
	//�����
	glTexCoord2f(0, 0);	glVertex3f(-256, 60, 127);
	glTexCoord2f(1, 0);	glVertex3f(-256, 0, 127);
	glTexCoord2f(1, 1);	glVertex3f(-256, 0, -127);
	glTexCoord2f(0, 1);	glVertex3f(-256, 60, -127);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	gluDeleteQuadric(quadObj); //������� ������
	glutSwapBuffers();
}

void Initialize()
{
	//�������� ������
	TextureInit("data/T8-1.bmp", &texture[0]);
	TextureInit("data/T61.bmp", &texture[1]);
	TextureInit("data/T62.bmp", &texture[2]);
	//����
	TextureInit("data/T4.bmp", &texture[3]);
	TextureInit("data/T4-1.bmp", &texture[4]);
	TextureInit("data/T4-2.bmp", &texture[5]);
	//�������
	TextureInit("data/T2.bmp", &texture[6]);
	TextureInit("data/T3.bmp", &texture[7]);
	TextureInit("data/T5.bmp", &texture[8]);

	glClearColor(0, 0, 0, 1);
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Width / 2, Width / 2, -Height / 2, Height / 2, -600, 600);

	glRotatef(50, 1, -1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y)
{
	float step = 5;
	switch (key)
	{
		//�������
	case 'a': glTranslatef(-step, 0, 0);
		break;
	case 'd': glTranslatef(step, 0, 0);
		break;
	case 'w': glTranslatef(0, step, 0);
		break;
	case 's': glTranslatef(0, -step, 0);
		break;
	case 'q': glTranslatef(0, 0, -step);
		break;
	case 'e': glTranslatef(0, 0, step);
		break;
	case 'x': //���������
		if (xb<512)
			xb += 5;
		break;
	case 'z': //���������
		if (xb>0)
			xb -= 5;
		break;
	case ' ': 
		xb = 0;
		glLoadIdentity();	//����������� �������������� ������
		break;
	default: return;
	}
	glutPostRedisplay();
}

void SKeyboard(int key, int x, int y)
{
	switch (key)
	{
		//�������
	case GLUT_KEY_LEFT: glRotatef(1, 0, 1, 0);
		break;
	case GLUT_KEY_RIGHT: glRotatef(-1, 0, 1, 0);
		break;
	case GLUT_KEY_UP: glRotatef(1, 1, 0, 0);
		break;
	case GLUT_KEY_DOWN: glRotatef(-1, 1, 0, 0);
		break;
	case GLUT_KEY_PAGE_UP: glRotatef(1, 0, 0, 1);
		break;
	case GLUT_KEY_PAGE_DOWN: glRotatef(-1, 0, 0, 1);
		break;
		//���������������
	case GLUT_KEY_F1: glScalef(1.1, 1, 1);
		break;
	case GLUT_KEY_F2: glScalef(0.9, 1, 1);
		break;
	case GLUT_KEY_F3: glScalef(1, 1.1, 1);
		break;
	case GLUT_KEY_F4: glScalef(1, 0.9, 1);
		break;
	case GLUT_KEY_F5: glScalef(1, 1, 1.1);
		break;
	case GLUT_KEY_F6: glScalef(1, 1, 0.9);
		break;
	default: return;
	}
	glutPostRedisplay();
}

void setLight() //���������
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("x,z-����������,����������. C������,PgUp,PgDn - ��������. w,s,a,d-��������. ������-�����.");

	glutDisplayFunc(Display);
	//glutTimerFunc(20, Timer, 0);
	Initialize();
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);

	setLight(); //���������

	glutMainLoop();
	return 0;
}