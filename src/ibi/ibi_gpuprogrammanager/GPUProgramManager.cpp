/*
 * GPUProgramManager.cpp
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#include "GPUProgramManager.h"

#include <Cg/cgGL.h>
#include "ibi_error/Exception.h"
#include <iostream>

using namespace std;

namespace ibi
{

GPUProgramManager::GPUProgramManager()
{

}

GPUProgramManager::~GPUProgramManager()
{

}

void GPUProgramManager::init()
{
	context = cgCreateContext();
	checkError();

	cgGLRegisterStates(context);
	checkError();

	vertex_profile = cgGLGetLatestProfile(CG_GL_VERTEX);
	fragment_profile = cgGLGetLatestProfile(CG_GL_FRAGMENT);

}

VertexProgram* GPUProgramManager::loadVertexProgram(String path, String entry)
{
	VertexProgram* prog = new VertexProgram();

	cgGLEnableProfile(vertex_profile);

	CGprogram program = cgCreateProgramFromFile(context, CG_SOURCE,
			path.c_str(), vertex_profile, entry.c_str(), NULL);
	if (!cgIsProgramCompiled(program))
		cgCompileProgram(program);

	cgGLLoadProgram(program);

	cgGLDisableProfile(vertex_profile);

	checkError();

	prog->profile = vertex_profile;
	prog->program = program;

	return prog;
}

FragmentProgram* GPUProgramManager::loadFragmentProgram(String path,
		String entry)
{
	FragmentProgram* prog = new FragmentProgram();

	cgGLEnableProfile(fragment_profile);

	CGprogram program = cgCreateProgramFromFile(context, CG_SOURCE,
			path.c_str(), fragment_profile, entry.c_str(), NULL);
	if (!cgIsProgramCompiled(program))
		cgCompileProgram(program);

	cgGLLoadProgram(program);

	cgGLDisableProfile(fragment_profile);

	checkError();

	prog->profile = fragment_profile;
	prog->program = program;

	return prog;
}

void GPUProgramManager::checkError()
{
	CGerror lastError = cgGetError();
	if (lastError)
	{
		//		cout << cgGetErrorString(lastError) << endl;
		if (context != NULL)
			cout << cgGetLastListing(context) << endl;
		throw Exception(cgGetErrorString(lastError));
	}
}

} // namespace ibi
