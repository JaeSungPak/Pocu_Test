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

int main()
{
	Sedan* demSedan1 = new Sedan();
	Sedan* demSedan2 = new Sedan();
	Trailer* demTrailer1 = new Trailer(10);
	Trailer* demTrailer2 = new Trailer(5);
	demSedan1->AddTrailer(demTrailer1);
	demSedan2->AddTrailer(demTrailer2);

	*demSedan1 = *demSedan2;

	//assert(demTrailer1 == nullptr);

	std::cout << demTrailer1->GetWeight();

	return 0;
}