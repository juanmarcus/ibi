/*
 * TextureLoader.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: Juan Ibiapina
 */

#include "TextureLoader.h"
#include "ibi_error/Exception.h"
#include <fstream>

using namespace std;

TextureLoader::TextureLoader(QGLWidget* a_glwidget) :
	glwidget(a_glwidget)
{
}

TextureLoader::~TextureLoader()
{
}

void TextureLoader::load(Texture& t)
{
	switch (t.fileFormat)
	{
	case FF_NRRD:
		loadNrrd(t);
		break;
	case FF_QT:
		loadQt(t);
		break;
	case FF_RAW:
		loadRaw(t);
		break;
	default:
		throw Exception("Unrecognized format");
		break;
	}
}

void TextureLoader::loadQt(Texture& t)
{
	// Qt initializes the texture for us
	//t.init();
	if (!glwidget)
	{
		throw Exception("Error loading Qt texture. GLWidget not set.");
	}

	t.glname = glwidget->bindTexture(QImage(t.filename.c_str()), t.target);
	if (!t.glname)
	{
		throw Exception("Error loading texture with Qt.");
	}
}

void TextureLoader::loadNrrd(Texture& t)
{
	if (!t.width || !t.height)
	{
		throw Exception("Nrrd format requires width and height parameters.");
	}

	if (!t.elemsize)
	{
		throw Exception("Nrrd format requires element size parameter.");
	}
	// Initialize texture
	t.init();

	// Copy memory upside-down
	char* tmpdata = (char*) malloc(t.width * t.height * t.elemsize);

	for (int i = 0; i < t.height; ++i)
	{
		char* src = (char*) t.data;
		int linesize = t.width * t.elemsize;
		memcpy(&tmpdata[(t.height - i - 1) * linesize], &src[i * linesize],
				linesize);
	}

	// Load the data to opengl
	glTexImage2D(t.target, 0, 1, t.width, t.height, 0, GL_LUMINANCE,
			t.dataformat, tmpdata);

	free(tmpdata);

}

void TextureLoader::loadRaw(Texture& t)
{
	if (!t.width || !t.height)
	{
		throw Exception("Raw format requires width and height parameters.");
	}
	// Initialize texture
	t.init();

	char* tmpdata;
	// Check for data
	if (!t.data)
	{
		// Open file
		ifstream infile;
		infile.open(t.filename.c_str(), ios::binary);
		if (!infile)
		{
			cout << "here" << endl;
			throw Exception("Error opening file.");
			cout << "here" << endl;
		}

		// Load the data to memory
		tmpdata = new char[t.width * t.height * 3];
		infile.read(tmpdata, 256 * 256 * 3);
	}
	else
	{
		tmpdata = (char*) t.data;
	}

	// Load the data to opengl
	glTexImage2D(t.target, 0, 3, t.width, t.height, 0, GL_RGB, t.dataformat,
			tmpdata);

	// Delete raw data
	if (!t.data)
	{
		delete[] tmpdata;
	}
}
