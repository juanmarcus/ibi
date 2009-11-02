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
#include <QtGui/QImage>
#include <QtOpenGL/QGLWidget>

using namespace ibi;

class TextureLoader_qt: public TextureLoader
{
	Texture* load(TextureLoadingInfo& info)
	{
		Texture* texture = new Texture();
		texture->setTarget(info.target);
		texture->init();

		String filename = boost::any_cast<String>(info.options["filename"]);

		QImage t;
		QImage b;

		if (!b.load(filename.c_str()))
		{
			// Error
		}

		t = QGLWidget::convertToGLFormat(b);

		GLuint name = texture->getGLName();

		glTexImage2D(info.target, 0, 3, t.width(), t.height(), 0, GL_RGBA,
				GL_UNSIGNED_BYTE, t.bits());
		glTexParameteri(info.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(info.target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		texture->setDimensions(t.width(), t.height());

		return texture;

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
