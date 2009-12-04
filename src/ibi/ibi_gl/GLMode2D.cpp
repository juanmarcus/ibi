/*
 * GLMode2D.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#include "GLMode2D.h"

BEGIN_NAMESPACE_IBI

GLMode2D::GLMode2D() :
	active(false), width(0), height(0)
{

}

GLMode2D::~GLMode2D()
{

}

void GLMode2D::setScreenDimensions(int w, int h)
{
	this->width = w;
	this->height = h;
}

void GLMode2D::enable()
{
	if (!active)
	{
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, width, 0, height, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Make sure depth testing and lighting are disabled for 2D rendering until
		// we are finished rendering in 2D
		glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);

		active = true;
	}
}

void GLMode2D::disable()
{
	if (active)
	{
		// Restore lighting and depth testing state
		glPopAttrib();

		// Restore matrices
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		active = false;
	}
}

void GLMode2D::drawFullScreenQuad()
{
	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0);
	glVertex2d(0.0, 0.0);

	glTexCoord2d(1.0, 0.0);
	glVertex2d(width, 0.0);

	glTexCoord2d(1.0, 1.0);
	glVertex2d(width, height);

	glTexCoord2d(0.0, 1.0);
	glVertex2d(0.0, height);

	glEnd();
}

END_NAMESPACE_IBI
