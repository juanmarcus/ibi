/*
 * Framebuffer.h
 *
 *  Created on: Nov 5, 2009
 *      Author: juanmarcus
 */

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include "ibi.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/Texture.h"

namespace ibi
{

enum FB_status
{
	FB_COMPLETE, FB_INCOMPLETE
};

class Framebuffer
{
public:
	Framebuffer();
	~Framebuffer();

	void init();

	void enable();
	void disable();

	void setTarget(Texture* t);

	FB_status getStatus();
private:
	bool enabled;

	/**
	 * Generated OpenGL name.
	 */
	GLuint name;
};

} // namespace ibi

#endif /* FRAMEBUFFER_H_ */
