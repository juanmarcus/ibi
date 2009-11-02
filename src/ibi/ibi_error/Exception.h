/*
 * Exception.h
 *
 *  Created on: Oct 9, 2009
 *      Author: Juan Ibiapina
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "ibi.h"
#include <exception>

namespace ibi
{

class Exception: public std::exception
{
public:
	Exception(String msg);

	~Exception() throw ();

	virtual const char* what() const throw ()
	{
		return msg.c_str();
	}
private:
	String msg;

};

} // namespace ibi

#endif /* EXCEPTION_H_ */
