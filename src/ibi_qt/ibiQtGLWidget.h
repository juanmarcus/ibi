#ifndef IBIQGLWIDGET_H
#define IBIQGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <boost/function.hpp>

typedef boost::function<void(void)> Painter;

class ibiQtGLWidget: public QGLWidget
{
Q_OBJECT

public:
	ibiQtGLWidget(Painter& a_painter);
	~ibiQtGLWidget();

	void paintGL();
private:
	Painter& painter;
};

#endif // IBIQGLWIDGET_H
