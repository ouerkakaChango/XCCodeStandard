#include "Car.h"

bool Car::Init() {
	XCCONNECTION1(Car, Chassis)
		XCALERT("Car init,connection done", "");
		return true;
}
