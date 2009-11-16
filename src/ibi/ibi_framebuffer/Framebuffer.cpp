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
	enabled(false)
{
	glewInit();
}

Framebuffer::~Framebuffer()
{
	glDeleteFramebuffersEXT(1, &name);
}

void Framebuffer::init()
{
	glGenFramebuffersEXT(1, &name);
}

void Framebuffer::bind()
{
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, name);
	// Bind target texture
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT,
			target->getTarget(), target->getGLName(), 0);
	checkStatus();
	// Save old viewport
	glGetIntegerv(GL_VIEWPORT, oldViewport);
	glViewport(0, 0, target->getWidth(), target->getHeight());
	enabled = true;
}

void Framebuffer::release()
{
	if (!enabled)
	{
		throw Exception("Framebuffer.cpp", "Problem finishing render.",
				"Trying to operate on a disabled framebuffer object.");
	}
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	// Restore old viewport
	glViewport(oldViewport[0], oldViewport[1], oldViewport[2], oldViewport[3]);
	enabled = false;
}

void Framebuffer::setTarget(Texture* t)
{
	this->target = t;
}

void Framebuffer::checkStatus()
{
	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

	if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		throw Exception("Framebuffer.cpp", "Framebuffer consistence problem.",
				"Framebuffer state incomplete.");
	}
}

} // namespace ibi
