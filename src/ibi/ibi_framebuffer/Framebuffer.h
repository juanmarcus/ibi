/*
 * Framebuffer.h
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/Texture.h"

namespace ibi
{

class Framebuffer
{
public:
	Framebuffer();
	~Framebuffer();

	void init();

	void enable();
	void disable();

	void beginRender();
	void endRender();

	void setTarget(Texture* t);

	void checkStatus();
private:

	bool enabled;

	bool rendering;

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

} // namespace ibi

#endif /* FRAMEBUFFER_H_ */
