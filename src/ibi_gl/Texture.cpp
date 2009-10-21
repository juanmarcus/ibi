/*
 * Texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: juanmarcus
 */

#include "Texture.h"
#include "ibi_error/Exception.h"

using namespace std;

Texture::Texture(FileFormat a_fileFormat, int a_width, int a_height) :
	fileFormat(a_fileFormat), glname(0), width(a_width), height(a_height)
{
	target = GL_TEXTURE_2D;
}

Texture::~Texture()
{

}

void Texture::setFilename(string filename)
{
	this->filename = filename;
}

void Texture::setDims(int w, int h)
{
	this->width = w;
	this->height = h;
}

void Texture::setFormat(FileFormat format)
{
	this->fileFormat = format;
}

void Texture::apply()
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

void Texture::init()
{
	// Generate a name
	glGenTextures(1, &this->glname);
	// Make current
	apply();
	// Set texture properties
	glTexParameterf(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}
