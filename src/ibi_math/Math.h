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
#include <cassert>
#include <limits>
#include <algorithm>

class Degree;
class Radian;

class Radian
{
	Real mRad;

public:
	explicit Radian(Real r = 0) :
		mRad(r)
	{
	}

	Radian(const Degree& d);
	Radian& operator =(const Real& f)
	{
		mRad = f;
		return *this;
	}
	Radian& operator =(const Radian& r)
	{
		mRad = r.mRad;
		return *this;
	}
	Radian& operator =(const Degree& d);

	Real valueDegrees() const; // see bottom of this file
	Real valueRadians() const
	{
		return mRad;
	}
	Real valueAngleUnits() const;

	const Radian& operator +() const
	{
		return *this;
	}
	Radian operator +(const Radian& r) const
	{
		return Radian(mRad + r.mRad);
	}
	Radian operator +(const Degree& d) const;
	Radian& operator +=(const Radian& r)
	{
		mRad += r.mRad;
		return *this;
	}
	Radian& operator +=(const Degree& d);
	Radian operator -() const
	{
		return Radian(-mRad);
	}
	Radian operator -(const Radian& r) const
	{
		return Radian(mRad - r.mRad);
	}
	Radian operator -(const Degree& d) const;
	Radian& operator -=(const Radian& r)
	{
		mRad -= r.mRad;
		return *this;
	}
	Radian& operator -=(const Degree& d);
	Radian operator *(Real f) const
	{
		return Radian(mRad * f);
	}
	Radian operator *(const Radian& f) const
	{
		return Radian(mRad * f.mRad);
	}
	Radian& operator *=(Real f)
	{
		mRad *= f;
		return *this;
	}
	Radian operator /(Real f) const
	{
		return Radian(mRad / f);
	}
	Radian& operator /=(Real f)
	{
		mRad /= f;
		return *this;
	}

	bool operator <(const Radian& r) const
	{
		return mRad < r.mRad;
	}
	bool operator <=(const Radian& r) const
	{
		return mRad <= r.mRad;
	}
	bool operator ==(const Radian& r) const
	{
		return mRad == r.mRad;
	}
	bool operator !=(const Radian& r) const
	{
		return mRad != r.mRad;
	}
	bool operator >=(const Radian& r) const
	{
		return mRad >= r.mRad;
	}
	bool operator >(const Radian& r) const
	{
		return mRad > r.mRad;
	}

};

class Degree
{
	Real mDeg; // if you get an error here - make sure to define/typedef 'Real' first

public:
	explicit Degree(Real d = 0) :
		mDeg(d)
	{
	}
	Degree(const Radian& r) :
		mDeg(r.valueDegrees())
	{
	}
	Degree& operator =(const Real& f)
	{
		mDeg = f;
		return *this;
	}
	Degree& operator =(const Degree& d)
	{
		mDeg = d.mDeg;
		return *this;
	}
	Degree& operator =(const Radian& r)
	{
		mDeg = r.valueDegrees();
		return *this;
	}

	Real valueDegrees() const
	{
		return mDeg;
	}
	Real valueRadians() const; // see bottom of this file
	Real valueAngleUnits() const;

	const Degree& operator +() const
	{
		return *this;
	}
	Degree operator +(const Degree& d) const
	{
		return Degree(mDeg + d.mDeg);
	}
	Degree operator +(const Radian& r) const
	{
		return Degree(mDeg + r.valueDegrees());
	}
	Degree& operator +=(const Degree& d)
	{
		mDeg += d.mDeg;
		return *this;
	}
	Degree& operator +=(const Radian& r)
	{
		mDeg += r.valueDegrees();
		return *this;
	}
	Degree operator -() const
	{
		return Degree(-mDeg);
	}
	Degree operator -(const Degree& d) const
	{
		return Degree(mDeg - d.mDeg);
	}
	Degree operator -(const Radian& r) const
	{
		return Degree(mDeg - r.valueDegrees());
	}
	Degree& operator -=(const Degree& d)
	{
		mDeg -= d.mDeg;
		return *this;
	}
	Degree& operator -=(const Radian& r)
	{
		mDeg -= r.valueDegrees();
		return *this;
	}
	Degree operator *(Real f) const
	{
		return Degree(mDeg * f);
	}
	Degree operator *(const Degree& f) const
	{
		return Degree(mDeg * f.mDeg);
	}
	Degree& operator *=(Real f)
	{
		mDeg *= f;
		return *this;
	}
	Degree operator /(Real f) const
	{
		return Degree(mDeg / f);
	}
	Degree& operator /=(Real f)
	{
		mDeg /= f;
		return *this;
	}

	bool operator <(const Degree& d) const
	{
		return mDeg < d.mDeg;
	}
	bool operator <=(const Degree& d) const
	{
		return mDeg <= d.mDeg;
	}
	bool operator ==(const Degree& d) const
	{
		return mDeg == d.mDeg;
	}
	bool operator !=(const Degree& d) const
	{
		return mDeg != d.mDeg;
	}
	bool operator >=(const Degree& d) const
	{
		return mDeg >= d.mDeg;
	}
	bool operator >(const Degree& d) const
	{
		return mDeg > d.mDeg;
	}

};

//class Angle
//{
//	Real mAngle;
//public:
//	explicit Angle(Real angle) :
//		mAngle(angle)
//	{
//	}
//	operator Radian() const;
//	operator Degree() const;
//};

