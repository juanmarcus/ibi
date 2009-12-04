/*
 * Factory.h
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#ifndef FACTORY_H_
#define FACTORY_H_

BEGIN_NAMESPACE_IBI
{

template<typename Interface>
class Factory
{
public:
	virtual Interface* create() = 0;
};

END_NAMESPACE_IBI

#endif /* FACTORY_H_ */
