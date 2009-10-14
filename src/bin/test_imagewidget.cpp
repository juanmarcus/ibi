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
	QAction* addImageAct = new QAction(w.tr("Add Image"), &w);
	addImageAct->connect(addImageAct, SIGNAL(triggered()), imageWidget, SLOT(addImage()) );
	QAction* setLayoutToRowsAct = new QAction(w.tr("Rows"), &w);
	setLayoutToRowsAct->connect(setLayoutToRowsAct, SIGNAL(triggered()), imageWidget, SLOT(setLayoutModeToRows()) );
	QAction* setLayoutToColumnsAct = new QAction(w.tr("Columns"), &w);
	setLayoutToColumnsAct->connect(setLayoutToColumnsAct, SIGNAL(triggered()), imageWidget, SLOT(setLayoutModeToColumns()) );

	// Configure toolbar
	QToolBar* bar = w.addToolBar(w.tr("Actions"));
	bar->addAction(addImageAct);
	bar->addAction(setLayoutToRowsAct);
	bar->addAction(setLayoutToColumnsAct);

	// Show the window
	w.show();
	// Run the application loop
	return app.exec();
}

