#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include <boost/function.hpp>
#include "ibiQtSmartGLWidget.h"

typedef boost::function<void(void)> PaintFunctor;
typedef boost::function<void(void)> InitializeFunctor;
typedef boost::function<void(int w, int h)> ResizeFunctor;

class ibiQtFunctorGLWidget: public ibiQtSmartGLWidget
{
Q_OBJECT

public:
	ibiQtFunctorGLWidget(InitializeFunctor& init, ResizeFunctor& resize,
			PaintFunctor& a_painter);
	~ibiQtFunctorGLWidget();

	void paintGL();
	void initializeGL();
	void resizeGL(int w, int h);
private:
	InitializeFunctor& initer;
	ResizeFunctor& resizer;
	PaintFunctor& painter;
};

#endif // IBIQGLWIDGET_H
