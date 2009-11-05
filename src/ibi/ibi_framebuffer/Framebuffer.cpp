/*
 * Framebuffer.cpp
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#include "Framebuffer.h"
#include "ibi_error/Exception.h"

namespace ibi
{

Framebuffer::Framebuffer() :
	enabled(false), rendering(false)
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

void Framebuffer::setTarget(Texture* t)
{
	this->target = t;
}

void Framebuffer::beginRender()
{
	if (!enabled)
	{
		throw Exception("Trying to operate on a disabled framebuffer object.");
	}
	if (rendering)
	{
		throw Exception("Not matching beginRender endRender block.");
	}
	// Bind target texture
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT,
			target->getTarget(), target->getGLName(), 0);
	checkStatus();
	// Save old viewport
	glGetIntegerv(GL_VIEWPORT, oldViewport);
	glViewport(0, 0, target->getWidth(), target->getHeight());
	rendering = true;
}

void Framebuffer::endRender()
{
	if (!enabled)
	{
		throw Exception("Trying to operate on a disabled framebuffer object.");
	}
	if (!rendering)
	{
		throw Exception("Not matching beginRender endRender block.");
	}
	// Restore old viewport
	glViewport(oldViewport[0], oldViewport[1], oldViewport[2], oldViewport[3]);
	rendering = false;
}

void Framebuffer::checkStatus()
{
	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

	if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		throw Exception("Framebuffer state incomplete.");
	}
}

} // namespace ibi
