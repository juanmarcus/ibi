/*
 * TestScene.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef TESTSCENE_H_
#define TESTSCENE_H_

class TestScene
{
public:
	static inline void draw()
	{
		glEnable( GL_LIGHTING);
		glEnable( GL_LIGHT0);

		GLfloat diffuse[3] =
		{ 1.0, 1.0, 1.0 };
		GLfloat black[3] =
		{ 0.0, 0.0, 0.0 };
		GLfloat ambient[] =
		{ 0.2f, 0.2f, 0.2f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_SPECULAR, diffuse);
		GLfloat lightPosition[4];

		lightPosition[0] = 0;
		lightPosition[1] = 3;
		lightPosition[2] = 0;
		lightPosition[3] = 1;
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

		glDisable( GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT, GL_EMISSION, diffuse);

		GLfloat materialDiffuseRed[3] =
		{ 1.0, 0.0, 0.0 };
		GLfloat materialDiffuseGreen[3] =
		{ 0.0, 1.0, 0.0 };
		GLfloat materialDiffuseBlue[3] =
		{ 0.0, 0.0, 1.0 };
		GLfloat materialDiffuseYellow[3] =
		{ 1.0, 1.0, 0.0 };
		GLfloat materialDiffuseMagenta[3] =
		{ 1.0, 0.0, 1.0 };
		GLfloat materialDiffusef[3] =
		{ 0.0, 1.0, 1.0 };
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_SPECULAR, diffuse);
		glMaterialf(GL_FRONT, GL_SHININESS, 60);

		glTranslatef(2, 0, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuseRed);
		glutSolidTeapot(1.0f);
		glTranslatef(0, 2, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuseGreen);
		glutSolidTeapot(1.0f);
		glTranslatef(0, -4, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuseBlue);
		glutSolidTeapot(1.0f);
		glTranslatef(0, 2, 0);
		glTranslatef(-4, 0, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuseYellow);
		glutSolidTeapot(1.0f);
		glTranslatef(0, 2, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuseMagenta);
		glutSolidTeapot(1.0f);
		glTranslatef(0, -4, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffusef);
		glutSolidTeapot(1.0f);
	}
};

#endif /* TESTSCENE_H_ */
