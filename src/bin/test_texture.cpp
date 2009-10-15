/*
 * test_texture.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QGLWidget w;

	w.showMaximized();

	return app.exec();
}
