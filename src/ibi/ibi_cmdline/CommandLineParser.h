/*
 * CommandLineParser.h
 *
 *  Created on: Oct 8, 2009
 *      Author: Juan Ibiapina
 */

#ifndef COMMANDLINEPARSER_H_
#define COMMANDLINEPARSER_H_

#include "ibi_internal.h"
#include <boost/program_options.hpp>

BEGIN_NAMESPACE_IBI

namespace po = boost::program_options;

// Wrapper to avoid the calling program from using namespace boost::program_options
template<class T>
po::typed_value<T>*
value(T* v)
{
	po::typed_value<T>* r = new po::typed_value<T>(v);

	return r;
}

template<class T>
po::typed_value<T>*
value()
{
	return value<T> (0);
}

class CommandLineParser
{
public:
	CommandLineParser();
	~CommandLineParser();

	void addOption(const char* name, const po::value_semantic* s,
			const char* description, bool required = false);
	bool parse(int argc, char* argv[]);
	void printUsage();

protected:
	void saveRequired(const char* name);

private:
	po::options_description* config;
	std::vector<String> requiredOptions;
};

END_NAMESPACE_IBI

#endif /* COMMANDLINEPARSER_H_ */
