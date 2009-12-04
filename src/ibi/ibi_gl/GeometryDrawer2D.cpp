/*
 * GeometryDrawer2D.cpp
 *
 *  Created on: Nov 11, 2009
 *      Author: Juan Ibiapina
 */

#include "GeometryDrawer2D.h"

BEGIN_NAMESPACE_IBI

GeometryDrawer2D::GeometryDrawer2D()
{

}

GeometryDrawer2D::~GeometryDrawer2D()
{

}

void GeometryDrawer2D::drawCircle(Vector3& center, float radius,
		float nbSubdivisions)
{
	float step = 360.0 / nbSubdivisions;
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(center.x, center.y);
	for (float angle = 0.0; angle <= 360; angle += step)
	{
		glVertex2f(center.x + Math::Sin(Degree(angle)) * radius, center.y
				+ Math::Cos(Degree(angle)) * radius);
	}

	glEnd();
}

END_NAMESPACE_IBI
