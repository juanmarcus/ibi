/*
 * RenderSystem.h
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#ifndef RENDERSYSTEM_H_
#define RENDERSYSTEM_H_

#include "ibi_internal.h"
#include "ibi_scene_graph/SceneGraph.h"
#include "ibi_scene_graph/Renderable.h"

namespace ibi
{

class RenderSystem
{
public:
	RenderSystem();
	virtual ~RenderSystem();

	void render(SceneGraph* sceneGraph);
protected:
	void renderSceneNode(SceneNode* node);
	virtual void renderRenderable(Renderable* renderable) = 0;
	virtual void applyTransform(Matrix4& transform) = 0;
	virtual void resetTransform() = 0;
};

} // namespace ibi

#endif /* RENDERSYSTEM_H_ */
