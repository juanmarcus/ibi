/*
 * Sprite.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: juanmarcus
 */

#include "Sprite.h"

#include <GL/glu.h>

Sprite::Sprite()
{
	texture = 0;
}

Sprite::~Sprite()
{
	glDeleteTextures(1, &texture);
}

void Sprite::render(int xpos, int ypos)
{
//	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(1.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(1.0, 1.0);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.0, 1.0);

	glEnd();

	glPopMatrix();
}

#include <iostream>

using namespace std;

void Sprite::loadFrom(Nrrd* nin)
{
	int width = nin->axis[0].size;
	int height = nin->axis[1].size;
	unsigned char* data = (unsigned char*) nin->data;

	// setup texture mapping
	glEnable(GL_TEXTURE_2D);

	// Generate a texture name
	glGenTextures(1, &texture);

	// select our current texture
	glBindTexture(GL_TEXTURE_2D, texture);

	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// when texture area is small, bilinear filter the closest MIP map
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// when texture area is large, bilinear filter the first MIP map
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// The texture ends at the edges (clamp)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// build our texture MIP maps
	//	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_LUMINANCE8, width, height, GL_LUMINANCE,
	//			GL_UNSIGNED_BYTE, data);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width, height, 0,
			GL_LUMINANCE, GL_UNSIGNED_BYTE, data);

	//	return texture;
}
