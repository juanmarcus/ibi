/*
 * Framebuffer.cpp
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#include "Framebuffer.h"

namespace ibi
{

Framebuffer::Framebuffer() :
	enabled(false)
{

}

Framebuffer::~Framebuffer()
{

}

void Framebuffer::init()
{
	glGenFramebuffersEXT(1, &name);
}

void Framebuffer::enable()
{
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, name);
	enabled = true;
}

void Framebuffer::disable()
{
	enabled = false;
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}

FB_status Framebuffer::getStatus()
{
	bool prev = enabled;
	enable();
	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

	if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		return FB_INCOMPLETE;
	}

	if (!prev)
	{
		disable();
	}

	return FB_COMPLETE;

}

} // namespace ibi
