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

	static inline Real Sqrt(Real fValue)
	{
		return Real(sqrt(fValue));
	}

	static inline Real Abs(Real fValue)
	{
		return Real(fabs(fValue));
	}

	static const Real POS_INFINITY;
	static const Real NEG_INFINITY;
};

#endif /* MATH_H_ */
