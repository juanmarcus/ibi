/*
 * Matrix3.h
 *
 *  Created on: Oct 27, 2009
 *      Author: Juan Ibiapina
 */

#ifndef MATRIX3_H_
#define MATRIX3_H_

#include "ibi.h"
#include "Vector3.h"
#include <memory>

namespace ibi
{

class Matrix3
{
public:
	/** Default constructor.
	 @note
	 It does <b>NOT</b> initialize the matrix for efficiency.
	 */
	inline Matrix3()
	{
	}
	;
	inline explicit Matrix3(const Real arr[3][3])
	{
		memcpy(m, arr, 9 * sizeof(Real));
	}
	inline Matrix3(const Matrix3& rkMatrix)
	{
		memcpy(m, rkMatrix.m, 9 * sizeof(Real));
	}
	Matrix3(Real fEntry00, Real fEntry01, Real fEntry02, Real fEntry10,
			Real fEntry11, Real fEntry12, Real fEntry20, Real fEntry21,
			Real fEntry22)
	{
		m[0][0] = fEntry00;
		m[0][1] = fEntry01;
		m[0][2] = fEntry02;
		m[1][0] = fEntry10;
		m[1][1] = fEntry11;
		m[1][2] = fEntry12;
		m[2][0] = fEntry20;
		m[2][1] = fEntry21;
		m[2][2] = fEntry22;
	}

	// member access, allows use of construct mat[r][c]
	inline Real* operator[](size_t iRow) const
	{
		return (Real*) m[iRow];
	}
	/*inline operator Real* ()
	 {
	 return (Real*)m[0];
	 }*/
	Vector3 GetColumn(size_t iCol) const;
	void SetColumn(size_t iCol, const Vector3& vec);
	void FromAxes(const Vector3& xAxis, const Vector3& yAxis,
			const Vector3& zAxis);

	// assignment and comparison
	inline Matrix3& operator=(const Matrix3& rkMatrix)
	{
		memcpy(m, rkMatrix.m, 9 * sizeof(Real));
		return *this;
	}
	bool operator==(const Matrix3& rkMatrix) const;
	inline bool operator!=(const Matrix3& rkMatrix) const
	{
		return !operator==(rkMatrix);
	}

	// arithmetic operations
	Matrix3 operator+(const Matrix3& rkMatrix) const;
	Matrix3 operator-(const Matrix3& rkMatrix) const;
	Matrix3 operator*(const Matrix3& rkMatrix) const;
	Matrix3 operator-() const;

	// matrix * vector [3x3 * 3x1 = 3x1]
	Vector3 operator*(const Vector3& rkVector) const;

	// vector * matrix [1x3 * 3x3 = 1x3]
	friend Vector3 operator*(const Vector3& rkVector, const Matrix3& rkMatrix);

	// matrix * scalar
	Matrix3 operator*(Real fScalar) const;

	// scalar * matrix
	friend Matrix3 operator*(Real fScalar, const Matrix3& rkMatrix);

	// utilities
	Matrix3 Transpose() const;
	bool Inverse(Matrix3& rkInverse, Real fTolerance = 1e-06) const;
	Matrix3 Inverse(Real fTolerance = 1e-06) const;
	Real Determinant() const;

	// singular value decomposition
	void
	SingularValueDecomposition(Matrix3& rkL, Vector3& rkS, Matrix3& rkR) const;
	void SingularValueComposition(const Matrix3& rkL, const Vector3& rkS,
			const Matrix3& rkR);

	// Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
	void Orthonormalize();

	// orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
	void QDUDecomposition(Matrix3& rkQ, Vector3& rkD, Vector3& rkU) const;

	Real SpectralNorm() const;

	// matrix must be orthonormal
	void ToAxisAngle(Vector3& rkAxis, Radian& rfAngle) const;
	inline void ToAxisAngle(Vector3& rkAxis, Degree& rfAngle) const
	{
		Radian r;
		ToAxisAngle(rkAxis, r);
		rfAngle = r;
	}
	void FromAxisAngle(const Vector3& rkAxis, const Radian& fRadians);

	// The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
	// where yaw is rotation about the Up vector, pitch is rotation about the
	// Right axis, and roll is rotation about the Direction axis.
	bool
	ToEulerAnglesXYZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	bool
	ToEulerAnglesXZY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	bool
	ToEulerAnglesYXZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	bool
	ToEulerAnglesYZX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	bool
	ToEulerAnglesZXY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	bool
	ToEulerAnglesZYX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
	void FromEulerAnglesXYZ(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	void FromEulerAnglesXZY(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	void FromEulerAnglesYXZ(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	void FromEulerAnglesYZX(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	void FromEulerAnglesZXY(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	void FromEulerAnglesZYX(const Radian& fYAngle, const Radian& fPAngle,
			const Radian& fRAngle);
	// eigensolver, matrix must be symmetric
	void
	EigenSolveSymmetric(Real afEigenvalue[3], Vector3 akEigenvector[3]) const;

	static void TensorProduct(const Vector3& rkU, const Vector3& rkV,
			Matrix3& rkProduct);

	/** Determines if this matrix involves a scaling. */
	inline bool hasScale() const
	{
		// check magnitude of column vectors (==local axes)
		Real t = m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0];
		if (!Math::RealEqual(t, 1.0, 1e-04))
			return true;
		t = m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1];
		if (!Math::RealEqual(t, 1.0, 1e-04))
			return true;
		t = m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2];
		if (!Math::RealEqual(t, 1.0, 1e-04))
			return true;

		return false;
	}

	static const Real EPSILON;
	static const Matrix3 ZERO;
	static const Matrix3 IDENTITY;

protected:
	// support for eigensolver
	void Tridiagonal(Real afDiag[3], Real afSubDiag[3]);
	bool QLAlgorithm(Real afDiag[3], Real afSubDiag[3]);

	// support for singular value decomposition
	static const Real ms_fSvdEpsilon;
	static const unsigned int ms_iSvdMaxIterations;
	static void Bidiagonalize(Matrix3& kA, Matrix3& kL, Matrix3& kR);
	static void GolubKahanStep(Matrix3& kA, Matrix3& kL, Matrix3& kR);

	// support for spectral norm
	static Real MaxCubicRoot(Real afCoeff[3]);

	Real m[3][3];

	// for faster access
	friend class Matrix4;
};

} // namespace ibi

#endif /* MATRIX3_H_ */
