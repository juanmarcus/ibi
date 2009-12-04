/*
 * GeometryDrawer2D.h
 *
 *  Created on: Nov 11, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GEOMETRYDRAWER2D_H_
#define GEOMETRYDRAWER2D_H_

#include "ibi_internal.h"
#include "ibi_gl.h"
#include "ibi_geometry/Vector3.h"

BEGIN_NAMESPACE_IBI

class GeometryDrawer2D
{
public:
	GeometryDrawer2D();
	~GeometryDrawer2D();

	void drawCircle(Vector3& center, float radius = 10.0, float nbSubdivisions =
			60);
};

END_NAMESPACE_IBI

#endif /* GEOMETRYDRAWER2D_H_ */
