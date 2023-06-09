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
void TestSedan()
{
	Person* a = new Person("aaa", 50);
	Person* b = new Person("bbb", 100);
	Person* c = new Person("ccc", 150);

	Sedan* s1 = new Sedan();
	Sedan* s2 = new Sedan();
	Trailer* t1 = new Trailer(500);
	Trailer* t2 = new Trailer(300);

	s1->AddTrailer(t1);
	s1->AddPassenger(a);
	s1->AddPassenger(b);

	s2->AddPassenger(c);
	
	//s2->AddTrailer(t2);

	*s1 = *s2;

	

	delete s2;
	delete s1;

	cout << "???" << endl;

}
void TestMachina()
{
	Person* a = new Person("aaa", 1);
	Person* b = new Person("bbb", 2);


}

int main()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

#if 1
	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	assert(!bRemoved);

	deusExMachina1->Travel(); // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	assert(deusExMachina1->GetFurthestTravelled() == boat);
#endif
	std::cout << "No Assert!" << std::endl;

	return 0;
}