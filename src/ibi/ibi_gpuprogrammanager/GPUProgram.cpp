/*
 * GPUProgram.cpp
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#include "GPUProgram.h"

#include <Cg/cgGL.h>
#include "GPUProgramManager.h"

BEGIN_NAMESPACE_IBI

GPUProgram::GPUProgram(GPUProgramManager* a_parent) :
	parent(a_parent)
{

}

GPUProgram::~GPUProgram()
{

}

void GPUProgram::enable()
{
	cgGLBindProgram(program);
	cgGLEnableProfile(profile);
	parent->checkError();
}

void GPUProgram::disable()
{
	cgGLDisableProfile(profile);
}

GPUProgram::Parameter GPUProgram::getNamedParameter(String name)
{
	GPUProgram::Parameter par;
	CGparameter cgparam = cgGetNamedParameter(program, name.c_str());
	parent->checkError();
	par.cgparameter = cgparam;
	return par;
}

void GPUProgram::Parameter::setTexture(Texture* t)
{
	cgGLSetTextureParameter(cgparameter, t->getGLName());
	cgGLEnableTextureParameter(cgparameter);
}

END_NAMESPACE_IBI
