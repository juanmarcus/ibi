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

namespace ibi
{

class SceneGraph
{
public:
	SceneGraph();
	virtual ~SceneGraph();

	SceneNode* getRootSceneNode();

	void update();
private:
	/**
	 * Root SceneNode.
	 */
	SceneNode* rootSceneNode;

};

} // namespace ibi

#endif /* SCENEGRAPH_H_ */
