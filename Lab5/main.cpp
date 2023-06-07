#include <cassert>
#include <iostream>

#include "Lawn.h"
#include "IFenceable.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace std;
using namespace lab5;
void Foo()
{
	Lawn* lawn = new RectangleLawn(10, 20);
	unsigned int area = lawn->GetArea();
	unsigned int grassPrice = lawn->GetGrassPrice(BERMUDA);
	unsigned int sodRollsCount = lawn->GetMinimumSodRollsCount();

	assert(area == 200);
	assert(grassPrice == 1600);
	assert(sodRollsCount == 667);

	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;

	unsigned int fencePrice = rectangleLawn->GetFencePrice(RED_CEDAR);
	unsigned int fencesCount = rectangleLawn->GetMinimumFencesCount();

	assert(fencePrice == 360);
	assert(fencesCount == 240);

	delete lawn;
}

int main()
{
	Foo();

	cout << "NO Assert!" << endl;

	// ���� ���� ������� �ٸ� ��ü Ŭ�����鵵 �׽�Ʈ�� �� ����
	return 0;
}