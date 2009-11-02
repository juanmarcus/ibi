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

struct paint
{
	GLMode2D mode;

	void operator()(ibiQGLViewer* widget)
	{
		mode.enable();

		t->enable();
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

		//		int size = nrrdElementSize(nin);
		//		t.setData(nin->data);
		//		t.setElemSize(size);
		//		t.setDims(nin->axis[0].size, nin->axis[1].size);
		//		widget->loadTexture(t);
	}
};

struct resize
{
	void operator()(ibiQGLViewer* widget, int w, int h)
	{
	}
};

InitializeFunctor initer = init();
ResizeFunctor resizer = resize();
PaintFunctor painter = paint();

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	ibiQFunctorGLViewer w(initer, resizer, painter);

	w.showMaximized();

	return app.exec();
}
