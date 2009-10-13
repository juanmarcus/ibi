#include "ImageWidget.h"

#include <QtGui/QLayout>
#include <QtGui/QLabel>
#include <QtGui/QFileDialog>

ImageWidget::ImageWidget(QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout* layout = new QVBoxLayout();
	this->setLayout(layout);
}

ImageWidget::~ImageWidget()
{

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
		this->layout()->addWidget(label);
	}
	//TODO save pixmap for further reorganization
}

void ImageWidget::addImage()
{
	QString filename = QFileDialog::getOpenFileName(this, "Select image");
	if (!filename.isEmpty())
	{
		this->addImage(filename);
	}
}
