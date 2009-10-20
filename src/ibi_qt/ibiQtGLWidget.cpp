#include "ibiQtGLWidget.h"

ibiQtGLWidget::ibiQtGLWidget(InitializeFunctor& a_initer,
		ResizeFunctor& a_resizer, PaintFunctor& a_painter) :
	QGLWidget(), initer(a_initer), resizer(a_resizer), painter(a_painter)
{

}

ibiQtGLWidget::~ibiQtGLWidget()
{

}

void ibiQtGLWidget::paintGL()
{
	painter();
}

void ibiQtGLWidget::initializeGL()
{
	initer();
}

void ibiQtGLWidget::resizeGL(int w, int h)
{
	resizer(w, h);
}
