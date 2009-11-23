/*
 * Factory.h
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#ifndef FACTORY_H_
#define FACTORY_H_

namespace ibi
{

template<typename Interface>
class Factory
{
public:
	virtual Interface* create() = 0;
};

} // namespace ibi

#endif /* FACTORY_H_ */
