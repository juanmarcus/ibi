/*
 * GLRenderSystem.cpp
 *
 *  Created on: Dec 1, 2009
 *      Author: juanmarcus
 */

#include "GLRenderSystem.h"

#include "ibi_gl.h"

namespace ibi
{

GLRenderSystem::GLRenderSystem()
{

}

GLRenderSystem::~GLRenderSystem()
{

}

void GLRenderSystem::renderRenderable(Renderable* renderable)
{
	// render
}

void GLRenderSystem::applyTransform(Matrix4& transform)
{
	glPushMatrix();
	// Multiply current matrix
}

void GLRenderSystem::resetTransform()
{
	glPopMatrix();
}

} // namespace ibi
