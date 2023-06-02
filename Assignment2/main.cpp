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

int main()
{
	Person* p = new Person("Bob", 70);

	Person* p2 = new Person("James", 61);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 3319);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Boat* b1 = new Boat(5);
	Boat* b2 = new Boat(7);

	b1->AddPassenger(p);
	b1->AddPassenger(p2);

	b2->AddPassenger(p3);
	b2->AddPassenger(p4);
	b2->AddPassenger(p5);

	Boat* b3 = new Boat(*b1);

	cout << b1->GetPassenger(0)->GetName() << " " << b1->GetPassenger(1)->GetName() << endl;

	delete b2;
	delete b1;
	
	cout << b3->GetPassenger(0)->GetName() << " " << b3->GetPassenger(1)->GetName() << endl;

	std::cout << "No Assert!" << std::endl;

	return 0;
}