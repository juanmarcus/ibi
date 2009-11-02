/*
 * Intersection.cpp
 *
 *  Created on: Oct 28, 2009
 *      Author: juanmarcus
 */

#include "Intersection.h"

namespace ibi
{

std::pair<bool, RealPair> Intersection::intersects(const Ray& ray,
		const AxisAlignedBox& box)
{
	if (box.isNull())
		return std::pair<bool, RealPair>(false, RealPair(0, 0));

	if (box.isInfinite())
	{
		return std::pair<bool, RealPair>(true, RealPair(0, Math::POS_INFINITY));
	}

	const Vector3& min = box.getMinimum();
	const Vector3& max = box.getMaximum();
	const Vector3& rayorig = ray.getOrigin();
	const Vector3& raydir = ray.getDirection();

	Vector3 absDir;
	absDir[0] = Math::Abs(raydir[0]);
	absDir[1] = Math::Abs(raydir[1]);
	absDir[2] = Math::Abs(raydir[2]);

	// Sort the axis, ensure check minimise floating error axis first
	int imax = 0, imid = 1, imin = 2;
	if (absDir[0] < absDir[2])
	{
		imax = 2;
		imin = 0;
	}
	if (absDir[1] < absDir[imin])
	{
		imid = imin;
		imin = 1;
	}
	else if (absDir[1] > absDir[imax])
	{
		imid = imax;
		imax = 1;
	}

	Real start = 0, end = Math::POS_INFINITY;

#define _CALC_AXIS(i)                                       \
	    do {                                                    \
	        Real denom = 1 / raydir[i];                         \
	        Real newstart = (min[i] - rayorig[i]) * denom;      \
	        Real newend = (max[i] - rayorig[i]) * denom;        \
	        if (newstart > newend) std::swap(newstart, newend); \
	        if (newstart > end || newend < start) return std::pair<bool, RealPair>(false, RealPair(0, 0)); \
	        if (newstart > start) start = newstart;             \
	        if (newend < end) end = newend;                     \
	    } while(0)

	// Check each axis in turn

	_CALC_AXIS(imax);

	if (absDir[imid] < std::numeric_limits<Real>::epsilon())
	{
		// Parallel with middle and minimise axis, check bounds only
		if (rayorig[imid] < min[imid] || rayorig[imid] > max[imid]
				|| rayorig[imin] < min[imin] || rayorig[imin] > max[imin])
			return std::pair<bool, RealPair>(false, RealPair(0, 0));
	}
	else
	{
		_CALC_AXIS(imid);

		if (absDir[imin] < std::numeric_limits<Real>::epsilon())
		{
			// Parallel with minimise axis, check bounds only
			if (rayorig[imin] < min[imin] || rayorig[imin] > max[imin])
				return std::pair<bool, RealPair>(false, RealPair(0, 0));
		}
		else
		{
			_CALC_AXIS(imin);
		}
	}
#undef _CALC_AXIS

	return std::pair<bool, RealPair>(true, RealPair(start, end));

}

std::pair<bool, Real> Intersection::intersects(const Ray& ray,
		const Triangle& triangle)
{
	Vector3 u, v, n; // triangle vectors
	Vector3 dir, w0, w; // ray vectors
	Real r, a, b; // params to calc ray-plane intersect

	// get triangle edge vectors and plane normal
	u = triangle.getVertex(1) - triangle.getVertex(0);
	v = triangle.getVertex(2) - triangle.getVertex(0);
	n = u.crossProduct(v);
	if (n == Vector3::ZERO) // triangle is degenerate
		return std::pair<bool, Real>(false, 0);

	dir = ray.getDirection(); // ray direction vector
	w0 = ray.getOrigin() - triangle.getVertex(0);
	a = -n.dotProduct(w0);
	b = n.dotProduct(dir);
	if (Math::Abs(b) < 0.00000001)
	{ // ray is parallel to triangle plane
		if (a == 0) // ray lies in triangle plane
			return std::pair<bool, Real>(false, 0);
		else
			return std::pair<bool, Real>(false, 0); // ray disjoint from plane
	}

	// get intersect point of ray with triangle plane
	r = a / b;
	if (r < 0.0) // ray goes away from triangle
		return std::pair<bool, Real>(false, 0); // => no intersect

	Vector3 I = ray * r; // intersect point of ray and plane

	// is I inside T?
	float uu, uv, vv, wu, wv, D;
	uu = u.dotProduct(u);
	uv = u.dotProduct(v);
	vv = v.dotProduct(v);
	w = I - triangle.getVertex(0);
	wu = w.dotProduct(u);
	wv = w.dotProduct(v);
	D = uv * uv - uu * vv;

	// get and test parametric coords
	float s, t;
	s = (uv * wv - vv * wu) / D;
	if (s < 0.0 || s > 1.0) // I is outside T
		return std::pair<bool, Real>(false, 0);
	t = (uv * wu - uu * wv) / D;
	if (t < 0.0 || (s + t) > 1.0) // I is outside T
		return std::pair<bool, Real>(false, 0);

	return std::pair<bool, Real>(true, r); // I is in T
}

} // namespace ibi
