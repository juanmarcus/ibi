/*
 * texture_loader_qt.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#include "ibi.h"
#include "ibi_texturemanager/TextureManager.h"
#include "ibi_gl/Texture.h"
#include "ibi_error/Exception.h"
#include <boost/any.hpp>
#include <QtGui/QImage>
#include <QtOpenGL/QGLWidget>

using namespace ibi;

class TextureLoader_transfer_func: public TextureLoader
{
	void load(TextureLoadingInfo& info, Texture* texture)
	{
		String filename = boost::any_cast<String>(info.options["filename"]);

		QImage t;
		QImage b;

		if (!b.load(filename.c_str()))
		{
			throw Exception("File not found");
		}

		t = QGLWidget::convertToGLFormat(b);

		glTexImage1D(info.target, 0, GL_RGB, t.width(), 0, GL_RGBA,
				GL_UNSIGNED_BYTE, t.bits());

		texture->setDimensions(t.width());

	}
};

class TextureLoaderFactory_transfer_func: public TextureLoaderFactory
{
	TextureLoader* create()
	{
		TextureLoader* loader = new TextureLoader_transfer_func();
		return loader;
	}
};

extern "C"
{

void registerPlugin(TextureManager& manager)
{
	TextureLoaderFactory_transfer_func* loaderF =
			new TextureLoaderFactory_transfer_func();

	manager.registerTextureLoader(String("transfer_func"), loaderF);
}

}
