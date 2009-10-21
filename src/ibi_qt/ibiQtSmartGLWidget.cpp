#include "ibiQtSmartGLWidget.h"

ibiQtSmartGLWidget::ibiQtSmartGLWidget() :
	QGLWidget()
{
	textureLoader = new TextureLoader(this);
}

ibiQtSmartGLWidget::~ibiQtSmartGLWidget()
{
	delete textureLoader;
}

void ibiQtSmartGLWidget::loadTexture(Texture& t)
{
	textureLoader->load(t);
}
