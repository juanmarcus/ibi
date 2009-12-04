/*
 * Renderable.h
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include "ibi_internal.h"

BEGIN_NAMESPACE_IBI

class Renderable
{
public:
	Renderable();
	virtual ~Renderable();

	virtual void render() = 0;
};

END_NAMESPACE_IBI

#endif /* RENDERABLE_H_ */
