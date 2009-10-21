#ifndef IBIQTSMARTGLWIDGET_H
#define IBIQTSMARTGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include "ibi_gl/Texture.h"
#include "TextureLoader.h"

class ibiQtSmartGLWidget: public QGLWidget
{
Q_OBJECT

public:
	ibiQtSmartGLWidget();
	~ibiQtSmartGLWidget();

	void loadTexture(Texture& t);
private:
	TextureLoader* textureLoader;
};

#endif // IBIQTSMARTGLWIDGET_H
