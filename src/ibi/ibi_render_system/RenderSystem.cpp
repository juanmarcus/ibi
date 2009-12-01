/*
 * RenderSystem.cpp
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#include "RenderSystem.h"

#include "ibi_scene_graph/SceneNode.h"

namespace ibi
{

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::render(SceneGraph* sceneGraph)
{
	SceneNode* rootSceneNode = sceneGraph->getRootSceneNode();

	renderSceneNode(rootSceneNode);
}

void RenderSystem::renderSceneNode(SceneNode* node)
{
	Matrix4 transform = node->getTransformation();
	applyTransform(transform);
	Renderable* renderable = node->getRenderable();
	if (renderable)
	{
		renderRenderable(renderable);
	}
	// recurse to all children
	resetTransform();
}

} // namespace ibi
