/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>
#include <fstream>

#include "ibi_qt/ibiQtFunctorGLWidget.h"
#include "ibi_gl/Texture.h"
#include "ibi_error/Exception.h"

using namespace std;

Texture t(FF_RAW);

struct paint
{
	void operator()(ibiQtSmartGLWidget* widget)
	{
		t.enable();

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

struct init
{
	void operator()(ibiQtSmartGLWidget* widget)
	{
		char* data;
		ifstream infile;
		infile.open("data/texture.raw", ios::binary);
		if (!infile)
		{
			throw Exception("Error opening file.");
		}

		// Load the data to memory
		data = new char[256 * 256 * 3];
		infile.read(data, 256 * 256 * 3);

		t.setData(data);
		t.setDims(256, 256);
		widget->loadTexture(t);

		delete[] data;
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
