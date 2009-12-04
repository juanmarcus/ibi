/*
 * Texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include "Texture.h"
#include "ibi_error/Exception.h"

BEGIN_NAMESPACE_IBI

using namespace std;

Texture::Texture() :
	glname(0), dimension(2), width(0), height(0), depth(0)
{
	target = GL_TEXTURE_2D;
}

Texture::~Texture()
{
	glDeleteTextures(1, &glname);
}

void Texture::setGLName(GLuint name)
{
	this->glname = name;
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

void Texture::setDimension(int dim)
{
	this->dimension = dim;
}

int Texture::getDimension()
{
	return dimension;
}

int Texture::getWidth()
{
	return this->width;
}

int Texture::getHeight()
{
	return this->height;
}

int Texture::getDepth()
{
	return this->depth;
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
		throw Exception("Texture.cpp", "Problem with texture.",
				"Missing texture name.");
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
}

END_NAMESPACE_IBI
