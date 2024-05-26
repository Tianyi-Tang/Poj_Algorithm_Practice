#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define Pi 3.14159


int main()
{
	int radius, gallons, degrees;
	double distance;
	string operation;
	while(cin >> operation){
		if(operation == "ENDOFINPUT")
			break;

		cin >> radius;
		cin >> gallons;
		cin >> degrees;
		cin >> operation;

		if(degrees > 180)
			degrees = 360 - degrees;
		distance = 4 * Pi * radius * (double) (degrees / 360.0);

		if(distance <= gallons * 5){
			gallons = gallons - (distance / 5.0);
			cout << "YES " << gallons << endl; 
		}
		else{
			cout << "NO " << gallons * 5 << endl;
		}

		
	}

	return 0;
}