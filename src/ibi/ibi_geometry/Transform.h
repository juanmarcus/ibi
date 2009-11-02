/*
 * Transform.h
 *
 *  Created on: Oct 27, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "ibi.h"
#include "Ray.h"
#include "Matrix4.h"

namespace ibi
{

class Transform
{
public:
	static inline Ray TransformRay(Matrix4& mat, Ray& ray)
	{
		Ray rray;
		Matrix3 mrot;
		rray.setOrigin(mat * ray.getOrigin());
		mat.extract3x3Matrix(mrot);
		rray.setDirection(mrot * ray.getDirection());
		return rray;
	}
};

} // namespace ibi

#endif /* TRANSFORM_H_ */
