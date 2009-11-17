/*
 * FramebufferObject.cpp
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#include "FramebufferObject.h"
#include "ibi_error/Exception.h"

namespace ibi
{

FramebufferObject::FramebufferObject() :
	enabled(false)
{
	glewInit();
}

FramebufferObject::~FramebufferObject()
{
	glDeleteFramebuffersEXT(1, &name);
}

void FramebufferObject::init()
{
	glGenFramebuffersEXT(1, &name);
}

void FramebufferObject::bind()
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

void FramebufferObject::release()
{
	if (!enabled)
	{
		throw Exception("FramebufferObject.cpp", "Problem finishing render.",
				"Trying to operate on a disabled FramebufferObject object.");
	}
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	// Restore old viewport
	glViewport(oldViewport[0], oldViewport[1], oldViewport[2], oldViewport[3]);
	enabled = false;
}

void FramebufferObject::setTarget(Texture* t)
{
	this->target = t;
}

void FramebufferObject::checkStatus()
{
	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

	if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
	{
		throw Exception("FramebufferObject.cpp",
				"FramebufferObject consistence problem.",
				"FramebufferObject state incomplete.");
	}
}

} // namespace ibi
