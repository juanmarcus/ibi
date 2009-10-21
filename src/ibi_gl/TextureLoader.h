/*
 * TextureLoader.h
 *
 *  Created on: Oct 15, 2009
 *      Author: juanmarcus
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "Texture.h"
#include <string>
#include <iostream>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	void load(Texture& t);
	void loadRaw(Texture& t);
	void loadQt(Texture& t);
	void loadNrrd(Texture& t);
};

#endif /* TEXTURELOADER_H_ */
