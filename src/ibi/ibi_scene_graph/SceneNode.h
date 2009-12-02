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
	void setTranslation(Vector3& translation);

	SceneNode* getParentSceneNode();
	Renderable* getRenderable();
	std::vector<SceneNode*> getChildren();
	Vector3 getTranslation();

	void update(bool render);
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
	 * SceneNode translation relative to parent.
	 */
	Vector3 translation;

};

} // namespace ibi

#endif /* SCENENODE_H_ */
