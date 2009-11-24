/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include "ibi_gl/ibi_gl.h"
#include <QtGui/QApplication>
#include <iostream>
#include <teem/nrrd.h>
#include "ibi_qt/ibiQFunctorGLViewer.h"
#include "ibi_gl/Texture.h"
#include "ibi_gl/TextureLoader.h"
#include "ibi_gl/GLMode2D.h"

using namespace std;
using namespace ibi;

Texture* t = 0;

struct draw
{
	void operator()(ibiQGLViewer* widget)
	{
		glColor3d(1.0, 1.0, 1.0);

		t->enable();

		widget->start2DMode();

		widget->drawFullScreenQuad();

//		glBegin(GL_QUADS);
//
//		glTexCoord2d(0.0, 0.0);
//		glVertex2d(0.0, 0.0);
//
//		glTexCoord2d(1.0, 0.0);
//		glVertex2d(1.0, 0.0);
//
//		glTexCoord2d(1.0, 1.0);
//		glVertex2d(1.0, 1.0);
//
//		glTexCoord2d(0.0, 1.0);
//		glVertex2d(0.0, 1.0);
//
//		glEnd();

		widget->stop2DMode();
	}
};

struct init
{
	Nrrd* nin;

	void operator()(ibiQGLViewer* widget)
	{
		nin = nrrdNew();
		if (nrrdLoad(nin, "data/nrrd2d_8.nhdr", NULL))
		{
			char* err = biffGetDone(NRRD);
			cerr << err << endl;
			free(err);
		}

		TextureLoadingInfo tinfo;
		tinfo.target = GL_TEXTURE_2D;

		t = TextureLoader::load(tinfo);

		widget->setDesiredAspectRatio(1.0);
	}
};

InitializeFunctor initer = init();
DrawFunctor drawer = draw();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQFunctorGLViewer w(initer, drawer);

	w.showMaximized();

	return app.exec();
}
