/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>

#include "ibi_qt/ibiQtFunctorGLWidget.h"
#include "ibi_gl/Texture.h"

using namespace std;

Texture t(FF_QT);

struct paint
{
	void operator()(ibiQtSmartGLWidget* widget)
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
	void operator()(ibiQtSmartGLWidget* widget, int w, int h)
	{

	}
};

struct init
{
	void operator()(ibiQtSmartGLWidget* widget)
	{
		t.setFilename("data/image.png");
		widget->loadTexture(t);
	}
};

InitializeFunctor initer = init();
ResizeFunctor resizer = resize();
PaintFunctor painter = paint();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQtFunctorGLWidget w(initer, resizer, painter);

	w.showMaximized();

	return app.exec();
}
