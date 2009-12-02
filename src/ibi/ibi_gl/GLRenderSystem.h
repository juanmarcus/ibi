/*
 * GLRenderSystem.h
 *
 *  Created on: Dec 1, 2009
 *      Author: juanmarcus
 */

#ifndef GLRENDERSYSTEM_H_
#define GLRENDERSYSTEM_H_

#include "ibi_internal.h"
#include "ibi_render_system/RenderSystem.h"

namespace ibi
{

class GLRenderSystem: public RenderSystem
{
public:
	GLRenderSystem();
	virtual ~GLRenderSystem();

	virtual void renderRenderable(Renderable* renderable);
	virtual void applyTransform(Matrix4& transform);
	virtual void resetTransform();
};

} // namespace ibi

#endif /* GLRENDERSYSTEM_H_ */
