/*
 * SceneNode.h
 *
 *  Created on: Dec 1, 2009
 *      Author: Juan Ibiapina
 */

#ifndef SCENENODE_H_
#define SCENENODE_H_

#include "ibi_internal.h"
#include "Renderable.h"
#include "ibi_geometry/Matrix4.h"
#include <vector>

namespace ibi
{

class SceneNode
{
public:
	SceneNode();
	virtual ~SceneNode();

	SceneNode* createChildSceneNode();
	void addChildSceneNode(SceneNode* node);

	void setParentSceneNode(SceneNode* node);
	void setRenderable(Renderable* renderable);

	SceneNode* getParentSceneNode();
	Matrix4 getTransformation();
	Renderable* getRenderable();
	std::vector<SceneNode*> getChildren();

	void update();
private:
	/*
	 * Children SceneNodes.
	 */
	std::vector<SceneNode*> children;

	/**
	 * SceneNode that holds this node.
	 */
	SceneNode* parent;

	/**
	 * Renderable object.
	 */
	Renderable* renderable;

	/*
	 * SceneNode transformation relative to parent SceneNode.
	 */
	Matrix4 transform;

};

} // namespace ibi

#endif /* SCENENODE_H_ */
