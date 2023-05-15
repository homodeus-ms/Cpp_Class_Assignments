#include <iostream>
#include <cassert>
#include "TimeSheet.h"

void test();

void TestAddTime()
{
	lab3::TimeSheet m("mong", 3);
	assert(m.GetTotalTime() == 0);

	m.AddTime(5);
	assert(m.GetTotalTime() == 5);

	m.AddTime(1);
	assert(m.GetTotalTime() == 6);

	m.AddTime(0);
	assert(m.GetTotalTime() == 6);

	m.AddTime(-1);
	assert(m.GetTotalTime() == 6);

	m.AddTime(11);
	assert(m.GetTotalTime() == 6);

	m.AddTime(12);
	assert(m.GetTotalTime() == 6);

	m.AddTime(10);
	assert(m.GetTotalTime() == 16);

	m.AddTime(5);
	assert(m.GetTotalTime() == 16);
}

void TestGetTimeEntry()
{
	lab3::TimeSheet s("shell", 5);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == -1);
	assert(s.GetTimeEntry(1) == -1);
	assert(s.GetTimeEntry(2) == -1);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(0);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == -1);
	assert(s.GetTimeEntry(1) == -1);
	assert(s.GetTimeEntry(2) == -1);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(2);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == -1);
	assert(s.GetTimeEntry(2) == -1);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(4);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == -1);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(6);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == 6);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(-1000);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == 6);
	assert(s.GetTimeEntry(3) == -1);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(8);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == 6);
	assert(s.GetTimeEntry(3) == 8);
	assert(s.GetTimeEntry(4) == -1);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(10);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == 6);
	assert(s.GetTimeEntry(3) == 8);
	assert(s.GetTimeEntry(4) == 10);
	assert(s.GetTimeEntry(5) == -1);

	s.AddTime(1000);
	assert(s.GetTimeEntry(-1) == -1);
	assert(s.GetTimeEntry(0) == 2);
	assert(s.GetTimeEntry(1) == 4);
	assert(s.GetTimeEntry(2) == 6);
	assert(s.GetTimeEntry(3) == 8);
	assert(s.GetTimeEntry(4) == 10);
	assert(s.GetTimeEntry(5) == -1);
}

void TestGetTotalTime()
{
	lab3::TimeSheet m("mong", 5);
	assert(m.GetTotalTime() == 0);

	m.AddTime(-1);
	assert(m.GetTotalTime() == 0);

	m.AddTime(0);
	assert(m.GetTotalTime() == 0);

	m.AddTime(1);
	assert(m.GetTotalTime() == 1);

	m.AddTime(2);
	assert(m.GetTotalTime() == 3);

	m.AddTime(3);
	assert(m.GetTotalTime() == 6);

	m.AddTime(10);
	assert(m.GetTotalTime() == 16);

	m.AddTime(11);
	assert(m.GetTotalTime() == 16);

	m.AddTime(12);
	assert(m.GetTotalTime() == 16);

	m.AddTime(9);
	assert(m.GetTotalTime() == 25);

	m.AddTime(9);
	assert(m.GetTotalTime() == 25);
}

void TestGetAverageTime()
{
	lab3::TimeSheet s("shell", 10);
	assert(s.GetAverageTime() == 0.f);

	s.AddTime(-1);
	assert(s.GetAverageTime() == 0.f);

	s.AddTime(0);
	assert(s.GetAverageTime() == 0.f);

	s.AddTime(11);
	assert(s.GetAverageTime() == 0.f);

	s.AddTime(12);
	assert(s.GetAverageTime() == 0.f);

}

void TestGetStandardDeviation()
{
	// Values used in assert are calculated here:
	// https://www.calculator.net/standard-deviation-calculator.html

	lab3::TimeSheet s("shell", 10);
	assert(s.GetStandardDeviation() == 0.f);

	s.AddTime(-1);
	s.AddTime(0);
	s.AddTime(11);
	s.AddTime(12);
	assert(s.GetStandardDeviation() == 0.f);

	s.AddTime(4);
	s.AddTime(7);
	s.AddTime(6);
	s.AddTime(5);
	s.AddTime(1);
	s.AddTime(2);
	assert(fabs(2.1147629234083f - s.GetStandardDeviation()) < 0.00001f);

	s.AddTime(-1);
	s.AddTime(0);
	s.AddTime(11);
	s.AddTime(12);
	assert(fabs(2.1147629234083f - s.GetStandardDeviation()) < 0.00001f);

	s.AddTime(7);
	s.AddTime(8);
	assert(fabs(2.3452078799117f - s.GetStandardDeviation()) < 0.00001f);

	s.AddTime(9);
	s.AddTime(10);
	assert(fabs(2.7730849247724f - s.GetStandardDeviation()) < 0.00001f);

	s.AddTime(10);
	s.AddTime(10);
	s.AddTime(10);
	s.AddTime(10);
	assert(fabs(2.7730849247724f - s.GetStandardDeviation()) < 0.00001f);
}

void TestGetName()
{
	lab3::TimeSheet m("mong", 3);
	lab3::TimeSheet s("shell", 3);

	assert(m.GetName() == "mong");
	assert(s.GetName() == "shell");
	assert(m.GetName() != s.GetName());
}

