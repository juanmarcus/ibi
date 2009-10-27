/*
 * GeometryDrawer.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include "GeometryDrawer.h"
#include "GL.h"
#include <GL/glu.h>

GeometryDrawer::GeometryDrawer()
{

}

GeometryDrawer::~GeometryDrawer()
{

}

void GeometryDrawer::drawArrow(float length, float radius, int nbSubdivisions)
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

void GeometryDrawer::drawRay(Ray& ray, float length, float radius,
		int nbSubdivisions)
{
	glPushMatrix();

	// Calculate desired rotation
	Quaternion q = Vector3::UNIT_Z.getRotationTo(ray.getDirection());

	// Change transformation
	GL::Translate(ray.getOrigin());
	GL::Rotate(q);

	// Draw the arrow
	drawArrow(ray.getDirection().length(), radius, nbSubdivisions);

	glPopMatrix();

}

void GeometryDrawer::drawPoint(Vector3& point, float radius, int nbSubdivisions)
{
	static GLUquadric* quadric = gluNewQuadric();

	assert(radius > 0.0);

	glPushMatrix();

	glTranslatef(point.x, point.y, point.z);
	gluSphere(quadric, radius, nbSubdivisions, nbSubdivisions);

	glPopMatrix();
}
