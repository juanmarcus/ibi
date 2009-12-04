/*
 * FramebufferObject.h
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#ifndef FramebufferObject_H_
#define FramebufferObject_H_

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/Texture.h"

BEGIN_NAMESPACE_IBI

class FramebufferObject
{
public:
	FramebufferObject();
	~FramebufferObject();

	void init();

	void bind();
	void release();

	void setTarget(Texture* t);

	void checkStatus();
private:

	bool enabled;

	/**
	 * Generated OpenGL name.
	 */
	GLuint name;

	/*
	 * Texture to render to.
	 */
	Texture* target;

	/*
	 * Temporary viewport.
	 */
	int oldViewport[4];
};

END_NAMESPACE_IBI

#endif /* FramebufferObject_H_ */
