/*
 * Texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include "Texture.h"
#include "ibi_error/Exception.h"

namespace ibi
{

using namespace std;

Texture::Texture() :
	glname(0), width(0), height(0)
{
	target = GL_TEXTURE_2D;
}

Texture::~Texture()
{
	glDeleteTextures(1, &glname);
}

void Texture::setTarget(GLenum target)
{
	this->target = target;
}

void Texture::setDimensions(int w, int h)
{
	this->width = w;
	this->height = h;
}

GLuint Texture::getGLName()
{
	return this->glname;
}

void Texture::enable()
{
	if (glname)
	{
		glEnable(target);
		glBindTexture(target, glname);
	}
	else
	{
		throw Exception("Problem with texture.");
	}
}

void Texture::disable()
{
	glDisable(target);
}

void Texture::init()
{
	// Generate a name
	glGenTextures(1, &this->glname);
	// Make current
	enable();
	// Set texture properties
	glTexParameterf(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

} // namespace ibi
