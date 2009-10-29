/*
 * test_interpolation.cpp
 *
 *  Created on: Oct 29, 2009
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
#include "ibi_interpolation/Interpolation.h"

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

		setSceneRadius(2.0);
		showEntireScene();
		//	restoreStateFromFile();

		box.setExtents(-1, -1, -1, 1, 1, 1);

		p1 = Vector3(1, 1, 1);
		p2 = Vector3(-1, -1, -1);

	}

	void draw()
	{
		glColor3f(1.0, 1.0, 1.0);

		// Draw point at the origin
		drawer.drawPoint(Vector3::ZERO);

		// Draw a box
		drawer.drawAxisAlignedBox(box);

		glColor3f(0.0, 0.0, 1.0);
		ipoints = Interpolation::interpolate(p1, p2, 100);
		drawer.drawPoints(ipoints);
	}

private:
	GeometryDrawer drawer;
	AxisAlignedBox box;

	Vector3 p1, p2;
	std::vector<Vector3> ipoints;
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Viewer w;

	w.showMaximized();

	return app.exec();
}
