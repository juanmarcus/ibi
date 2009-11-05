/*
 * VertexProgram.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef VERTEXPROGRAM_H_
#define VERTEXPROGRAM_H_

#include "ibi.h"
#include <Cg/cg.h>
#include "GPUProgram.h"

namespace ibi
{

class VertexProgram: public GPUProgram
{
public:
	VertexProgram();
	~VertexProgram();
};

} // namespace ibi

#endif /* VERTEXPROGRAM_H_ */