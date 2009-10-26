/*
 * GeometryDrawer.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include "GeometryDrawer.h"
#include <GL/glu.h>

GeometryDrawer::GeometryDrawer()
{
	// TODO Auto-generated constructor stub

}

GeometryDrawer::~GeometryDrawer()
{
	// TODO Auto-generated destructor stub
}

void GeometryDrawer::draw(Ray& ray, float length, float radius,
		int nbSubdivisions)
{
	static GLUquadric* quadric = gluNewQuadric();

	if (radius < 0.0)
		radius = 0.05 * length;

	const float head = 2.5 * (radius / length) + 0.1;
	const float coneRadiusCoef = 4.0 - 5.0 * head;

	gluCylinder(quadric, radius, radius,
			length * (1.0 - head / coneRadiusCoef), nbSubdivisions, 1);
	glTranslatef(0.0, 0.0, length * (1.0 - head));
	gluCylinder(quadric, coneRadiusCoef * radius, 0.0, head * length,
			nbSubdivisions, 1);
	glTranslatef(0.0, 0.0, -length * (1.0 - head));
}
