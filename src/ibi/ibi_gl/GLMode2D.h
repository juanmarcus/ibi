/*
 * GLMode2D.h
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GLMODE2D_H_
#define GLMODE2D_H_

#include "ibi.h"
#include "ibi_gl.h"

namespace ibi
{

class GLMode2D
{
public:
	GLMode2D();
	~GLMode2D();

	void setScreenDimensions(int w, int h);

	void enable();
	void disable();

private:
	bool active;

	int width;
	int height;

};

} // namespace ibi

#endif /* GLMODE2D_H_ */
