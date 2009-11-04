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

class TextureLoader_nrrd3D: public TextureLoader
{
	Texture* load(TextureLoadingInfo& info)
	{
		Texture* texture = new Texture();
		texture->setTarget(info.target);
		texture->init();

		Nrrd* nin = boost::any_cast<Nrrd*>(info.options["nrrd"]);
		//		Nrrd* nout = nrrdNew();
		//		nrrdConvert(nout,nin,nrrdTypeUChar);
		//		nrrdQuantize(nout, nin, 0, 8);

		int width = nin->axis[0].size;
		int height = nin->axis[1].size;
		int depth = nin->axis[2].size;

		// TODO Copy memory upside-down
		//		char* tmpdata = (char*) malloc(width * height * depth * elemsize);
		//
		//		for (int i = 0; i < height; ++i)
		//		{
		//			char* src = (char*) nin->data;
		//			int linesize = width * elemsize;
		//			memcpy(&tmpdata[(height - i - 1) * linesize], &src[i * linesize],
		//					linesize);
		//		}

//		GLuint name = texture->getGLName();

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage3D(info.target, 0, 1, width, height, depth, 0, GL_LUMINANCE,
				convert_type_to_enum(nin->type), nin->data);

		texture->setDimensions(width, height, depth);

		//		free( tmpdata);
		//		nrrdNuke(nout);

		return texture;

	}
};

class TextureLoaderFactory_nrrd3D: public TextureLoaderFactory
{
	TextureLoader* create()
	{
		TextureLoader* loader = new TextureLoader_nrrd3D();
		return loader;
	}
};

extern "C"
{

void registerPlugin(TextureManager& manager)
{
	TextureLoaderFactory_nrrd3D* loaderF = new TextureLoaderFactory_nrrd3D();

	manager.registerTextureLoader(String("nrrd3D"), loaderF);
}

}
