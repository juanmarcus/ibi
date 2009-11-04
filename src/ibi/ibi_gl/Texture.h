/*
 * Texture.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "ibi.h"
#include "ibi_gl.h"
#include <boost/any.hpp>
#include <map>

namespace ibi
{

/*
 * Loading time information for textures.
 */
struct TextureLoadingInfo
{
	/*
	 * Texture type.
	 *
	 * Used to select the loading plugin.
	 */
	std::string texture_type;

	/*
	 * Target GL enum.
	 *
	 * For instance GL_TEXTURE_2D.
	 */
	GLenum target;

	/*
	 * Custom loading options.
	 *
	 * Each plugin checks for the options it needs.
	 */
	std::map<String, boost::any> options;

};

class Texture
{
	friend class TextureLoader;
public:
	Texture();
	~Texture();

	void setTarget(GLenum target);
	void setDimensions(int w, int h, int d = 0);

	GLuint getGLName();

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
