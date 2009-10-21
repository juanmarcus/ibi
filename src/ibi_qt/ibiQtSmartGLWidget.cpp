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

void ibiQtSmartGLWidget::setViewportAuto(bool keepAspect)
{
	if (keepAspect)
	{
		int width = size().width();
		int height = size().height();
		int side = qMin(width, height);
		glViewport((width - side) / 2, (height - side) / 2, side, side);
	}
	else
	{
		// Stupid viewport setter
		glViewport(0, 0, size().width(), size().height());
	}
}
