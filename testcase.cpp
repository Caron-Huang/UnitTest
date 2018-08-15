/*
 * testhelper.cpp
 *
 *  Created on: Jul 27, 2018
 *      Author: caron
 */

#include "testcase.h"

namespace test {

namespace {
class CTestCase {
public:
	CTestCase(const std::string &base, const std::string &name, void (*func)()) {
		_base.assign(base);
		_name.assign(name);
		_func = func;
	}
	void (*_func)();
private:
	std::string _base;
	std::string _name;
};
std::vector<CTestCase>* tests;
}

int regTestCase(const std::string &base, const std::string &name, void (*func)()) {
	if (NULL == tests) {
		tests = new std::vector<CTestCase>;
		if (NULL == tests) {
			return -1;
		}
	}
	CTestCase t(base, name, func);
	tests->push_back(t);
	return 0;
}

int runAllTests() {
	unsigned int i;
	if (NULL == tests) {
		return 0;
	}

	for (i = 0; i < tests->size(); i++) {
		const CTestCase &t = (*tests)[i];

		(*t._func)();
	}

	return 0;
}
}
