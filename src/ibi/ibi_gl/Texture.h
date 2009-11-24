/*
 * Texture.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "ibi_internal.h"
#include "ibi_gl.h"
#include <boost/any.hpp>
#include <map>

namespace ibi
{

class Texture
{
	friend class TextureLoader;
public:
	Texture();
	~Texture();

	void setGLName(GLuint name);
	void setTarget(GLenum target);
	void setDimensions(int w, int h = 0, int d = 0);
	void setDimension(int dim);

	GLuint getGLName();
	GLenum getTarget();
	int getDimension();
	int getWidth();
	int getHeight();
	int getDepth();

	void init();
	void enable();
	void disable();
private:
	/*
	 * Generated OpenGL name.
	 */
	GLuint glname;

	/*
	 * Target texture enum.
	 *
	 * Defaults to GL_TEXTURE_2D.
	 */
	GLenum target;

	/*
	 * Texture dimension.
	 */
	int dimension;

	/*
	 * Texture width in pixels.
	 */
	int width;

	/*
	 * Texture height in pixels.
	 */
	int height;

	/*
	 * Texture depth in pixels.
	 *
	 * Used only for 3D textures.
	 */
	int depth;
};

} // namespace ibi

#endif /* TEXTURE_H_ */
