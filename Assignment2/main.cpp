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
	Boatplane* a1 = new Boatplane(2);

	cout << a1->GetFlySpeed() << " " << a1->GetSailSpeed() << endl;

	std::cout << "No Assert!" << std::endl;

	return 0;
}