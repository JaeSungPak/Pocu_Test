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

#include <cassert>


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	
	Airplane* airplane = new Airplane(0);
	Boat* boat = new Boat(0);
	DeusExMachina* deusExMachina = DeusExMachina::GetInstance();
	deusExMachina->AddVehicle(airplane);
	deusExMachina->AddVehicle(boat);
	deusExMachina->Travel();
	assert(deusExMachina->GetFurthestTravelled() == airplane);
	

}