/*
 * Texture.h
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <string>

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

	void setFilename(std::string filename);
	void setData(void* data);
	void setDims(int w, int h);
	void setFormat(FileFormat format);
	void setDataFormat(GLenum dataformat);

	void init();
	void enable();
	void disable();
private:
	// Texture filename
	std::string filename;

	// Data
	void* data;

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

#endif /* TEXTURE_H_ */
