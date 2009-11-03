/*
 * GLMode2D.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#include "GLMode2D.h"

namespace ibi
{

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
		glOrtho(0, 1, 0, 1, -1, 1);

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

} // namespace ibi
