#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <boost/function.hpp>

typedef boost::function<void(void)> PaintFunctor;
typedef boost::function<void(void)> InitializeFunctor;
typedef boost::function<void(int w, int h)> ResizeFunctor;

class ibiQtGLWidget: public QGLWidget
{
Q_OBJECT

public:
	ibiQtGLWidget(InitializeFunctor& init, ResizeFunctor& resize,
			PaintFunctor& a_painter);
	~ibiQtGLWidget();

	void paintGL();
	void initializeGL();
	void resizeGL(int w, int h);
private:
	InitializeFunctor& initer;
	ResizeFunctor& resizer;
	PaintFunctor& painter;
};

#endif // IBIQGLWIDGET_H
