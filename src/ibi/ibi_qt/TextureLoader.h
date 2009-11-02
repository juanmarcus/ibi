/*
 * TextureLoader.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <QtOpenGL/QGLWidget>
#include "ibi_gl/Texture.h"
#include <string>
#include <iostream>

namespace ibi
{

class TextureLoader
{
public:
	TextureLoader(QGLWidget* glwidget = 0);
	~TextureLoader();

	void load(Texture& t);
	void loadRaw(Texture& t);
	void loadQt(Texture& t);
	void loadNrrd(Texture& t);
private:
	QGLWidget* glwidget;
};

} // namespace ibi

#endif /* TEXTURELOADER_H_ */
