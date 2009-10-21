/*
 * TextureLoader.cpp
 *
 *  Created on: Oct 15, 2009
 *      Author: juanmarcus
 */

#include "TextureLoader.h"
#include "ibi_error/Exception.h"
#include <fstream>

using namespace std;

TextureLoader::TextureLoader()
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
	throw Exception("unimplemented.");
}

void TextureLoader::loadNrrd(Texture& t)
{
	throw Exception("unimplemented.");
}

void TextureLoader::loadRaw(Texture& t)
{
	if (!t.width || !t.height)
	{
		throw Exception("Raw format requires width and height parameters.");
	}
	// Initialize texture
	t.init();

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
	char* data = new char[t.width * t.height * 3];
	infile.read(data, 256 * 256 * 3);

	// Load the data to opengl
	glTexImage2D(t.target, 0, 3, t.width, t.height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, data);

	// Delete raw data
	delete[] data;
}
