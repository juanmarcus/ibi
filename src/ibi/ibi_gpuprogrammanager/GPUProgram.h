/*
 * GPUProgram.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef GPUPROGRAM_H_
#define GPUPROGRAM_H_

#include "ibi.h"
#include <Cg/cg.h>

namespace ibi
{

class GPUProgram
{
public:
	friend class GPUProgramManager;

	GPUProgram();
	~GPUProgram();

	void enable();
	void disable();
protected:
	CGprofile profile;
	CGprogram program;
};

} // namespace ibi

#endif /* GPUPROGRAM_H_ */
