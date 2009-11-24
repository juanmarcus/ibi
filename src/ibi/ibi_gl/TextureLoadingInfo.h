/*
 * TextureLoadingInfo.h
 *
 *  Created on: Nov 23, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURELOADINGINFO_H_
#define TEXTURELOADINGINFO_H_

#include "ibi_internal.h"
#include "ibi_gl.h"

namespace ibi
{

/*
 * Loading time information for textures.
 */
class TextureLoadingInfo
{
public:
	TextureLoadingInfo();
	virtual ~TextureLoadingInfo();
public:
	/*
	 * Target GL enum.
	 *
	 * For instance GL_TEXTURE_2D.
	 */
	GLenum target;

	/*
	 * Number of dimensions;
	 */
	int dim;

	/*
	 * Texture width.
	 */
	int width;

	/*
	 * Texture height.
	 *
	 * Does not apply to 1D textures.
	 */
	int height;

	/*
	 * Texture depth.
	 *
	 * Does not apply to 2D textures.
	 */
	int depth;

	/*
	 * Mipmap level.
	 */
	int level;

	/*
	 * Format to represent texture internally.
	 */
	int internalformat;

	/*
	 * Border width.
	 */
	int border;

	/*
	 * Data format on memory.
	 */
	GLenum format;

	/*
	 * Data type on memory.
	 */
	GLenum type;

	/*
	 * Actual data.
	 */
	void* data;

	/*
	 * Determines of data should be destroyed after loading.
	 */
	bool destroydata;
};

} // namespace ibi

#endif /* TEXTURELOADINGINFO_H_ */
