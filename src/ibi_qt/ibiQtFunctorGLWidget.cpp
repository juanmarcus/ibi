#include "ibiQtFunctorGLWidget.h"

ibiQtFunctorGLWidget::ibiQtFunctorGLWidget(InitializeFunctor& a_initer,
		ResizeFunctor& a_resizer, PaintFunctor& a_painter) :
	ibiQtSmartGLWidget(), initer(a_initer), resizer(a_resizer), painter(
			a_painter)
{

}

ibiQtFunctorGLWidget::~ibiQtFunctorGLWidget()
{

}

void ibiQtFunctorGLWidget::paintGL()
{
	painter();
}

void ibiQtFunctorGLWidget::initializeGL()
{
	initer();
}

void ibiQtFunctorGLWidget::resizeGL(int w, int h)
{
	resizer(w, h);
}
