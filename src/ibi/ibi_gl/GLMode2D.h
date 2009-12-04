/*
 * GLMode2D.h
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GLMODE2D_H_
#define GLMODE2D_H_

#include "ibi_internal.h"
#include "ibi_gl.h"

BEGIN_NAMESPACE_IBI

class GLMode2D
{
public:
	GLMode2D();
	~GLMode2D();

	void setScreenDimensions(int w, int h);

	void enable();
	void disable();

	void drawFullScreenQuad();

private:
	bool active;

	int width;
	int height;

};

END_NAMESPACE_IBI

#endif /* GLMODE2D_H_ */
