/*
 * GPUProgram.cpp
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#include "GPUProgram.h"

#include <Cg/cgGL.h>

namespace ibi
{

GPUProgram::GPUProgram()
{

}

GPUProgram::~GPUProgram()
{

}

void GPUProgram::enable()
{
	cgGLBindProgram(program);
	cgGLEnableProfile(profile);
}

void GPUProgram::disable()
{

}

} // namespace ibi
