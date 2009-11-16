/*
 * GPUProgramManager.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef GPUPROGRAMMANAGER_H_
#define GPUPROGRAMMANAGER_H_

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include "Cg/cg.h"
#include "VertexProgram.h"
#include "FragmentProgram.h"

namespace ibi
{

class GPUProgramManager
{
public:
	GPUProgramManager();
	virtual ~GPUProgramManager();

	/*
	 * Initialize the context and profiles.
	 */
	void init();

	VertexProgram* loadVertexProgram(String path, String entry = "main");
	FragmentProgram* loadFragmentProgram(String path, String entry = "main");

	/*
	 * Checks current context for errors.
	 */
	void checkError();
private:
	/*
	 * CG context.
	 */
	CGcontext context;

	/*
	 * Current vertex profile.
	 */
	CGprofile vertex_profile;

	/*
	 * * Current fragment profile.
	 */
	CGprofile fragment_profile;
};

} // namespace ibi

#endif /* GPUPROGRAMMANAGER_H_ */
