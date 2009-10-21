/*
 * GLMode2D.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: juanmarcus
 */

#include "GLMode2D.h"

#include <GL/gl.h>

GLMode2D::GLMode2D()
{

}

GLMode2D::~GLMode2D()
{

}

void GLMode2D::enable()
{
	// Save a copy of the projection matrix so that we can restore it
	// when it's time to do 3D rendering again.
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
}

void GLMode2D::disable()
{
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