void TestCopyConstructor()
{
	lab3::TimeSheet m("mong", 5);
	m.AddTime(1);
	m.AddTime(2);
	m.AddTime(3);

	lab3::TimeSheet m2 = m;

	assert(m.GetName() == m2.GetName());
	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) == m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() == m2.GetTotalTime());
	assert(m.GetAverageTime() == m2.GetAverageTime());
	assert(m.GetStandardDeviation() == m2.GetStandardDeviation());

	m.AddTime(4);

	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) != m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() != m2.GetTotalTime());
	assert(m.GetAverageTime() != m2.GetAverageTime());
	assert(m.GetStandardDeviation() != m2.GetStandardDeviation());

	m2.AddTime(5);

	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) != m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() != m2.GetTotalTime());
	assert(m.GetAverageTime() != m2.GetAverageTime());
	assert(m.GetStandardDeviation() != m2.GetStandardDeviation());
}

void TestAssignmentOperator()
{
	lab3::TimeSheet m("mong", 3);
	m.AddTime(1);
	m.AddTime(2);
	m.AddTime(3);

	lab3::TimeSheet s("shell", 5);
	s.AddTime(2);
	s.AddTime(4);
	s.AddTime(6);
	s.AddTime(8);
	s.AddTime(10);

	assert(m.GetName() == "mong");
	assert(m.GetTimeEntry(0) == 1);
	assert(m.GetTimeEntry(1) == 2);
	assert(m.GetTimeEntry(2) == 3);
	assert(m.GetTimeEntry(3) == -1);
	assert(m.GetTimeEntry(4) == -1);

	m = m;

	assert(m.GetName() == "mong");
	assert(m.GetTimeEntry(0) == 1);
	assert(m.GetTimeEntry(1) == 2);
	assert(m.GetTimeEntry(2) == 3);
	assert(m.GetTimeEntry(3) == -1);
	assert(m.GetTimeEntry(4) == -1);

	m = s;

	std::cout << m.GetName() << std::endl;

	assert(m.GetName() == "shell");
	assert(m.GetTimeEntry(0) == 2);
	assert(m.GetTimeEntry(1) == 4);
	assert(m.GetTimeEntry(2) == 6);
	assert(m.GetTimeEntry(3) == 8);
	assert(m.GetTimeEntry(4) == 10);
}


int main()
{
	std::cout << "start" << std::endl;
	
    lab3::TimeSheet employee1("John", 10);
    employee1.AddTime(4);
    employee1.AddTime(7);

	std::cout << employee1.GetName() << std::endl;

    std::cout << "name: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;
	
	test();

	TestAddTime();
	TestGetTimeEntry();
	TestGetTotalTime();
	TestGetAverageTime();
	TestGetStandardDeviation();
	TestGetName();
	TestCopyConstructor();
	TestAssignmentOperator();


	std::cout << "NoAssert!!" << std::endl;

    return 0;
}

void test()
{
	lab3::TimeSheet employee1("John", 5);
	employee1.AddTime(1);    // ok
	employee1.AddTime(5);    // ok  
	employee1.AddTime(-1);   // Not ok
	employee1.AddTime(7);    // ok
	employee1.AddTime(10);   // ok
	employee1.AddTime(15);   // Not ok
	employee1.AddTime(3);    // ok
	employee1.AddTime(8);    // Not ok

	std::cout << employee1.GetTimeEntry(0) << std::endl;    // 1
	std::cout << employee1.GetTimeEntry(-1) << std::endl;   // -1
	std::cout << employee1.GetTimeEntry(5) << std::endl;    // -1
	std::cout << employee1.GetTimeEntry(4) << std::endl;    // 3
	std::cout << employee1.GetTimeEntry(1) << std::endl;    // 5
	std::cout << employee1.GetTimeEntry(7) << std::endl;    // -1

	std::cout << employee1.GetTotalTime() << std::endl;         // 26
	std::cout << employee1.GetAverageTime() << std::endl;       // 5.2
	std::cout << employee1.GetStandardDeviation() << std::endl; // 3.1241
	std::cout << employee1.GetName() << std::endl;              // John

	lab3::TimeSheet employee2("Pope", 10);
	employee2.AddTime(4);    // ok
	employee2.AddTime(7);    // ok
	employee2.AddTime(6);    // ok

	std::cout << employee2.GetTotalTime() << std::endl;          // 17
	std::cout << employee2.GetAverageTime() << std::endl;        // 5.66667

	lab3::TimeSheet pope(employee2);

	pope.AddTime(5);    // ok
	pope.AddTime(1);    // ok
	pope.AddTime(2);    // ok

	std::cout << pope.GetTotalTime() << std::endl;          // 25
	std::cout << pope.GetAverageTime() << std::endl;        // 4.16667
	std::cout << pope.GetStandardDeviation() << std::endl;  // 2.11476(모집단의 표준편차)
	std::cout << pope.GetName() << std::endl;               // Pope

	lab3::TimeSheet hulk("HULK", 10);
	std::cout << hulk.GetStandardDeviation() << std::endl;//0.0
}
