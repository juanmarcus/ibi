/*
 * AxisAlignedBox.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef AXISALIGNEDBOX_H_
#define AXISALIGNEDBOX_H_

#include "Vector3.h"

class AxisAlignedBox
{
public:
	enum Extent
	{
		EXTENT_NULL, EXTENT_FINITE, EXTENT_INFINITE
	};
protected:

	Vector3 mMinimum;
	Vector3 mMaximum;
	Extent mExtent;
	//	mutable Vector3* mpCorners;
	//	Vector3 mpCorners[8];

public:
	/*
	 1-----2
	 /|    /|
	 / |   / |
	 5-----4  |
	 |  0--|--3
	 | /   | /
	 |/    |/
	 6-----7
	 */
	typedef enum
	{
		FAR_LEFT_BOTTOM = 0,
		FAR_LEFT_TOP = 1,
		FAR_RIGHT_TOP = 2,
		FAR_RIGHT_BOTTOM = 3,
		NEAR_RIGHT_BOTTOM = 7,
		NEAR_LEFT_BOTTOM = 6,
		NEAR_LEFT_TOP = 5,
		NEAR_RIGHT_TOP = 4
	} CornerEnum;
	inline AxisAlignedBox()
	{
		// Default to a null box
		setMinimum(-0.5, -0.5, -0.5);
		setMaximum(0.5, 0.5, 0.5);
		mExtent = EXTENT_NULL;
	}
	inline AxisAlignedBox(Extent e)
	{
		setMinimum(-0.5, -0.5, -0.5);
		setMaximum(0.5, 0.5, 0.5);
		mExtent = e;
	}

	inline AxisAlignedBox(const AxisAlignedBox & rkBox)
	{
		if (rkBox.isNull())
			setNull();
		else if (rkBox.isInfinite())
			setInfinite();
		else
			setExtents(rkBox.mMinimum, rkBox.mMaximum);
	}

	inline AxisAlignedBox(const Vector3& min, const Vector3& max)
	{
		setExtents(min, max);
	}

	inline AxisAlignedBox(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz)
	{
		setExtents(mx, my, mz, Mx, My, Mz);
	}

	AxisAlignedBox& operator=(const AxisAlignedBox& rhs)
	{
		// Specifically override to avoid copying mpCorners
		if (rhs.isNull())
			setNull();
		else if (rhs.isInfinite())
			setInfinite();
		else
			setExtents(rhs.mMinimum, rhs.mMaximum);

		return *this;
	}

	~AxisAlignedBox()
	{
		//		if (mpCorners)
		//			OGRE_FREE(mpCorners, MEMCATEGORY_SCENE_CONTROL);
	}

	/** Gets the minimum corner of the box.
	 */
	inline const Vector3& getMinimum(void) const
	{
		return mMinimum;
	}

	/** Gets a modifiable version of the minimum
	 corner of the box.
	 */
	inline Vector3& getMinimum(void)
	{
		return mMinimum;
	}

	/** Gets the maximum corner of the box.
	 */
	inline const Vector3& getMaximum(void) const
	{
		return mMaximum;
	}

	/** Gets a modifiable version of the maximum
	 corner of the box.
	 */
	inline Vector3& getMaximum(void)
	{
		return mMaximum;
	}

	/** Sets the minimum corner of the box.
	 */
	inline void setMinimum(const Vector3& vec)
	{
		mExtent = EXTENT_FINITE;
		mMinimum = vec;
	}

	inline void setMinimum(Real x, Real y, Real z)
	{
		mExtent = EXTENT_FINITE;
		mMinimum.x = x;
		mMinimum.y = y;
		mMinimum.z = z;
	}

	/** Changes one of the components of the minimum corner of the box
	 used to resize only one dimension of the box
	 */
	inline void setMinimumX(Real x)
	{
		mMinimum.x = x;
	}

	inline void setMinimumY(Real y)
	{
		mMinimum.y = y;
	}

	inline void setMinimumZ(Real z)
	{
		mMinimum.z = z;
	}

	/** Sets the maximum corner of the box.
	 */
	inline void setMaximum(const Vector3& vec)
	{
		mExtent = EXTENT_FINITE;
		mMaximum = vec;
	}

	inline void setMaximum(Real x, Real y, Real z)
	{
		mExtent = EXTENT_FINITE;
		mMaximum.x = x;
		mMaximum.y = y;
		mMaximum.z = z;
	}

	/** Changes one of the components of the maximum corner of the box
	 used to resize only one dimension of the box
	 */
	inline void setMaximumX(Real x)
	{
		mMaximum.x = x;
	}

	inline void setMaximumY(Real y)
	{
		mMaximum.y = y;
	}

	inline void setMaximumZ(Real z)
	{
		mMaximum.z = z;
	}

	/** Sets both minimum and maximum extents at once.
	 */
	inline void setExtents(const Vector3& min, const Vector3& max)
	{
		assert(
				(min.x <= max.x && min.y <= max.y && min.z <= max.z)
				&& "The minimum corner of the box must be less than or equal to maximum corner");

		mExtent = EXTENT_FINITE;
		mMinimum = min;
		mMaximum = max;
	}

	inline void setExtents(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz)
	{
		assert(
				(mx <= Mx && my <= My && mz <= Mz)
				&& "The minimum corner of the box must be less than or equal to maximum corner");

		mExtent = EXTENT_FINITE;

		mMinimum.x = mx;
		mMinimum.y = my;
		mMinimum.z = mz;

		mMaximum.x = Mx;
		mMaximum.y = My;
		mMaximum.z = Mz;

	}

	/** gets the position of one of the corners
	 */
	Vector3 getCorner(CornerEnum cornerToGet) const
	{
		switch (cornerToGet)
		{
		case FAR_LEFT_BOTTOM:
			return mMinimum;
		case FAR_LEFT_TOP:
			return Vector3(mMinimum.x, mMaximum.y, mMinimum.z);
		case FAR_RIGHT_TOP:
			return Vector3(mMaximum.x, mMaximum.y, mMinimum.z);
		case FAR_RIGHT_BOTTOM:
			return Vector3(mMaximum.x, mMinimum.y, mMinimum.z);
		case NEAR_RIGHT_BOTTOM:
			return Vector3(mMaximum.x, mMinimum.y, mMaximum.z);
		case NEAR_LEFT_BOTTOM:
			return Vector3(mMinimum.x, mMinimum.y, mMaximum.z);
		case NEAR_LEFT_TOP:
			return Vector3(mMinimum.x, mMaximum.y, mMaximum.z);
		case NEAR_RIGHT_TOP:
			return mMaximum;
		default:
			return Vector3();
		}
	}

	/** Merges the passed in box into the current box. The result is the
	 box which encompasses both.
	 */
	void merge(const AxisAlignedBox& rhs)
	{
		// Do nothing if rhs null, or this is infinite
		if ((rhs.mExtent == EXTENT_NULL) || (mExtent == EXTENT_INFINITE))
		{
			return;
		}
		// Otherwise if rhs is infinite, make this infinite, too
		else if (rhs.mExtent == EXTENT_INFINITE)
		{
			mExtent = EXTENT_INFINITE;
		}
		// Otherwise if current null, just take rhs
		else if (mExtent == EXTENT_NULL)
		{
			setExtents(rhs.mMinimum, rhs.mMaximum);
		}
		// Otherwise merge
		else
		{
			Vector3 min = mMinimum;
			Vector3 max = mMaximum;
			max.makeCeil(rhs.mMaximum);
			min.makeFloor(rhs.mMinimum);

			setExtents(min, max);
		}

	}

	/** Extends the box to encompass the specified point (if needed).
	 */
	inline void merge(const Vector3& point)
	{
		switch (mExtent)
		{
		case EXTENT_NULL: // if null, use this point
			setExtents(point, point);
			return;

		case EXTENT_FINITE:
			mMaximum.makeCeil(point);
			mMinimum.makeFloor(point);
			return;

		case EXTENT_INFINITE: // if infinite, makes no difference
			return;
		}

		assert(false && "Never reached");
	}

	/** Sets the box to a 'null' value i.e. not a box.
	 */
	inline void setNull()
	{
		mExtent = EXTENT_NULL;
	}

	/** Returns true if the box is null i.e. empty.
	 */
	inline bool isNull(void) const
	{
		return (mExtent == EXTENT_NULL);
	}

	/** Returns true if the box is finite.
	 */
	bool isFinite(void) const
	{
		return (mExtent == EXTENT_FINITE);
	}

	/** Sets the box to 'infinite'
	 */
	inline void setInfinite()
	{
		mExtent = EXTENT_INFINITE;
	}

	/** Returns true if the box is infinite.
	 */
	bool isInfinite(void) const
	{
		return (mExtent == EXTENT_INFINITE);
	}

	/** Returns whether or not this box intersects another. */
	inline bool intersects(const AxisAlignedBox& b2) const
	{
		// Early-fail for nulls
		if (this->isNull() || b2.isNull())
			return false;

		// Early-success for infinites
		if (this->isInfinite() || b2.isInfinite())
			return true;

		// Use up to 6 separating planes
		if (mMaximum.x < b2.mMinimum.x)
			return false;
		if (mMaximum.y < b2.mMinimum.y)
			return false;
		if (mMaximum.z < b2.mMinimum.z)
			return false;

		if (mMinimum.x > b2.mMaximum.x)
			return false;
		if (mMinimum.y > b2.mMaximum.y)
			return false;
		if (mMinimum.z > b2.mMaximum.z)
			return false;

		// otherwise, must be intersecting
		return true;

	}

	/// Calculate the area of intersection of this box and another
	inline AxisAlignedBox intersection(const AxisAlignedBox& b2) const
	{
		if (this->isNull() || b2.isNull())
		{
			return AxisAlignedBox();
		}
		else if (this->isInfinite())
		{
			return b2;
		}
		else if (b2.isInfinite())
		{
			return *this;
		}

		Vector3 intMin = mMinimum;
		Vector3 intMax = mMaximum;

		intMin.makeCeil(b2.getMinimum());
		intMax.makeFloor(b2.getMaximum());

		// Check intersection isn't null
		if (intMin.x < intMax.x && intMin.y < intMax.y && intMin.z < intMax.z)
		{
			return AxisAlignedBox(intMin, intMax);
		}

		return AxisAlignedBox();
	}

	/// Calculate the volume of this box
	Real volume(void) const
	{
		switch (mExtent)
		{
		case EXTENT_NULL:
			return 0.0f;

		case EXTENT_FINITE:
		{
			Vector3 diff = mMaximum - mMinimum;
			return diff.x * diff.y * diff.z;
		}

		case EXTENT_INFINITE:
			return Math::POS_INFINITY;

		default: // shut up compiler
			assert(false && "Never reached");
			return 0.0f;
		}
	}

	/** Scales the AABB by the vector given. */
	inline void scale(const Vector3& s)
	{
		// Do nothing if current null or infinite
		if (mExtent != EXTENT_FINITE)
			return;

		// NB assumes centered on origin
		Vector3 min = mMinimum * s;
		Vector3 max = mMaximum * s;
		setExtents(min, max);
	}

	/** Tests whether the vector point is within this box. */
	bool intersects(const Vector3& v) const
	{
		switch (mExtent)
		{
		case EXTENT_NULL:
			return false;

		case EXTENT_FINITE:
			return (v.x >= mMinimum.x && v.x <= mMaximum.x && v.y >= mMinimum.y
					&& v.y <= mMaximum.y && v.z >= mMinimum.z && v.z
					<= mMaximum.z);

		case EXTENT_INFINITE:
			return true;

		default: // shut up compiler
			assert(false && "Never reached");
			return false;
		}
	}
	/// Gets the centre of the box
	Vector3 getCenter(void) const
	{
		assert((mExtent == EXTENT_FINITE)
				&& "Can't get center of a null or infinite AAB");

		return Vector3((mMaximum.x + mMinimum.x) * 0.5, (mMaximum.y
				+ mMinimum.y) * 0.5, (mMaximum.z + mMinimum.z) * 0.5);
	}
	/// Gets the size of the box
	Vector3 getSize(void) const
	{
		switch (mExtent)
		{
		case EXTENT_NULL:
			return Vector3::ZERO;

		case EXTENT_FINITE:
			return mMaximum - mMinimum;

		case EXTENT_INFINITE:
			return Vector3(Math::POS_INFINITY, Math::POS_INFINITY,
					Math::POS_INFINITY);

		default: // shut up compiler
			assert(false && "Never reached");
			return Vector3::ZERO;
		}
	}
	/// Gets the half-size of the box
	Vector3 getHalfSize(void) const
	{
		switch (mExtent)
		{
		case EXTENT_NULL:
			return Vector3::ZERO;

		case EXTENT_FINITE:
			return (mMaximum - mMinimum) * 0.5;

		case EXTENT_INFINITE:
			return Vector3(Math::POS_INFINITY, Math::POS_INFINITY,
					Math::POS_INFINITY);

		default: // shut up compiler
			assert(false && "Never reached");
			return Vector3::ZERO;
		}
	}

	/** Tests whether the given point contained by this box.
	 */
	bool contains(const Vector3& v) const
	{
		if (isNull())
			return false;
		if (isInfinite())
			return true;

		return mMinimum.x <= v.x && v.x <= mMaximum.x && mMinimum.y <= v.y
				&& v.y <= mMaximum.y && mMinimum.z <= v.z && v.z <= mMaximum.z;
	}

	/** Tests whether another box contained by this box.
	 */
	bool contains(const AxisAlignedBox& other) const
	{
		if (other.isNull() || this->isInfinite())
			return true;

		if (this->isNull() || other.isInfinite())
			return false;

		return this->mMinimum.x <= other.mMinimum.x && this->mMinimum.y
				<= other.mMinimum.y && this->mMinimum.z <= other.mMinimum.z
				&& other.mMaximum.x <= this->mMaximum.x && other.mMaximum.y
				<= this->mMaximum.y && other.mMaximum.z <= this->mMaximum.z;
	}

	/** Tests 2 boxes for equality.
	 */
	bool operator==(const AxisAlignedBox& rhs) const
	{
		if (this->mExtent != rhs.mExtent)
			return false;

		if (!this->isFinite())
			return true;

		return this->mMinimum == rhs.mMinimum && this->mMaximum == rhs.mMaximum;
	}

	/** Tests 2 boxes for inequality.
	 */
	bool operator!=(const AxisAlignedBox& rhs) const
	{
		return !(*this == rhs);
	}

	// special values
	static const AxisAlignedBox BOX_NULL;
	static const AxisAlignedBox BOX_INFINITE;

};

#endif /* AXISALIGNEDBOX_H_ */
