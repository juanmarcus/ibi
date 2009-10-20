/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>

#include "ibi_qt/ibiQtGLWidget.h"
#include "ibi_gl/Texture.h"

struct paint
{
	Texture t;

	void operator()()
	{
		t.set();
	}
};

struct resize
{
	void operator()(int w, int h)
	{

	}
};

struct init
{
	void operator()()
	{
	}
};

InitializeFunctor initer = init();
ResizeFunctor resizer = resize();
PaintFunctor painter = paint();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQtGLWidget w(initer, resizer, painter);

	w.showMaximized();

	return app.exec();
}
