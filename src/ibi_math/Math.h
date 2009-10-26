/*
 * Math.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef MATH_H_
#define MATH_H_

#include "ibi_common/common.h"
#include <cmath>

class Math
{
public:

	static inline Real Sqrt(Real fValue)
	{
		return Real(sqrt(fValue));
	}

	static inline Real Abs(Real fValue)
	{
		return Real(fabs(fValue));
	}
};

#endif /* MATH_H_ */
