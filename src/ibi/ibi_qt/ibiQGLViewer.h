#ifndef IBIQTSMARTGLWIDGET_H
#define IBIQTSMARTGLWIDGET_H

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/GLMode2D.h"
#include "ibi_gl/Texture.h"
#include "ibi_gl/TextureLoadingInfo.h"
#include "ibi_geometry/Vector3.h"
#include <QGLViewer/qglviewer.h>

namespace ibi
{

class ibiQGLViewer: public QGLViewer
{
Q_OBJECT

public:
	ibiQGLViewer(QWidget *parent = 0, const QGLWidget *shareWidget = 0,
			Qt::WFlags flags = 0);
	ibiQGLViewer(QGLContext *context, QWidget *parent = 0,
			const QGLWidget *shareWidget = 0, Qt::WFlags flags = 0);
	ibiQGLViewer(const QGLFormat &format, QWidget *parent = 0,
			const QGLWidget *shareWidget = 0, Qt::WFlags flags = 0);
	~ibiQGLViewer();

	//	void init();

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

	/**
	 * Returns normalized screen coordinates from Qt screen coordinates.
	 */
	Vector3 normalizedViewportCoordinates(int x, int y);

	/*
	 * Return absolute screen coordinates from normalized coordinates.
	 */
	Vector3 absoluteViewportCoordinates(Vector3& point);

	void resizeGL(int w, int h);

	void setDesiredAspectRatio(float ratio);

	void saveViewport();

	void restoreViewport();

	Texture* loadTexture(TextureLoadingInfo& info);

private:
	GLMode2D mode2d;

	int savedViewport[4];

	float desiredAspectRatio;
};

} // namespace ibi

#endif // IBIQTSMARTGLWIDGET_H
