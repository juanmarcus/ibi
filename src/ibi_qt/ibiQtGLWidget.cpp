#include "ibiQtGLWidget.h"

ibiQtGLWidget::ibiQtGLWidget(PaintFunctor& a_painter) :
	QGLWidget(), painter(a_painter)
{

}

ibiQtGLWidget::~ibiQtGLWidget()
{

}

void ibiQtGLWidget::paintGL()
{
	painter();
}
