/*
 * Interpolation.h
 *
 *  Created on: Oct 29, 2009
 *      Author: Juan Ibiapina
 */

#ifndef INTERPOLATION_H_
#define INTERPOLATION_H_

#include "ibi_internal.h"
#include <vector>
#include "ibi_geometry/Vector3.h"
#include "ibi_geometry/Ray.h"

namespace ibi
{

class Interpolation
{
public:
	Interpolation();
	~Interpolation();

	static inline std::vector<Vector3> interpolate(const Vector3& p1,
			const Vector3& p2, int npoints)
	{
		std::vector<Vector3> points;

		Vector3 dir = p2 - p1;
		Real len = dir.length();
		dir.normalise();
		Ray ray(p1, dir);

		Real pos = 0.0;

		Real step = len / (npoints + 1);

		for (int i = 0; i < npoints; ++i)
		{
			pos += step;
			Vector3 np = ray * pos;
			points.push_back(np);
		}

		return points;
	}
};

} // namespace ibi

#endif /* INTERPOLATION_H_ */
