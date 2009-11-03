/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <iostream>
#include <teem/nrrd.h>
#include "ibi_qt/ibiQFunctorGLViewer.h"
#include "ibi_gl/Texture.h"
#include "ibi_texturemanager/TextureManager.h"
#include "ibi_gl/GLMode2D.h"

using namespace std;
using namespace ibi;

Texture* t = 0;

struct draw
{
	void operator()(ibiQGLViewer* widget)
	{
		t->enable();

		widget->start2DMode();

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

		widget->stop2DMode();
	}
};

struct init
{
	Nrrd* nin;

	void operator()(ibiQGLViewer* widget)
	{
		nin = nrrdNew();
		if (nrrdLoad(nin, "data/nrrd2d.nhdr", NULL))
		{
			char* err = biffGetDone(NRRD);
			cerr << err << endl;
			free(err);
		}

		TextureLoadingInfo tinfo;
		tinfo.texture_type = "nrrd";
		tinfo.target = GL_TEXTURE_2D;
		tinfo.options["nrrd"] = nin;

		TextureManager manager;
		manager.loadPlugin("build/lib/libtexture_loader_nrrd.so");

		t = manager.load(tinfo);

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
