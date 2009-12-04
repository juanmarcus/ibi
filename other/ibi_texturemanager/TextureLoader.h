/*
 * TextureLoader.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "ibi_internal.h"
#include "ibi_factory/Factory.h"
#include "ibi_gl/Texture.h"

BEGIN_NAMESPACE_IBI
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

END_NAMESPACE_IBI

#endif /* TEXTURELOADER_H_ */
