/*
 * TextureLoader.h
 *
 *  Created on: Nov 23, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "ibi_internal.h"
#include "ibi_error/Exception.h"
#include "Texture.h"
#include "TextureLoadingInfo.h"

namespace ibi
{

class TextureLoader
{
public:
	static inline Texture* load(TextureLoadingInfo& info)
	{
		// Create and init texture
		Texture* t = new Texture();
		t->setTarget(info.target);
		t->setDimensions(info.width, info.height, info.depth);
		t->setDimension(info.dim);
		t->init();

		load(t, info.level, info.internalformat, info.border, info.format,
				info.type, info.data);

		if (info.destroydata)
		{
			delete[] (char*)info.data;
			info.data = 0;
		}

		return t;
	}

	static inline void load(Texture* t, int level, int internalformat,
			int border, GLenum format, GLenum type, void* data)
	{
		// Enable texture
		t->enable();

		int dim = t->getDimension();
		switch (dim)
		{
		case 1:
			load1D(t, level, internalformat, border, format, type, data);
			break;
		case 2:
			load2D(t, level, internalformat, border, format, type, data);
			break;
		case 3:
			load3D(t, level, internalformat, border, format, type, data);
			break;
		default:
			throw Exception("TextureLoader.h", "Problem loading texture.",
					"Wrong texture dimension.");
		}

		// Set texture parameters
		glTexParameteri(t->getTarget(), GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(t->getTarget(), GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// Disable texture
		t->disable();
	}

private:
	static inline void load1D(Texture* t, int level, int internalformat,
			int border, GLenum format, GLenum type, void* data)
	{
		glTexImage1D(t->getTarget(), level, internalformat, t->getWidth(),
				border, format, type, data);
	}

	static inline void load2D(Texture* t, int level, int internalformat,
			int border, GLenum format, GLenum type, void* data)
	{
		glTexImage2D(t->getTarget(), level, internalformat, t->getWidth(),
				t->getHeight(), border, format, type, data);
	}

	static inline void load3D(Texture* t, int level, int internalformat,
			int border, GLenum format, GLenum type, void* data)
	{
		glTexImage3D(t->getTarget(), level, internalformat, t->getWidth(),
				t->getHeight(), t->getDepth(), border, format, type, data);
	}
};

} // namespace ibi

#endif /* TEXTURELOADER_H_ */
