/*
 * GPUProgram.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef GPUPROGRAM_H_
#define GPUPROGRAM_H_

#include "ibi_internal.h"
#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/Texture.h"
#include <Cg/cg.h>

BEGIN_NAMESPACE_IBI

class GPUProgramManager;

class GPUProgram
{
public:
	friend class GPUProgramManager;

	class Parameter
	{
	public:
		void setTexture(Texture* t);
	public:
		CGparameter cgparameter;
	};

	GPUProgram(GPUProgramManager* parent);
	~GPUProgram();

	void enable();
	void disable();

	Parameter getNamedParameter(String name);
protected:
	CGprofile profile;
	CGprogram program;
	GPUProgramManager* parent;
};

END_NAMESPACE_IBI

#endif /* GPUPROGRAM_H_ */
