/*
 * test_geometry.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QGLViewer/qglviewer.h>
#include <iostream>

#include "ibi_geometry/Ray.h"
#include "ibi_gl/GeometryDrawer.h"

using namespace std;

class Viewer: public QGLViewer
{

public:
	Viewer(QWidget* parent = 0) :
		QGLViewer(parent)
	{

	}

	~Viewer()
	{

	}

	void draw()
	{
		drawer.draw(ray, 1);
	}

private:
	GeometryDrawer drawer;
	Ray ray;
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Viewer w;

	w.showMaximized();

	return app.exec();
}
