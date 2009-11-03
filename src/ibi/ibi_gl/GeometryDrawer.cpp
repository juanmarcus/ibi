/*
 * GeometryDrawer.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include "GeometryDrawer.h"

#include "GL.h"

namespace ibi
{

GeometryDrawer::GeometryDrawer()
{
	quadric = gluNewQuadric();
}

GeometryDrawer::~GeometryDrawer()
{

}

void GeometryDrawer::drawCylinder(float length, float radius,
		int nbSubdivisions)
{
	if (radius < 0.0)
		radius = 0.05 * length;
	gluCylinder(quadric, radius, radius, length, nbSubdivisions, 1);
}

void GeometryDrawer::drawCylinder(Vector3& from, Vector3& to, float radius,
		int nbSubdivisions)
{
	Vector3 dir = to - from;

	// Calculate desired rotation
	Quaternion q = Vector3::UNIT_Z.getRotationTo(dir);

	glPushMatrix();

	// Change transformation
	GL::Translate(from);
	GL::Rotate(q);

	drawCylinder(dir.length(), radius, nbSubdivisions);

	glPopMatrix();
}

void GeometryDrawer::drawArrow(float length, float radius, int nbSubdivisions)
{
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
	// Calculate desired rotation
	Quaternion q = Vector3::UNIT_Z.getRotationTo(ray.getDirection());

	glPushMatrix();

	// Change transformation
	GL::Translate(ray.getOrigin());
	GL::Rotate(q);

	// Draw the arrow
	drawArrow(length, radius, nbSubdivisions);

	glPopMatrix();

}

void GeometryDrawer::drawPoint(const Vector3& point, float radius,
		int nbSubdivisions)
{
	assert(radius > 0.0);

	glPushMatrix();

	glTranslatef(point.x, point.y, point.z);
	gluSphere(quadric, radius, nbSubdivisions, nbSubdivisions);

	glPopMatrix();
}

void GeometryDrawer::drawPoints(std::vector<Vector3>& points, float radius,
		int nbSubdivisions)
{
	std::vector<Vector3>::iterator it = points.begin();
	std::vector<Vector3>::iterator itEnd = points.end();
	for (; it != itEnd; ++it)
	{
		drawPoint(*it, radius, nbSubdivisions);
	}
}

void GeometryDrawer::drawAxisAlignedBox(const AxisAlignedBox& box,
		float radius, int nbSubdivisions)
{
	/*
	 1-----2
	 /|    /|
	 / |   / |
	 5-----4  |
	 |  0--|--3
	 | /   | /
	 |/    |/
	 6-----7
	 */
	// Get box corners
	Vector3 corner[8];
	corner[0] = box.getCorner(AxisAlignedBox::FAR_LEFT_BOTTOM);
	corner[1] = box.getCorner(AxisAlignedBox::FAR_LEFT_TOP);
	corner[2] = box.getCorner(AxisAlignedBox::FAR_RIGHT_TOP);
	corner[3] = box.getCorner(AxisAlignedBox::FAR_RIGHT_BOTTOM);
	corner[4] = box.getCorner(AxisAlignedBox::NEAR_RIGHT_TOP);
	corner[5] = box.getCorner(AxisAlignedBox::NEAR_LEFT_TOP);
	corner[6] = box.getCorner(AxisAlignedBox::NEAR_LEFT_BOTTOM);
	corner[7] = box.getCorner(AxisAlignedBox::NEAR_RIGHT_BOTTOM);

	// Draw corners
	for (int i = 0; i < 8; ++i)
	{
		drawPoint(corner[i], radius, nbSubdivisions);
	}

	drawCylinder(corner[0], corner[1], radius / 2);
	drawCylinder(corner[0], corner[3], radius / 2);
	drawCylinder(corner[0], corner[6], radius / 2);

	drawCylinder(corner[1], corner[2], radius / 2);
	drawCylinder(corner[1], corner[5], radius / 2);

	drawCylinder(corner[2], corner[3], radius / 2);
	drawCylinder(corner[2], corner[4], radius / 2);

	drawCylinder(corner[3], corner[7], radius / 2);

	drawCylinder(corner[4], corner[5], radius / 2);
	drawCylinder(corner[4], corner[7], radius / 2);

	drawCylinder(corner[5], corner[6], radius / 2);

	drawCylinder(corner[6], corner[7], radius / 2);

}

void GeometryDrawer::drawTriangle(const Triangle& t, float radius,
		int nbSubdivisions)
{
	Vector3 v0 = t.getVertex(0);
	Vector3 v1 = t.getVertex(1);
	Vector3 v2 = t.getVertex(2);

	glPushMatrix();

	drawPoint(v0, radius, nbSubdivisions);
	drawPoint(v1, radius, nbSubdivisions);
	drawPoint(v2, radius, nbSubdivisions);

	glPopMatrix();
}

} // namespace ibi
