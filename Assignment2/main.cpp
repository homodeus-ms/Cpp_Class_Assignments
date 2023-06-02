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
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 45);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 3319);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	UBoat* u1 = new UBoat();

	u1->AddPassenger(p);
	u1->AddPassenger(p2);
	u1->AddPassenger(p3);
	u1->AddPassenger(p4);
	
	//ap1 182키로 , 그 다음은 + 3500 - 182 = 3318
	cout << u1->GetSailSpeed() << " " << u1->GetDiveSpeed() << endl;

	std::cout << "No Assert!" << std::endl;

	return 0;
}