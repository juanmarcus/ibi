/*
 * Exception.cpp
 *
 *  Created on: Oct 9, 2009
 *      Author: Juan Ibiapina
 */

#include "Exception.h"

namespace ibi
{

using namespace std;

Exception::Exception(String file, String general, String detail) :
	exception()
{
	this->file = file;
	this->general = general;
	this->detail = detail;
}

Exception::~Exception() throw ()
{

}

} // namespace ibi
