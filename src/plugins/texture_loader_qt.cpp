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

class TextureLoader_qt: public TextureLoader
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

		GLuint name = texture->getGLName();

		glTexImage2D(info.target, 0, GL_RGBA, t.width(), t.height(), 0,
				GL_RGBA, GL_UNSIGNED_BYTE, t.bits());

		texture->setDimensions(t.width(), t.height());

	}
};

class TextureLoaderFactory_qt: public TextureLoaderFactory
{
	TextureLoader* create()
	{
		TextureLoader* loader = new TextureLoader_qt();
		return loader;
	}
};

extern "C"
{

void registerPlugin(TextureManager& manager)
{
	TextureLoaderFactory_qt* loaderF = new TextureLoaderFactory_qt();

	manager.registerTextureLoader(String("qt"), loaderF);
}

}
