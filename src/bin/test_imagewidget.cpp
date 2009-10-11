/*
 * test_imagewidget.cpp
 *
 *  Created on: Oct 11, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>

#include "ibi_qt/ImageWidget.h"

int main(int argc, char **argv)
{
	// Create an application
	QApplication app(argc, argv);
	// Create a windows
	QMainWindow w;
	// Show the window
	w.show();
	// Run the application loop
	return app.exec();
}

