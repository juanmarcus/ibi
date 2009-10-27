/*
 * Ray.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vector3.h"

class Ray
{
protected:
	Vector3 mOrigin;
	Vector3 mDirection;
public:
	Ray() :
		mOrigin(Vector3::ZERO), mDirection(Vector3::UNIT_Z)
	{
	}
	Ray(const Vector3& origin, const Vector3& direction) :
		mOrigin(origin), mDirection(direction)
	{
	}

	/** Sets the origin of the ray. */
	void setOrigin(const Vector3& origin)
	{
		mOrigin = origin;
	}
	/** Gets the origin of the ray. */
	const Vector3& getOrigin(void) const
	{
		return mOrigin;
	}

	/** Sets the direction of the ray. */
	void setDirection(const Vector3& dir)
	{
		mDirection = dir;
	}
	/** Gets the direction of the ray. */
	const Vector3& getDirection(void) const
	{
		return mDirection;
	}
};

#endif /* RAY_H_ */