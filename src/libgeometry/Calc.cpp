#include <iostream>
#include "libgeometry.h"
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

double calcParam(double Number){
	double perimeter = 2 * pi * Number;
	return perimeter;
}

double calcArea(double Number){
	double area = pi * Number * Number;
	return area;
}