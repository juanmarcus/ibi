/*
 * GeometryDrawer.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GEOMETRYDRAWER_H_
#define GEOMETRYDRAWER_H_

#include "ibi_geometry/Ray.h"
#include "ibi_geometry/Vector3.h"

class GeometryDrawer
{
public:
	GeometryDrawer();
	~GeometryDrawer();

	void drawRay(Ray& ray, float length, float radius = -1.0, int nbSubdivisions = 12);
	void drawPoint(Vector3& point, float radius = 0.01, int nbSubdivisions = 12);
};

#endif /* GEOMETRYDRAWER_H_ */
