/*
 * SceneNode.cpp
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#include "SceneNode.h"

namespace ibi
{

SceneNode::SceneNode() :
	parent(0), renderable(0)
{
	transform = Matrix4::IDENTITY;
}

SceneNode::~SceneNode()
{

}

SceneNode* SceneNode::createChildSceneNode()
{
	SceneNode* node = new SceneNode();
	addChildSceneNode(node);
}

void SceneNode::addChildSceneNode(SceneNode* node)
{
	children.push_back(node);
	node->setParentSceneNode(this);
}

void SceneNode::setParentSceneNode(SceneNode* node)
{
	this->parent = node;
}

SceneNode* SceneNode::getParentSceneNode()
{
	return parent;
}

Renderable* SceneNode::getRenderable()
{
	return renderable;
}

Matrix4 SceneNode::getTransformation()
{
	return transform;
}

void SceneNode::update()
{
	std::vector<SceneNode*>::iterator it = children.begin();
	std::vector<SceneNode*>::iterator itEnd = children.end();
	for (; it != itEnd; ++it)
	{
		(*it)->update();
	}
}

} // namespace ibi
