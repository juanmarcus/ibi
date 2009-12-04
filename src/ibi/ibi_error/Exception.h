/*
 * Exception.h
 *
 *  Created on: Oct 9, 2009
 *      Author: Juan Ibiapina
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "ibi_internal.h"
#include <exception>

BEGIN_NAMESPACE_IBI

class Exception: public std::exception
{
public:
	Exception(String file, String general, String detail = "");

	~Exception() throw ();

	virtual const char* what() const throw ()
	{
		String message = file + ": " + general + "\n" + detail;
		return message.c_str();
	}
private:
	String file;
	String general;
	String detail;
};

END_NAMESPACE_IBI

#endif /* EXCEPTION_H_ */
