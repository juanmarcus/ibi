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

namespace ibi
{

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

} // namespace ibi

#endif /* IBI_BASE_H_ */
