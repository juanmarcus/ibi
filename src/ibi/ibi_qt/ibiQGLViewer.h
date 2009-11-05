#ifndef IBIQTSMARTGLWIDGET_H
#define IBIQTSMARTGLWIDGET_H

#include "ibi.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/GLMode2D.h"
#include <QGLViewer/qglviewer.h>

namespace ibi
{

class ibiQGLViewer: public QGLViewer
{
Q_OBJECT

public:
	ibiQGLViewer(QWidget* parent = 0);
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

	/*
	 * Draws a full screen quad.
	 */
	void drawFullScreenQuad();

	void resizeGL(int w, int h);

	void setDesiredAspectRatio(float ratio);

private:
	GLMode2D mode2d;

	float desiredAspectRatio;
};

} // namespace ibi

#endif // IBIQTSMARTGLWIDGET_H
