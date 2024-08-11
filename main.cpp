#include <iostream>
#include "LegOfLegends.h"
using namespace std;
int main() {
	Leg dogLeg(57, 110);
	dogLeg.setRestPositions(90, -60);
	sint j1, j2, j3;
	tie(j1, j2, j3) = dogLeg.calculatePos(0, 40, 0);
	cout << "J1: " << j1 << endl;
	cout << "J2: " << j2 << endl;
	cout << "J3: " << j3 << endl;

	return 0;
}