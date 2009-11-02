#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include "ibi.h"
#include <boost/function.hpp>
#include "ibiQGLViewer.h"

namespace ibi
{

typedef boost::function<void(ibiQGLViewer* widget)> PaintFunctor;
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
	ibiQFunctorGLViewer(InitializeFunctor& init, ResizeFunctor& resize,
			PaintFunctor& a_painter);
	~ibiQFunctorGLViewer();

	void paintGL();
	void initializeGL();
	void resizeGL(int w, int h);
private:
	InitializeFunctor& initer;
	ResizeFunctor& resizer;
	PaintFunctor& painter;
};

} // namespace ibi

#endif // IBIQGLWIDGET_H
