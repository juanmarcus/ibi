#include "ibiQGLViewer.h"

namespace ibi
{

ibiQGLViewer::ibiQGLViewer(QWidget* parent) :
	QGLViewer(parent), desiredAspectRatio(0.0)
{
}

ibiQGLViewer::~ibiQGLViewer()
{
}

void ibiQGLViewer::start2DMode()
{
	mode2d.setScreenDimensions(width(), height());
	mode2d.enable();
}

void ibiQGLViewer::stop2DMode()
{
	mode2d.disable();
}

void ibiQGLViewer::resizeGL(int width, int height)
{
	QGLWidget::resizeGL(width, height);

	//	int side = qMin(width, height);
	//	glViewport((width - side) / 2, (height - side) / 2, side, side);

	if (desiredAspectRatio > 0.0)
	{
		if (width > height)
		{
			float actual_width = height * desiredAspectRatio;
			glViewport((width - actual_width) / 2.0, 0.0, actual_width, height);
		}
		else
		{
			float actual_height = width / desiredAspectRatio;
			glViewport(0.0, (height - actual_height) / 2.0, width,
					actual_height);
		}
	}
	else
	{
		glViewport(0, 0, GLint(width), GLint(height));
	}
	camera()->setScreenWidthAndHeight(this->width(), this->height());
}

void ibiQGLViewer::setDesiredAspectRatio(float ratio)
{
	this->desiredAspectRatio = ratio;
}

//void ibiQtSmartGLWidget::resizeGL(int w, int h)
//{
//	if (autoViewport)
//	{
//		setViewportAuto();
//	}
//}

//void ibiQtSmartGLWidget::setViewportAuto(bool keepAspect)
//{
//	if (keepAspect)
//	{
//		int width = size().width();
//		int height = size().height();
//		int side = qMin(width, height);
//		glViewport((width - side) / 2, (height - side) / 2, side, side);
//	}
//	else
//	{
//		// Stupid viewport setter
//		glViewport(0, 0, size().width(), size().height());
//	}
//}

} // namespace ibi
