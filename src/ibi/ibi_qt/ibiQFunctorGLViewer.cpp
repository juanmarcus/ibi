#include "ibiQFunctorGLViewer.h"

namespace ibi
{

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

void ibiQFunctorGLViewer::ibi_init()
{
	initer(this);
}

//void ibiQFunctorGLViewer::resizeGL(int w, int h)
//{
//	resizer(this, w, h);
//}

} // namespace ibi
