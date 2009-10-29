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
#include "ibi_geometry/Matrix4.h"
#include "ibi_geometry/AxisAlignedBox.h"
#include "ibi_gl/GeometryDrawer.h"
#include "ibi_geometry/Transform.h"

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
		showEntireScene();
		//	restoreStateFromFile();

		box.setExtents(-1, -1, -1, 1, 1, 1);
	}

	void draw()
	{
		const GLdouble* mod = manipulatedFrame()->matrix();
		Matrix4 m(mod[0], mod[4], mod[8], mod[12], mod[1], mod[5], mod[9],
				mod[13], mod[2], mod[6], mod[10], mod[14], mod[3], mod[7],
				mod[11], mod[15]);

		// Transform ray
		Ray tray = Transform::TransformRay(m, ray);
		// Draw ray
		drawer.drawRay(tray, 4, 0.005);

		// Draw point at the origin
		drawer.drawPoint(Vector3::ZERO);

		// Draw a box
		drawer.drawAxisAlignedBox(box);

	}

private:
	GeometryDrawer drawer;
	Ray ray;
	AxisAlignedBox box;
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Viewer w;

	w.showMaximized();

	return app.exec();
}
