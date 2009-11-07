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
#include "nrrdGLutils.h"

using namespace ibi;

class TextureLoader_nrrd: public TextureLoader
{
	void load(TextureLoadingInfo& info, Texture* texture)
	{
		Nrrd* nin = boost::any_cast<Nrrd*>(info.options["nrrd"]);
		//		Nrrd* nout = nrrdNew();
		//		nrrdConvert(nout,nin,nrrdTypeUChar);
		//		nrrdQuantize(nout, nin, 0, 8);

		int width = nin->axis[0].size;
		int height = nin->axis[1].size;
		int elemsize = nrrdElementSize(nin);

		// Copy memory upside-down
		char* tmpdata = (char*) malloc(width * height * elemsize);

		char* src = (char*) nin->data;
		for (int i = 0; i < height; ++i)
		{
			int linesize = width * elemsize;
			memcpy(&tmpdata[(height - i - 1) * linesize], &src[i * linesize],
					linesize);
		}

		GLuint name = texture->getGLName();

		glTexImage2D(info.target, 0, 1, width, height, 0, GL_LUMINANCE,
				convert_type_to_enum(nin->type), tmpdata);

		texture->setDimensions(width, height);

		free(tmpdata);
		//		nrrdNuke(nout);

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
