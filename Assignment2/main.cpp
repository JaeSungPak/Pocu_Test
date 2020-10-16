#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	Sedan* demSedan1 = new Sedan();
	Sedan* demSedan2 = new Sedan();
	Trailer* demTrailer = new Trailer(10);
	(demSedan1)->AddTrailer(demTrailer);

	*demSedan1 = *demSedan2;

	return 0;
}