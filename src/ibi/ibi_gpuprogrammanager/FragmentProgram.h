/*
 * FragmentProgram.h
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#ifndef FRAGMENTPROGRAM_H_
#define FRAGMENTPROGRAM_H_

#include "ibi_internal.h"
#include <Cg/cg.h>
#include "GPUProgram.h"

namespace ibi
{

class FragmentProgram: public GPUProgram
{
public:
	FragmentProgram(GPUProgramManager* parent);
	~FragmentProgram();
};

} // namespace ibi

#endif /* FRAGMENTPROGRAM_H_ */
