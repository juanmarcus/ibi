/*
 * test_imagewidget.cpp
 *
 *  Created on: Oct 11, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QAction>
#include <QtGui/QToolBar>
#include <QtCore>

#include "ibi_qt/ImageWidget.h"

int main(int argc, char **argv)
{
	// Create an application
	QApplication app(argc, argv);
	// Create a window
	QMainWindow w;

	// Set the central widget to a ImageWidget
	ImageWidget* imageWidget = new ImageWidget();
	w.setCentralWidget(imageWidget);

	// Configure actions
	QAction* action = new QAction(w.tr("Add Image"), &w);
	action->connect(action, SIGNAL(triggered()), imageWidget, SLOT(addImage()) );

	// Configure toolbar
	QToolBar* bar = w.addToolBar(w.tr("Actions"));
	bar->addAction(action);

	// Show the window
	w.show();
	// Run the application loop
	return app.exec();
}

