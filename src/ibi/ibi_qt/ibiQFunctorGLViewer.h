#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include <boost/function.hpp>
#include "ibiQGLViewer.h"

namespace ibi
{

typedef boost::function<void(ibiQGLViewer* widget)> DrawFunctor;
typedef boost::function<void(ibiQGLViewer* widget)> InitializeFunctor;
typedef boost::function<void(ibiQGLViewer* widget, int w, int h)> ResizeFunctor;

//struct Resizer_AutoViewport
//{
//	bool keepAspect;
//
//	Resizer_AutoViewport(bool a_keepAspect = true)
//	{
//		keepAspect = a_keepAspect;
//	}
//
//	void operator()(ibiQGLViewer* widget, int w, int h)
//	{
//		widget->setViewportAuto(keepAspect);
//	}
//};

class ibiQFunctorGLViewer: public ibiQGLViewer
{
Q_OBJECT

public:
	ibiQFunctorGLViewer(InitializeFunctor& init, DrawFunctor& a_painter);
	~ibiQFunctorGLViewer();

	void draw();
	void ibi_init();
private:
	InitializeFunctor& initer;
	DrawFunctor& drawer;
};

} // namespace ibi

#endif // IBIQGLWIDGET_H
