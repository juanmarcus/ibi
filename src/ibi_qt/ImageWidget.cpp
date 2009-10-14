#include "ImageWidget.h"

#include <QtGui/QLayout>
#include <QtGui/QLabel>
#include <QtGui/QFileDialog>

using namespace std;

ImageWidget::ImageWidget(QWidget *parent) :
	QWidget(parent)
{
	setLayoutMode(Columns);
}

ImageWidget::~ImageWidget()
{

}

void ImageWidget::createLayout()
{
	QLayout* layout = this->layout();
	if (layout)
	{
		delete layout;
		layout = NULL;
	}
	if (this->layoutMode == Rows)
	{
		layout = new QHBoxLayout();
	}
	else if (this->layoutMode == Columns)
	{
		layout = new QVBoxLayout();
	}
	this->setLayout(layout);

	populateLayout(images);
}

void ImageWidget::addImage(QString filename)
{
	QPixmap pixmap(filename);
	this->addImage(pixmap);
}

void ImageWidget::addImage(QPixmap pixmap)
{
	if (!pixmap.isNull())
	{
		QLabel* label = new QLabel();
		label->setPixmap(pixmap);
		images.push_back(label);
		this->layout()->addWidget(label);
	}
}

void ImageWidget::addImage()
{
	QString filename = QFileDialog::getOpenFileName(this, "Select image");
	if (!filename.isEmpty())
	{
		this->addImage(filename);
	}
}

void ImageWidget::setLayoutMode(LayoutMode mode)
{
	this->layoutMode = mode;
	createLayout();
}

void ImageWidget::setLayoutModeToRows()
{
	setLayoutMode(Rows);
}

void ImageWidget::setLayoutModeToColumns()
{
	setLayoutMode(Columns);
}

void ImageWidget::populateLayout(vector<QLabel*> images)
{
	QLayout* layout = this->layout();
	if (!layout)
	{
		return;
	}
	vector<QLabel*>::iterator it = images.begin();
	vector<QLabel*>::iterator itEnd = images.end();
	for (; it != itEnd; ++it)
	{
		layout->addWidget(*it);
	}
}
