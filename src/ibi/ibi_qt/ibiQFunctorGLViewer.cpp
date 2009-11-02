#include "ibiQFunctorGLViewer.h"

namespace ibi
{

ibiQFunctorGLViewer::ibiQFunctorGLViewer(InitializeFunctor& a_initer,
		ResizeFunctor& a_resizer, PaintFunctor& a_painter) :
	ibiQGLViewer(), initer(a_initer), resizer(a_resizer), painter(a_painter)
{

}

ibiQFunctorGLViewer::~ibiQFunctorGLViewer()
{

}

void ibiQFunctorGLViewer::paintGL()
{
	painter(this);
}

void ibiQFunctorGLViewer::initializeGL()
{
	initer(this);
}

void ibiQFunctorGLViewer::resizeGL(int w, int h)
{
	resizer(this, w, h);
}

} // namespace ibi
