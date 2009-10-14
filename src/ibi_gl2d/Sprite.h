/*
 * Sprite.h
 *
 *  Created on: Oct 14, 2009
 *      Author: juanmarcus
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <GL/gl.h>

#include <teem/nrrd.h>

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	void render(int xpos, int ypos);
	void loadFrom(Nrrd* nin);
private:
	GLuint texture;
};

#endif /* SPRITE_H_ */
