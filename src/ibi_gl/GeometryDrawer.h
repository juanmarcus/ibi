/*
 * GeometryDrawer.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GEOMETRYDRAWER_H_
#define GEOMETRYDRAWER_H_

#include "ibi_geometry/Ray.h"

class GeometryDrawer
{
public:
	GeometryDrawer();
	~GeometryDrawer();

	void draw(Ray& ray);
};

#endif /* GEOMETRYDRAWER_H_ */
