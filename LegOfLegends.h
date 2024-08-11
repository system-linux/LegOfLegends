#pragma once
#include <math.h>
#include <tuple>
using namespace std;
typedef short int sint;
#define PI 3.14159265359

class Leg {
public:
	Leg (sint j2l, sint j3l) {
		this->j2l = j2l; this->j3l = j3l;
	}
	void setRestPositions(sint Y, sint Z) {
		this->restY = Y;
		this->restZ = Z;
	}
	tuple<double, double, double> calculateAngle(sint X, sint Y, sint Z) {
		Y += restY;;
		Z += restZ;
		double J1 = atan(X / Y) * (180 / PI);
		double H = sqrt((Y * Y) + (X * X));
		double L = sqrt((H * H) + (Z * Z));
		double J3 = acos(((j2l * j2l) + (j3l * j3l) - (L * L)) / (2 * j2l * j3l)) * (180 / PI);
		double B = acos(((L * L) + (j2l * j2l) - (j3l * j3l)) / (2 * L * j2l)) * (180 / PI);
		double A = atan(Z / H) * (180 / PI);
		double J2 = (B + A);
		return make_tuple(J1, J2, J3);
	}
	
private:
	sint j2l, j3l;
	sint restY = 0, restZ = 0;
};
