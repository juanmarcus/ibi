/*
 * Triangle.h
 *
 *  Created on: Oct 28, 2009
 *      Author: juanmarcus
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Vector3.h"

class Triangle
{
public:
	Triangle()
	{

	}

	Triangle(Vector3& v0, Vector3& v1, Vector3 v2)
	{
		vertices[0] = v0;
		vertices[1] = v1;
		vertices[2] = v2;
	}

	~Triangle()
	{

	}

	Vector3 getVertex(int v)
	{
		assert(v < 3);
		return vertices[v];
	}
private:
	Vector3 vertices[3];
};

#endif /* TRIANGLE_H_ */
