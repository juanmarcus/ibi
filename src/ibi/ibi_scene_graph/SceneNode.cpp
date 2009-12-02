/*
 * SceneNode.cpp
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#include "SceneNode.h"

#include "ibi_gl/ibi_gl.h"
#include "ibi_gl/GL.h"

namespace ibi
{

SceneNode::SceneNode() :
	parent(0), renderable(0)
{
	translation = Vector3::ZERO;
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

void SceneNode::setRenderable(Renderable* renderable)
{
	this->renderable = renderable;
}

void SceneNode::setTranslation(Vector3& translation)
{
	this->translation = translation;
}

SceneNode* SceneNode::getParentSceneNode()
{
	return parent;
}

Renderable* SceneNode::getRenderable()
{
	return renderable;
}

std::vector<SceneNode*> SceneNode::getChildren()
{
	return children;
}

Vector3 SceneNode::getTranslation()
{
	return translation;
}

void SceneNode::update(bool render)
{
	if (render)
	{
		glPushMatrix();
		GL::Translate(translation);

		if (renderable)
		{
			renderable->render();
		}
	}

	std::vector<SceneNode*>::iterator it = children.begin();
	std::vector<SceneNode*>::iterator itEnd = children.end();
	for (; it != itEnd; ++it)
	{
		(*it)->update(render);
	}

	if (render)
	{
		glPopMatrix();
	}
}

} // namespace ibi
