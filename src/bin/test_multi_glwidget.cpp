/*
 * test_imagewidget.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>

int main(int argc, char **argv)
{
	// Create an application
	QApplication app(argc, argv);
	// Create two GL widgets
	QGLWidget gl1, gl2;

	// Show the widgets
	gl1.show();
	gl2.show();

	// Run the application loop
	return app.exec();
}

