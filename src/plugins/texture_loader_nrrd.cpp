/*
 * texture_loader_qt.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#include "ibi.h"
#include "ibi_texturemanager/TextureManager.h"
#include "ibi_gl/Texture.h"
#include <boost/any.hpp>
#include <teem/nrrd.h>

using namespace ibi;

class TextureLoader_nrrd: public TextureLoader
{
	Texture* load(TextureLoadingInfo& info)
	{
		Texture* texture = new Texture();
		texture->setTarget(info.target);
		texture->init();

		Nrrd* nin = boost::any_cast<Nrrd*>(info.options["nrrd"]);
		Nrrd* nout = nrrdNew();
		NrrdRange* range = nrrdRangeNewSet(nin, 0);
		nrrdQuantize(nout, nin, 0, 8);

		int width = nout->axis[0].size;
		int height = nout->axis[1].size;
		int elemsize = nrrdElementSize(nout);

		// Copy memory upside-down
		char* tmpdata = (char*) malloc(width * height * elemsize);

		for (int i = 0; i < height; ++i)
		{
			char* src = (char*) nout->data;
			int linesize = width * elemsize;
			memcpy(&tmpdata[(height - i - 1) * linesize], &src[i * linesize],
					linesize);
		}

		GLuint name = texture->getGLName();

		glTexImage2D(info.target, 0, 1, width, height, 0, GL_LUMINANCE,
				GL_UNSIGNED_BYTE, tmpdata);

		texture->setDimensions(width, height);

		free(tmpdata);
		nrrdNuke(nout);

		return texture;

	}
};

class TextureLoaderFactory_nrrd: public TextureLoaderFactory
{
	TextureLoader* create()
	{
		TextureLoader* loader = new TextureLoader_nrrd();
		return loader;
	}
};

extern "C"
{

void registerPlugin(TextureManager& manager)
{
	TextureLoaderFactory_nrrd* loaderF = new TextureLoaderFactory_nrrd();

	manager.registerTextureLoader(String("nrrd"), loaderF);
}

}
