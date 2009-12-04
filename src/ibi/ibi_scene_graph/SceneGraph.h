/*
 * SceneGraph.h
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include "ibi_internal.h"
#include "SceneNode.h"

BEGIN_NAMESPACE_IBI

class SceneGraph
{
public:
	SceneGraph();
	virtual ~SceneGraph();

	SceneNode* getRootSceneNode();

	void update(bool render = true);
private:
	/**
	 * Root SceneNode.
	 */
	SceneNode* rootSceneNode;

};

END_NAMESPACE_IBI

#endif /* SCENEGRAPH_H_ */
