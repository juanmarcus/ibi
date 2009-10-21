#include "ibiQtSmartGLWidget.h"

ibiQtSmartGLWidget::ibiQtSmartGLWidget() :
	QGLWidget()
{
	textureLoader = new TextureLoader(this);
	autoViewport = true;
}

ibiQtSmartGLWidget::~ibiQtSmartGLWidget()
{
	delete textureLoader;
}

void ibiQtSmartGLWidget::loadTexture(Texture& t)
{
	textureLoader->load(t);
}

void ibiQtSmartGLWidget::resizeGL(int w, int h)
{
	if (autoViewport)
	{
		setViewportAuto();
	}
}

void ibiQtSmartGLWidget::setViewportAuto()
{
	// Stupid viewport setter
	glViewport(0, 0, size().width(), size().height());
}
