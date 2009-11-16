/*
 * Wrapper.h
 *
 *  Created on: Oct 27, 2009
 *      Author: Juan Ibiapina
 */

#ifndef WRAPPER_H_
#define WRAPPER_H_

#include "ibi_internal.h"
#include "ibi_gl.h"
#include "ibi_geometry/Vector3.h"
#include "ibi_geometry/Matrix3.h"

namespace ibi
{

class GL
{
public:
	static inline void Translate(const Vector3& vec)
	{
		glTranslatef(vec.x, vec.y, vec.z);
	}

	static inline void Rotate(const Quaternion& q)
	{
		Matrix3 m3;
		Vector3 axis;
		Radian angle;

		q.ToRotationMatrix(m3);
		m3.ToAxisAngle(axis, angle);

		glRotatef(angle.valueDegrees(), axis.x, axis.y, axis.z);
	}

};

} // namespace ibi

#endif /* WRAPPER_H_ */
