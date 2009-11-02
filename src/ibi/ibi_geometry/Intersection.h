/*
 * Intersection.h
 *
 *  Created on: Oct 28, 2009
 *      Author: juanmarcus
 */

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "ibi.h"
#include "ibi_geometry/Ray.h"
#include "ibi_geometry/AxisAlignedBox.h"
#include "ibi_geometry/Triangle.h"

namespace ibi
{

class Intersection
{
public:
	/** Ray / box intersection, returns boolean result and distance. */
	static std::pair<bool, RealPair > intersects(const Ray& ray,
			const AxisAlignedBox& box);
	static std::pair<bool, Real> intersects(const Ray& ray,
			const Triangle& triangle);
};

} // namespace ibi

#endif /* INTERSECTION_H_ */
