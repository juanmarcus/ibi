/*
 * SceneGraph.cpp
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#include "SceneGraph.h"

BEGIN_NAMESPACE_IBI

SceneGraph::SceneGraph()
{
	rootSceneNode = new SceneNode();
}

SceneGraph::~SceneGraph()
{
	delete rootSceneNode;
}

SceneNode* SceneGraph::getRootSceneNode()
{
	return rootSceneNode;
}

void SceneGraph::update(bool render)
{
	rootSceneNode->update(render);
}

END_NAMESPACE_IBI
