/*
 * TextureConfigurator_Qt.h
 *
 *  Created on: Nov 24, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURECONFIGURATOR_QT_H_
#define TEXTURECONFIGURATOR_QT_H_

BEGIN_NAMESPACE_IBI

class TextureConfigurator_Qt
{
public:
	static inline TextureLoadingInfo fromQImage(QImage &image)
	{
		// Create the resulting object
		TextureLoadingInfo info;

		// Convert the image to OpenGL format
		QImage t = QGLWidget::convertToGLFormat(image);

		// Allocate and set memory
		char* data = new char[t.numBytes()];
		memcpy(data, t.bits(), t.numBytes());

		info.internalformat = GL_RGBA;
		info.width = t.width();
		info.height = t.height();
		info.format = GL_RGBA;
		info.type = GL_UNSIGNED_BYTE;
		info.data = data;
		info.destroydata = true;

		return info;
	}

	static inline TextureLoadingInfo fromQImage1D(QImage &image)
	{
		// Create the resulting object
		TextureLoadingInfo info;

		// Convert the image to OpenGL format
		QImage t = QGLWidget::convertToGLFormat(image);

		// Allocate and set memory
		char* data = new char[t.bytesPerLine()];
		memcpy(data, t.bits(), t.bytesPerLine());

		info.target = GL_TEXTURE_1D;
		info.dim = 1;
		info.internalformat = GL_RGBA;
		info.width = t.width();
		info.format = GL_RGBA;
		info.type = GL_UNSIGNED_BYTE;
		info.data = data;
		info.destroydata = true;

		return info;
	}

	static inline TextureLoadingInfo fromFilename(QString filename)
	{
		QImage img(filename);
		return fromQImage(img);
	}
};

}

#endif /* TEXTURECONFIGURATOR_QT_H_ */
