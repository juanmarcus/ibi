#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <vector>

class ImageWidget: public QWidget
{
Q_OBJECT

public:
	enum LayoutMode
	{
		Rows, Columns
	};

public:
	ImageWidget(QWidget *parent = 0);
	~ImageWidget();

	void createLayout();
	void setLayoutMode(LayoutMode mode);
	void populateLayout(std::vector<QLabel*> images);

public slots:
	void addImage();
	void addImage(QPixmap pixmap);
	void addImage(QString filename);
	void setLayoutModeToRows();
	void setLayoutModeToColumns();

private:
	LayoutMode layoutMode;
	std::vector<QLabel*> images;

};

#endif // IMAGEWIDGET_H
