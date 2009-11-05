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
	glname(0), width(0), height(0), depth(0)
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

void Texture::setDimensions(int w, int h, int d)
{
	this->width = w;
	this->height = h;
	this->depth = d;
}

int Texture::getWidth()
{
	return this->width;
}

int Texture::getHeight()
{
	return this->height;
}

GLuint Texture::getGLName()
{
	return this->glname;
}

GLenum Texture::getTarget()
{
	return this->target;
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
	glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

} // namespace ibi
