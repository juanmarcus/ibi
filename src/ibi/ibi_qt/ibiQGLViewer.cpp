#include "ibiQGLViewer.h"

#include "ibi_error/Exception.h"
#include "ibi_gl/TextureLoader.h"

BEGIN_NAMESPACE_IBI

ibiQGLViewer::ibiQGLViewer(QWidget *parent, const QGLWidget *shareWidget,
		Qt::WFlags flags) :
	QGLViewer(parent, shareWidget, flags), desiredAspectRatio(0.0)
{

}

ibiQGLViewer::ibiQGLViewer(QGLContext *context, QWidget *parent,
		const QGLWidget *shareWidget, Qt::WFlags flags) :
	QGLViewer(context, parent, shareWidget, flags), desiredAspectRatio(0.0)
{

}

ibiQGLViewer::ibiQGLViewer(const QGLFormat &format, QWidget *parent,
		const QGLWidget *shareWidget, Qt::WFlags flags) :
	QGLViewer(format, parent, shareWidget, flags), desiredAspectRatio(0.0)
{

}

ibiQGLViewer::~ibiQGLViewer()
{
}

void ibiQGLViewer::start2DMode()
{
	mode2d.enable();
}

void ibiQGLViewer::stop2DMode()
{
	mode2d.disable();
}

void ibiQGLViewer::drawFullScreenQuad()
{
	mode2d.drawFullScreenQuad();
}

Vector3 ibiQGLViewer::normalizedViewportCoordinates(int x, int y)
{
	int vPort[4];

	glGetIntegerv(GL_VIEWPORT, vPort);

	Vector3 result;
	result.x = Real(x - vPort[0]) / Real(vPort[2]);
	result.y = 1.0 - (Real(y - vPort[1]) / Real(vPort[3]));
	result.z = 0;

	return result;
}

Vector3 ibiQGLViewer::absoluteViewportCoordinates(Vector3& point)
{
	int vPort[4];

	glGetIntegerv(GL_VIEWPORT, vPort);

	Vector3 result;
	result.x = (point.x * vPort[2]);
	result.y = (point.y * vPort[3]);
	result.z = 0;

	return result;
}

void ibiQGLViewer::resizeGL(int width, int height)
{
	QGLWidget::resizeGL(width, height);

	//	int side = qMin(width, height);
	//	glViewport((width - side) / 2, (height - side) / 2, side, side);

	if (desiredAspectRatio > 0.0)
	{
		if (width > (desiredAspectRatio * height))
		{
			float actual_width = height * desiredAspectRatio;
			glViewport((width - actual_width) / 2.0, 0.0, actual_width, height);
			camera()->setScreenWidthAndHeight(actual_width, height);
			mode2d.setScreenDimensions(actual_width, height);
		}
		else
		{
			float actual_height = width / desiredAspectRatio;
			glViewport(0.0, (height - actual_height) / 2.0, width,
					actual_height);
			camera()->setScreenWidthAndHeight(width, actual_height);
			mode2d.setScreenDimensions(width, actual_height);
		}
	}
	else
	{
		glViewport(0, 0, GLint(width), GLint(height));
		camera()->setScreenWidthAndHeight(width, height);
		mode2d.setScreenDimensions(width, height);
	}
}

void ibiQGLViewer::setDesiredAspectRatio(float ratio)
{
	this->desiredAspectRatio = ratio;
}

void ibiQGLViewer::saveViewport()
{
	glGetIntegerv(GL_VIEWPORT, savedViewport);
}

void ibiQGLViewer::restoreViewport()
{
	glViewport(savedViewport[0], savedViewport[1], savedViewport[2],
			savedViewport[3]);
}

Texture* ibiQGLViewer::loadTexture(TextureLoadingInfo& info)
{
	makeCurrent();
	return TextureLoader::load(info);
}

END_NAMESPACE_IBI
