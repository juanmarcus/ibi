#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <boost/function.hpp>

typedef boost::function<void(void)> PaintFunctor;

class ibiQtGLWidget: public QGLWidget
{
Q_OBJECT

public:
	ibiQtGLWidget(PaintFunctor& a_painter);
	~ibiQtGLWidget();

	void paintGL();
private:
	PaintFunctor& painter;
};

#endif // IBIQGLWIDGET_H
