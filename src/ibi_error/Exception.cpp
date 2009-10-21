/*
 * Exception.cpp
 *
 *  Created on: Oct 9, 2009
 *      Author: Juan Ibiapina
 */

#include "Exception.h"

using namespace std;

Exception::Exception(string msg):
	exception()
{
	this->msg = msg;
}

Exception::~Exception() throw ()
{

}
