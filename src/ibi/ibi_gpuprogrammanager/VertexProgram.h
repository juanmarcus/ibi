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

namespace ibi
{

class VertexProgram: public GPUProgram
{
public:
	VertexProgram(GPUProgramManager* parent);
	~VertexProgram();
};

} // namespace ibi

#endif /* VERTEXPROGRAM_H_ */
