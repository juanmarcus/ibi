#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QtGui/QWidget>

class ImageWidget: public QWidget
{
Q_OBJECT

public:
	ImageWidget(QWidget *parent = 0);
	~ImageWidget();

public slots:
	void addImage();
	void addImage(QPixmap pixmap);
	void addImage(QString filename);

};

#endif // IMAGEWIDGET_H
