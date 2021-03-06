/*
 * TextureLoadingInfo.cpp
 *
 *  Created on: Nov 23, 2009
 *      Author: Juan Ibiapina
 */

#include "TextureLoadingInfo.h"

BEGIN_NAMESPACE_IBI

TextureLoadingInfo::TextureLoadingInfo()
{
	target = GL_TEXTURE_2D;
	dim = 2;
	width = 256;
	height = 256;
	depth = 0;
	level = 0;
	internalformat = GL_RGBA;
	border = 0;
	format = GL_RGBA;
	type = GL_FLOAT;
	data = 0;
	destroydata = false;
}

TextureLoadingInfo::~TextureLoadingInfo()
{
	if (destroydata)
	{
		delete[] (char*) data;
	}

}

}
