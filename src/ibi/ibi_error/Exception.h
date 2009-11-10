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

} // namespace ibi

#endif /* EXCEPTION_H_ */
