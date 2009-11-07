/*
 * TextureLoader.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "ibi.h"
#include "ibi_factory/Factory.h"
#include "ibi_gl/Texture.h"

namespace ibi
{

/*
 * Texture loader interface.
 */
class TextureLoader
{
public:
	virtual void load(TextureLoadingInfo& info, Texture* t) = 0;
};

/*
 * Creates texture loaders.
 */
typedef Factory<TextureLoader> TextureLoaderFactory;

} // namespace ibi

#endif /* TEXTURELOADER_H_ */
