/*
 * test_geometry.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>

#include "ibi_qt/ibiQtFunctorGLWidget.h"
#include "ibi_geometry/Ray.h"
#include "ibi_gl/GeometryDrawer.h"

using namespace std;

GeometryDrawer drawer;
Ray ray;

struct paint
{
	void operator()(ibiQtSmartGLWidget* widget)
	{
		drawer.draw(ray);
	}
};

struct init
{
	void operator()(ibiQtSmartGLWidget* widget)
	{
	}
};

InitializeFunctor initer = init();
ResizeFunctor resizer = Resizer_AutoViewport();
PaintFunctor painter = paint();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQtFunctorGLWidget w(initer, resizer, painter);

	w.showMaximized();

	return app.exec();
}
