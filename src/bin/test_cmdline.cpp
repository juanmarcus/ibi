/*
 * test_cmdline.cpp
 *
 *  Created on: Oct 22, 2009
 *      Author: Juan Ibiapina
 */

#include "ibi_cmdline/CommandLineParser.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string input;
	int intvalue;
	float floatvalue;

	CommandLineParser p;
	p.addOption("input,i", value<string> (&input), "input file", false);
	p.addOption("intvalue,e", value<int> (&intvalue), "int value", true);
	p.addOption("floatvalue,f", value<float> (&floatvalue), "float value", true);

	if (!p.parse(argc, argv))
	{
		return 1;
	}

	return 0;
}
