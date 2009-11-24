/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include "ibi_gl/ibi_gl.h"
#include <QtGui/QApplication>
#include <iostream>
#include "ibi_qt/ibiQFunctorGLViewer.h"
#include "ibi_gl/TextureLoader.h"
#include "ibi_gl/Texture.h"
#include "ibi_qt/TextureConfigurator_Qt.h"

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

		widget->stop2DMode();
	}
};

struct init
{
	void operator()(ibiQGLViewer* widget)
	{
		TextureLoadingInfo info = TextureConfigurator_Qt::fromFilename(
				"data/image.png");

		t = TextureLoader::load(info);

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
