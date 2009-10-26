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
#include "ibi_geometry/Vector3.h"
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

	void init()
	{

		setManipulatedFrame(new qglviewer::ManipulatedFrame());

		setSceneRadius(2.0);
		//	restoreStateFromFile();

	}

	void draw()
	{
		// Change to frame coordinate system
		glPushMatrix();
		glMultMatrixd(manipulatedFrame()->matrix());
		// Draw ray
		drawer.drawRay(ray, 2, 0.005);
		// Change back to world coordinate system
		glPopMatrix();

		drawer.drawPoint(point1);

	}

private:
	GeometryDrawer drawer;
	Ray ray;
	Vector3 point1;
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Viewer w;

	w.showMaximized();

	return app.exec();
}
