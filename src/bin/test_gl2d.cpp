/*
 * test_gl2d.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: Juan Ibiapina
 */

#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>

#include <teem/nrrd.h>

#include "ibi_gl2d/GLMode2D.h"
#include "ibi_gl2d/Sprite.h"

// 2D test class
class GLWidget: public QGLWidget
{
public:
	GLWidget(QWidget* parent = 0) :
		QGLWidget(parent)
	{
		sprite = 0;

		Nrrd* nin = nrrdNew();
		if (nrrdLoad(nin, "data/nrrd2d.nhdr", NULL))
		{
			char* err = biffGetDone(NRRD);
			fprintf(stderr, "problem loading nrrd\n%s", err);
			free(err);
		}
		else
		{
			sprite = new Sprite();
//			sprite->loadFrom(nin);
		}

	}
	~GLWidget()
	{
		if (sprite)
		{
			delete sprite;
		}
	}

	void initializeGL()
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);

		glEnable(GL_TEXTURE_2D);
		GLuint texture = bindTexture(QPixmap("data/image.png"), GL_TEXTURE_2D);
	}

	void resizeGL(int width, int height)
	{
		int side = qMin(width, height);
		glViewport((width - side) / 2, (height - side) / 2, side, side);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 1, 1, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
	}

	void paintGL()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		mode2d.enable();

		glColor3f(1,1,1);

		sprite->render(0, 0);

		mode2d.disable();
	}
private:
	GLMode2D mode2d;
	Sprite* sprite;
};

int main(int argc, char **argv)
{
	// Create an application
	QApplication app(argc, argv);
	// Create a window
	GLWidget w;
	// Show the window
	w.showMaximized();
	// Run the application loop
	return app.exec();
}
