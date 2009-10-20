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

Painter p = paint();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQtGLWidget w(p);

	w.showMaximized();

	return app.exec();
}
