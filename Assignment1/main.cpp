#include <iostream>
#include <cassert>

#include "MyString.h"

using namespace assignment1;

int main()
{

	std::cout << "Start!!" << std::endl;
	/*
	MyString str("");
	str.Append("Hello");
	assert(strcmp(str.GetCString(), "Hello") == 0);
	std::cout << "nullptr ���� ���� Append : " << str.GetCString() << std::endl;
	*/

	MyString constructorTest("Hello");
	std::cout << "���ڿ� ���� : " << constructorTest.GetCString() << std::endl;
	std::cout << "���ڿ� ���� ���� : " << constructorTest.GetLength() << std::endl;
	assert(strcmp(constructorTest.GetCString(), "Hello") == 0);
	assert(constructorTest.GetLength() == 5);


	std::cout << std::hex;
	MyString originalStr("Hello");
	MyString copyStr(originalStr);
	int originalStrAddress = reinterpret_cast<int>(originalStr.GetCString());
	int copyStrAddress = reinterpret_cast<int>(copyStr.GetCString());
	std::cout << "���� : " << originalStr.GetCString() << ", ���� �ּ� : " << originalStrAddress << std::endl;
	std::cout << "���纻 : " << copyStr.GetCString() << ", ���纻 �ּ� : " << copyStrAddress << std::endl;
	assert(originalStrAddress != copyStrAddress);
	assert(strcmp(originalStr.GetCString(), "Hello") == 0);
	assert(strcmp(copyStr.GetCString(), "Hello") == 0);


	MyString appendTestFunctional("Hello");
	appendTestFunctional.Append(" World");
	std::cout << "���ڿ� �̾� ������ �Լ��� ���ΰ� ���� : " << appendTestFunctional.GetCString() << std::endl;
	assert(strcmp(appendTestFunctional.GetCString(), "Hello World") == 0);


	MyString appendTestOperator1("Hello");
	MyString appendTestOperator2(" World");
	MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
	std::cout << "���ڿ� �̾� ������ ������ ��ȯ : " << appendTestOperator3.GetCString() << std::endl;
	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);


	MyString indexOfTest("Hello");
	assert(indexOfTest.IndexOf("el") == 1);
	assert(indexOfTest.IndexOf("ll") == 2);
	assert(indexOfTest.IndexOf("l") == 2);
	assert(indexOfTest.IndexOf("asd") == -1);
	assert(indexOfTest.IndexOf("") == 0);
	//assert(indexOfTest.IndexOf(nullptr) == -1);
	assert(indexOfTest.IndexOf("lo") == 3);

	assert(indexOfTest.LastIndexOf("l") == 3);
	assert(indexOfTest.LastIndexOf("asd") == -1);
	assert(indexOfTest.LastIndexOf("") == indexOfTest.GetLength());
	//assert(indexOfTest.LastIndexOf(nullptr) == -1);
	assert(indexOfTest.LastIndexOf("He") == 0);

	MyString emptyIndexOfTest("");
	assert(emptyIndexOfTest.IndexOf("a") == -1);
	assert(emptyIndexOfTest.IndexOf("") == 0);
	assert(emptyIndexOfTest.LastIndexOf("") == emptyIndexOfTest.GetLength());

	/*
	int previousInterLeaveTestStrAddress = reinterpret_cast<int>(.GetCString());
	interLeaveTest.Interleave("");
	int currentInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	assert(previousInterLeaveTestStrAddress == currentInterLeaveTestStrAddress);
	*/
	std::cout << std::boolalpha;
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s�� "ello", b1�� true
	std::cout << "Hello�� ù���� ����� : " << removeTest.GetCString() << ", �������� : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);

	bool b2 = removeTest.RemoveAt(3); // s�� "ell", b2�� true
	std::cout << "ello�� �׹�° ���� ����� : " << removeTest.GetCString() << ", �������� : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);

	bool b3 = removeTest.RemoveAt(4); // s�� "ell", b3�� false
	std::cout << "ell�� �ټ���° ���� ����� : " << removeTest.GetCString() << ", �������� : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);



	MyString padLeftTest1("Hello");
	int previousPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	padLeftTest1.PadLeft(2); // s1: "Hello"
	int currentPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	std::cout << padLeftTest1.GetCString() << std::endl;
	assert(previousPadLeftTest1StrAddress == currentPadLeftTest1StrAddress);
	assert(strcmp(padLeftTest1.GetCString(), "Hello") == 0);

	padLeftTest1.PadLeft(8); // s1: "   Hello"
	assert(strcmp(padLeftTest1.GetCString(), "   Hello") == 0);
	std::cout << padLeftTest1.GetCString() << std::endl;



	MyString padLeftTest2("Hello");
	int previousPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	padLeftTest2.PadLeft(3, '-'); // s1: "Hello"
	int currentPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(previousPadLeftTest2StrAddress == currentPadLeftTest2StrAddress);
	assert(strcmp(padLeftTest2.GetCString(), "Hello") == 0);

	padLeftTest2.PadLeft(7, '-'); // s1: "   Hello"
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(strcmp(padLeftTest2.GetCString(), "--Hello") == 0);



	MyString padRightTest1("Hello");
	int previousPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	padRightTest1.PadRight(2); // s1: "Hello"
	int currentPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	std::cout << padRightTest1.GetCString() << std::endl;
	assert(previousPadRightTest1StrAddress == currentPadRightTest1StrAddress);
	assert(strcmp(padRightTest1.GetCString(), "Hello") == 0);

	padRightTest1.PadRight(8); // s1: "   Hello"
	std::cout << padRightTest1.GetCString() << "I" << std::endl;
	assert(strcmp(padRightTest1.GetCString(), "Hello   ") == 0);



	MyString padRightTest2("Hello");
	int previousPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	padRightTest2.PadRight(3, '-'); // s1: "Hello"
	int currentPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(previousPadRightTest2StrAddress == currentPadRightTest2StrAddress);
	assert(strcmp(padRightTest2.GetCString(), "Hello") == 0);

	padRightTest2.PadRight(7, '-'); // s1: "   Hello"
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(strcmp(padRightTest2.GetCString(), "Hello--") == 0);



	MyString reverseTest("Hello");
	int previousReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	reverseTest.Reverse();
	int currentReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	std::cout << "���ڸ� �Ųٷ� : " << reverseTest.GetCString() << std::endl;
	assert(strcmp(reverseTest.GetCString(), "olleH") == 0);



	MyString equelsOperatorTest1("Hello");
	MyString equelsOperatorTest2("Hello");
	MyString equelsOperatorTest3("World");
	assert((equelsOperatorTest1 == equelsOperatorTest2) == true);
	assert((equelsOperatorTest1 == equelsOperatorTest3) == false);



	MyString toLowerTest("HEllo 123K");
	toLowerTest.ToLower(); // s1: "hello 123k"
	assert(strcmp(toLowerTest.GetCString(), "hello 123k") == 0);
	std::cout << "��ü ���� �ҹ��ڷ� ���� : " << toLowerTest.GetCString() << std::endl;



	MyString toUpperTest("HEllo 123K");
	toUpperTest.ToUpper(); // s1: "HELLO 123K"
	assert(strcmp(toUpperTest.GetCString(), "HELLO 123K") == 0);
	std::cout << "��ü ���� �빮�ڷ� ���� : " << toUpperTest.GetCString() << std::endl;

	std::cout << "No Assert!!" << std::endl;

	return 0;
}
