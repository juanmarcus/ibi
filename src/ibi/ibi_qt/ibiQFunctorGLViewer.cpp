#include "ibiQFunctorGLViewer.h"

BEGIN_NAMESPACE_IBI

ibiQFunctorGLViewer::ibiQFunctorGLViewer(InitializeFunctor& a_initer,
		DrawFunctor& a_painter) :
	ibiQGLViewer(), initer(a_initer), drawer(a_painter)
{

}

ibiQFunctorGLViewer::~ibiQFunctorGLViewer()
{

}

void ibiQFunctorGLViewer::draw()
{
	drawer(this);
}

void ibiQFunctorGLViewer::init()
{
	initer(this);
}

//void ibiQFunctorGLViewer::resizeGL(int w, int h)
//{
//	resizer(this, w, h);
//}

END_NAMESPACE_IBI
