/*
 * test.h
 *
 *  Created on: Jul 27, 2018
 *      Author: caron
 */

#ifndef TEST_TESTCASE_H_
#define TEST_TESTCASE_H_
#include <stddef.h>
#include <string>
#include <vector>
namespace test {

extern int regTestCase(const std::string &base, const std::string &name, void (*func)());
extern int runAllTests();

#define STRCAT(a, b)	STRCAT1(a, b)
#define STRCAT1(a, b)	a##b

#define TEST(base, name)					\
class STRCAT(_Test_, name) : public base {	\
private:									\
	void _test_run();						\
public:										\
	static void _testRun() {				\
		STRCAT(_Test_, name) t;				\
		t._test_run();						\
	}										\
};											\
int STRCAT(_ignore_, name) = regTestCase(#base, #name, &STRCAT(_Test_, name)::_testRun);\
void STRCAT(_Test_, name)::_test_run()

}



#endif /* TEST_TESTCASE_H_ */
