/*
 * VertexProgram.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef VERTEXPROGRAM_H_
#define VERTEXPROGRAM_H_

#include "ibi_internal.h"
#include <Cg/cg.h>
#include "GPUProgram.h"

BEGIN_NAMESPACE_IBI

class VertexProgram: public GPUProgram
{
public:
	VertexProgram(GPUProgramManager* parent);
	~VertexProgram();
};

END_NAMESPACE_IBI

#endif /* VERTEXPROGRAM_H_ */
