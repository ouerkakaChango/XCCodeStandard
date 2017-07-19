#include <iostream>
#include "Car.h"
#include "Chassis.h"
using namespace std;

#define SAMPLE_RATE 16000  
#define STR1(R)  #R  
#define STR2(R)  STR1(R)  



int main()
{
	int id = 16000;
	XC.Init();
	Car obj; Chassis o2;
	obj.Init();
	cout << obj.className;
	cout << "\n";
	
	//obj->operator->()(1, 2, 3);
	system("pause");
    return 0;
}

