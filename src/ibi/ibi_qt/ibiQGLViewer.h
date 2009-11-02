#ifndef IBIQTSMARTGLWIDGET_H
#define IBIQTSMARTGLWIDGET_H

#include "ibi.h"
#include <QGLViewer/qglviewer.h>

namespace ibi
{

class ibiQGLViewer: public QGLViewer
{
Q_OBJECT

public:
	ibiQGLViewer();
	~ibiQGLViewer();
};

} // namespace ibi

#endif // IBIQTSMARTGLWIDGET_H
