#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include "ibi.h"
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
	void init();
private:
	InitializeFunctor& initer;
	DrawFunctor& drawer;
};

} // namespace ibi

#endif // IBIQGLWIDGET_H
