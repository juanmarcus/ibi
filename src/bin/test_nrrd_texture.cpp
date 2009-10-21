/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>
#include <teem/nrrd.h>
#include "ibi_qt/ibiQtFunctorGLWidget.h"
#include "ibi_gl/Texture.h"
#include "ibi_gl2d/GLMode2D.h"

using namespace std;

Texture t(FF_NRRD);

struct paint
{
	GLMode2D mode;

	void operator()(ibiQtSmartGLWidget* widget)
	{
		mode.enable();

		t.apply();
//		glDisable(GL_TEXTURE_2D);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_QUADS);

		glTexCoord2d(0.0, 0.0);
		glVertex2d(0.0, 0.0);

		glTexCoord2d(1.0, 0.0);
		glVertex2d(1.0, 0.0);

		glTexCoord2d(1.0, 1.0);
		glVertex2d(1.0, 1.0);

		glTexCoord2d(0.0, 1.0);
		glVertex2d(0.0, 1.0);

		glEnd();

		mode.disable();
	}
};

struct init
{
	Nrrd* nin;

	void operator()(ibiQtSmartGLWidget* widget)
	{
		nin = nrrdNew();
		if (nrrdLoad(nin, "data/nrrd2d.nhdr", NULL))
		{
			char* err = biffGetDone(NRRD);
			cerr << err << endl;
			free(err);
		}

		t.setData(nin->data);
		t.setDims(nin->axis[0].size, nin->axis[1].size);
		widget->loadTexture(t);
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
