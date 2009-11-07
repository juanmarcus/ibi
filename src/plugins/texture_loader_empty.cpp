/*
 * texture_loader_qt.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#include "ibi.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_texturemanager/TextureManager.h"
#include "ibi_gl/Texture.h"
#include <boost/any.hpp>

#include <iostream>

using namespace ibi;

class TextureLoader_empty: public TextureLoader
{
	void load(TextureLoadingInfo& info, Texture* texture)
	{
		int width = boost::any_cast<int>(info.options["width"]);
		int height = boost::any_cast<int>(info.options["height"]);
		GLint internalformat = boost::any_cast<GLint>(
				info.options["internalformat"]);

		//		std::cout << boost::any_cast<unsigned int>(info.options["format"]) << std::endl;
		//		std::cout << GL_RGBA << std::endl;
		GLenum format = boost::any_cast<int>(info.options["format"]);
		GLenum type = boost::any_cast<int>(info.options["type"]);

		glTexImage2D(info.target, 0, internalformat, width, height, 0, format,
				type, NULL);

		texture->setDimensions(width, height);

	}
};

class TextureLoaderFactory_empty: public TextureLoaderFactory
{
	TextureLoader* create()
	{
		TextureLoader* loader = new TextureLoader_empty();
		return loader;
	}
};

extern "C"
{

void registerPlugin(TextureManager& manager)
{
	TextureLoaderFactory_empty* loaderF = new TextureLoaderFactory_empty();

	manager.registerTextureLoader(String("empty"), loaderF);
}

}
