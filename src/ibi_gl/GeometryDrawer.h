/*
 * GeometryDrawer.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef GEOMETRYDRAWER_H_
#define GEOMETRYDRAWER_H_

#include <vector>
#include <GL/glu.h>
#include "ibi_geometry/Ray.h"
#include "ibi_geometry/AxisAlignedBox.h"
#include "ibi_geometry/Vector3.h"
#include "ibi_geometry/Triangle.h"

class GeometryDrawer
{
public:
	GeometryDrawer();
	~GeometryDrawer();

	void drawCylinder(Vector3& from, Vector3& to, float radius = -1.0,
			int nbSubdivisions = 12);

	void drawCylinder(float length, float radius = -1.0, int nbSubdivisions =
			12);

	void drawArrow(float length, float radius = -1.0, int nbSubdivisions = 12);

	void drawRay(Ray& ray, float length, float radius = -1.0,
			int nbSubdivisions = 12);

	void
	drawPoint(const Vector3& point, float radius = 0.01, int nbSubdivisions =
			12);

	void drawPoints(std::vector<Vector3>& points, float radius = 0.01,
			int nbSubdivisions = 12);

	void drawAxisAlignedBox(const AxisAlignedBox& box, float radius = 0.01,
			int nbSubdivisions = 12);

	void drawTriangle(const Triangle& t, float radius = 0.01,
			int nbSubdivisions = 12);
private:
	GLUquadric* quadric;
};

#endif /* GEOMETRYDRAWER_H_ */
