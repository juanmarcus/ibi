/*
 * ibi_base.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Juan Ibiapina
 */

#ifndef IBI_BASE_H_
#define IBI_BASE_H_

#include <utility>
#include <string>

#define BEGIN_NAMESPACE_IBI namespace ibi {
#define END_NAMESPACE_IBI }

BEGIN_NAMESPACE_IBI

//-----------------------------------------------------------------------------
// Number

/*
 * Type for operating with floating point numbers.
 */
typedef float Real;

/*
 * A pair of floating point numbers.
 */
typedef std::pair<Real, Real> RealPair;

//-----------------------------------------------------------------------------
// String

/*
 * String type.
 */
typedef std::string String;

END_NAMESPACE_IBI

#endif /* IBI_BASE_H_ */
