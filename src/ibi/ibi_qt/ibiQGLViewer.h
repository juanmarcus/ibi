#ifndef IBIQTSMARTGLWIDGET_H
#define IBIQTSMARTGLWIDGET_H

#include "ibi.h"
#include "ibi_gl/GLMode2D.h"
#include <QGLViewer/qglviewer.h>

namespace ibi
{

class ibiQGLViewer: public QGLViewer
{
Q_OBJECT

public:
	ibiQGLViewer();
	~ibiQGLViewer();

	//==============================================

	/*
	 * Starts drawing in 2D.
	 */
	void start2DMode();

	/*
	 * Stops drawing in 2D and restores previous state.
	 */
	void stop2DMode();

	void resizeGL(int w, int h);

	void setDesiredAspectRatio(float ratio);

private:
	GLMode2D mode2d;

	float desiredAspectRatio;
};

} // namespace ibi

#endif // IBIQTSMARTGLWIDGET_H
