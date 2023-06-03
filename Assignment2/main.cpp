#include <cassert>
#include <iostream>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"


using namespace assignment2;
using namespace std;

void DoSomething()
{
	Person* p = new Person("Bob1", 80);
	Person* p2 = new Person("Bob2", 70);
	Person* p3 = new Person("Bob3", 60);

	Person* p4 = new Person("Bob4", 50);
	Person* p5 = new Person("Bob5", 40);
	Person* p6 = new Person("Bob6", 30);

	Airplane* a = new Airplane(5);
	a->AddPassenger(p);
	a->AddPassenger(p2);
	

	Airplane* b = new Airplane(10);
	b->AddPassenger(p4);
	b->AddPassenger(p5);

	*a = *b;
	//Airplane c(a);

	delete b;
	cout << a->GetPassenger(0)->GetName() << " " << a->GetPassenger(1)->GetName() << endl;

	delete a;
}

void TestDeleteAirplane()
{
	Airplane* a1 = new Airplane(5);
	Person* a = new Person("aaa", 50);
	Person* b = new Person("bbb", 100);

	Airplane* a2 = new Airplane(5);
	Person* c = new Person("ccc", 50);
	Person* d = new Person("ddd", 100);

	a1->AddPassenger(a);
	a1->AddPassenger(b);

	a2->AddPassenger(c);
	a2->AddPassenger(d);

	*a1 = *a2;

	delete a1;
	delete a2;
}

void TestBoatplane()
{
	Airplane* a1 = new Airplane(5);
	Person* a = new Person("aaa", 50);
	Person* b = new Person("bbb", 100);

	Boat* b1 = new Boat(10);
	Person* c = new Person("ccc", 50);
	Person* d = new Person("ddd", 100);

	a1->AddPassenger(a);
	a1->AddPassenger(b);

	b1->AddPassenger(c);
	b1->AddPassenger(d);

	Boatplane* bp = new Boatplane(*a1 + *b1);


	cout << bp->GetPassenger(0)->GetName() << " " << bp->GetPassenger(1)->GetName() << endl;

	delete a1;
	delete b1;
	delete bp;



}

int main()
{
	
	//TestDeleteAirplane();
	//DoSomething();
	TestBoatplane();

	std::cout << "No Assert!" << std::endl;

	return 0;
}