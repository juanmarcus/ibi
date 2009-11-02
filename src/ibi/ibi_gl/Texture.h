/*
 * Texture.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "ibi.h"
#include <GL/gl.h>

namespace ibi
{

enum FileFormat
{
	FF_QT, FF_RAW, FF_NRRD
};

class Texture
{
	friend class TextureLoader;
public:
	Texture(FileFormat fileFormat = FF_QT, int width = 0, int height = 0);
	~Texture();

	void setFilename(String filename);
	void setData(void* data);
	void setElemSize(int size);
	void setDims(int w, int h);
	void setFormat(FileFormat format);
	void setDataFormat(GLenum dataformat);

	void init();
	void enable();
	void disable();
private:
	// Texture filename
	String filename;

	// Data
	void* data;

	// Total data size
	int elemsize;

	// Image format
	FileFormat fileFormat;

	// Data format
	GLenum dataformat;

	// Generated OpenGL name
	GLuint glname;

	// Target enum
	GLenum target;

	// Dimensions
	int width;
	int height;
};

} // namespace ibi

#endif /* TEXTURE_H_ */
