/*
 * Renderable.h
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include "ibi_internal.h"

namespace ibi
{

class Renderable
{
public:
	Renderable();
	virtual ~Renderable();

	virtual void render() = 0;
};

} // namespace ibi

#endif /* RENDERABLE_H_ */
