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
	std::vector<SceneNode*> children = node->getChildren();
	std::vector<SceneNode*>::iterator it = children.begin();
	std::vector<SceneNode*>::iterator itEnd = children.end();
	for (; it != itEnd; ++it)
	{
		renderSceneNode(*it);
	}
	resetTransform();
}

} // namespace ibi
