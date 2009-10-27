/*
 * Transform.h
 *
 *  Created on: Oct 27, 2009
 *      Author: Juan Ibiapina
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Ray.h"
#include "Matrix4.h"

class Transform
{
public:
	static inline Ray TransformRay(Matrix4& mat, Ray& ray)
	{
		Ray rray;
		rray.setOrigin(mat * ray.getOrigin());
		rray.setDirection(mat.inverse().transpose() * ray.getDirection());
		return rray;
	}
};

#endif /* TRANSFORM_H_ */