// these functions could not be defined within the class definition of class
// Radian because they required class Degree to be defined
inline Radian::Radian(const Degree& d) :
	mRad(d.valueRadians())
{
}
inline Radian& Radian::operator =(const Degree& d)
{
	mRad = d.valueRadians();
	return *this;
}
inline Radian Radian::operator +(const Degree& d) const
{
	return Radian(mRad + d.valueRadians());
}
inline Radian& Radian::operator +=(const Degree& d)
{
	mRad += d.valueRadians();
	return *this;
}
inline Radian Radian::operator -(const Degree& d) const
{
	return Radian(mRad - d.valueRadians());
}
inline Radian& Radian::operator -=(const Degree& d)
{
	mRad -= d.valueRadians();
	return *this;
}

class Math
{
public:

	static inline int IAbs(int iValue)
	{
		return (iValue >= 0 ? iValue : -iValue);
	}
	static inline int ICeil(float fValue)
	{
		return int(ceil(fValue));
	}
	static inline int IFloor(float fValue)
	{
		return int(floor(fValue));
	}
	static int ISign(int iValue);

	static inline Real Abs(Real fValue)
	{
		return Real(fabs(fValue));
	}
	static inline Degree Abs(const Degree& dValue)
	{
		return Degree(fabs(dValue.valueDegrees()));
	}
	static inline Radian Abs(const Radian& rValue)
	{
		return Radian(fabs(rValue.valueRadians()));
	}
	static Radian ACos(Real fValue);
	static Radian ASin(Real fValue);
	static inline Radian ATan(Real fValue)
	{
		return Radian(atan(fValue));
	}
	static inline Radian ATan2(Real fY, Real fX)
	{
		return Radian(atan2(fY, fX));
	}
	static inline Real Ceil(Real fValue)
	{
		return Real(ceil(fValue));
	}

	static inline Real Cos(const Radian& fValue, bool useTables = false)
	{
		return Real(cos(fValue.valueRadians()));
	}

	static inline Real Cos(Real fValue, bool useTables = false)
	{
		return Real(cos(fValue));
	}

	static inline Real Exp(Real fValue)
	{
		return Real(exp(fValue));
	}

	static inline Real Floor(Real fValue)
	{
		return Real(floor(fValue));
	}

	static inline Real Log(Real fValue)
	{
		return Real(log(fValue));
	}

	static inline Real Pow(Real fBase, Real fExponent)
	{
		return Real(pow(fBase, fExponent));
	}

	static Real Sign(Real fValue);
	static inline Radian Sign(const Radian& rValue)
	{
		return Radian(Sign(rValue.valueRadians()));
	}
	static inline Degree Sign(const Degree& dValue)
	{
		return Degree(Sign(dValue.valueDegrees()));
	}

	static inline Real Sin(const Radian& fValue, bool useTables = false)
	{
		return Real(sin(fValue.valueRadians()));
	}

	static inline Real Sin(Real fValue, bool useTables = false)
	{
		return Real(sin(fValue));
	}

	static inline Real Sqr(Real fValue)
	{
		return fValue * fValue;
	}

	static inline Real Sqrt(Real fValue)
	{
		return Real(sqrt(fValue));
	}

	static inline Radian Sqrt(const Radian& fValue)
	{
		return Radian(sqrt(fValue.valueRadians()));
	}

	static inline Degree Sqrt(const Degree& fValue)
	{
		return Degree(sqrt(fValue.valueDegrees()));
	}

	/** Inverse square root i.e. 1 / Sqrt(x), good for vector
	 normalisation.
	 */
	static Real InvSqrt(Real fValue);

	static Real UnitRandom(); // in [0,1]

	static Real RangeRandom(Real fLow, Real fHigh); // in [fLow,fHigh]

	static Real SymmetricRandom(); // in [-1,1]

	static inline Real Tan(const Radian& fValue, bool useTables = false)
	{
		return Real(tan(fValue.valueRadians()));
	}

	static inline Real Tan(Real fValue, bool useTables = false)
	{
		return Real(tan(fValue));
	}

	static inline Real DegreesToRadians(Real degrees)
	{
		return degrees * fDeg2Rad;
	}
	static inline Real RadiansToDegrees(Real radians)
	{
		return radians * fRad2Deg;
	}

	/** Compare 2 reals, using tolerance for inaccuracies.
	 */
	static bool RealEqual(Real a, Real b, Real tolerance = std::numeric_limits<
			Real>::epsilon());

	/** Generates a value based on the Gaussian (normal) distribution function
	 with the given offset and scale parameters.
	 */
	static Real gaussianDistribution(Real x, Real offset = 0.0f, Real scale =
			1.0f);

	/** Clamp a value within an inclusive range. */
	template<typename T>
	static T Clamp(T val, T minval, T maxval)
	{
		assert(minval < maxval && "Invalid clamp range");
		return std::max(std::min(val, maxval), minval);
	}

	static const Real POS_INFINITY;
	static const Real NEG_INFINITY;
	static const Real PI;
	static const Real TWO_PI;
	static const Real HALF_PI;
	static const Real fDeg2Rad;
	static const Real fRad2Deg;

};

// these functions must be defined down here, because they rely on the
// angle unit conversion functions in class Math:

inline Real Radian::valueDegrees() const
{
	return Math::RadiansToDegrees(mRad);
}

inline Real Degree::valueRadians() const
{
	return Math::DegreesToRadians(mDeg);
}

inline Radian operator *(Real a, const Radian& b)
{
	return Radian(a * b.valueRadians());
}

inline Radian operator /(Real a, const Radian& b)
{
	return Radian(a / b.valueRadians());
}

inline Degree operator *(Real a, const Degree& b)
{
	return Degree(a * b.valueDegrees());
}

inline Degree operator /(Real a, const Degree& b)
{
	return Degree(a / b.valueDegrees());
}

#endif /* MATH_H_ */
