/*
 * Math.cpp
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#include "Math.h"

#include <limits>

BEGIN_NAMESPACE_IBI

const Real Math::POS_INFINITY = std::numeric_limits<Real>::infinity();
const Real Math::NEG_INFINITY = -std::numeric_limits<Real>::infinity();
const Real Math::PI = Real(4.0 * atan(1.0));
const Real Math::TWO_PI = Real(2.0 * PI);
const Real Math::HALF_PI = Real(0.5 * PI);
const Real Math::fDeg2Rad = PI / Real(180.0);
const Real Math::fRad2Deg = Real(180.0) / PI;

//-----------------------------------------------------------------------
int Math::ISign(int iValue)
{
	return (iValue > 0 ? +1 : (iValue < 0 ? -1 : 0));
}
//-----------------------------------------------------------------------
Radian Math::ACos(Real fValue)
{
	if (-1.0 < fValue)
	{
		if (fValue < 1.0)
			return Radian(acos(fValue));
		else
			return Radian(0.0);
	}
	else
	{
		return Radian(PI);
	}
}
//-----------------------------------------------------------------------
Radian Math::ASin(Real fValue)
{
	if (-1.0 < fValue)
	{
		if (fValue < 1.0)
			return Radian(asin(fValue));
		else
			return Radian(HALF_PI);
	}
	else
	{
		return Radian(-HALF_PI);
	}
}
//-----------------------------------------------------------------------
Real Math::Sign(Real fValue)
{
	if (fValue > 0.0)
		return 1.0;

	if (fValue < 0.0)
		return -1.0;

	return 0.0;
}
//-----------------------------------------------------------------------
Real Math::InvSqrt(Real fValue)
{
	return Real(1. / sqrt(fValue));
}
//-----------------------------------------------------------------------
Real Math::UnitRandom()
{
	return rand() / Real(RAND_MAX);
}

//-----------------------------------------------------------------------
Real Math::RangeRandom(Real fLow, Real fHigh)
{
	return (fHigh - fLow) * UnitRandom() + fLow;
}

//-----------------------------------------------------------------------
Real Math::SymmetricRandom()
{
	return 2.0f * UnitRandom() - 1.0f;
}

//-----------------------------------------------------------------------
bool Math::RealEqual(Real a, Real b, Real tolerance)
{
	if (fabs(b - a) <= tolerance)
		return true;
	else
		return false;
}

//-----------------------------------------------------------------------
Real Math::gaussianDistribution(Real x, Real offset, Real scale)
{
	Real nom = Math::Exp(-Math::Sqr(x - offset) / (2 * Math::Sqr(scale)));
	Real denom = scale * Math::Sqrt(2 * Math::PI);

	return nom / denom;

}

END_NAMESPACE_IBI
