/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>

#include "ibi_qt/ibiQtGLWidget.h"
#include "ibi_gl/Texture.h"
#include "ibi_gl/TextureLoader.h"

using namespace std;

Texture t(FF_RAW);
TextureLoader loader;

struct paint
{
	void operator()()
	{
		t.apply();

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0);
		glVertex2d(-1.0, -1.0);
		glTexCoord2d(1.0, 0.0);
		glVertex2d(+1.0, -1.0);
		glTexCoord2d(1.0, 1.0);
		glVertex2d(+1.0, +1.0);
		glTexCoord2d(0.0, 1.0);
		glVertex2d(-1.0, +1.0);

		glEnd();
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
		t.setFilename("data/texture.raw");
		t.setDims(256, 256);
		loader.load(t);
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
