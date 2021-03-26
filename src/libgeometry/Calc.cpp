#include "libgeometry.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;
const double pi = 3.141592653589793238463;

double calcParam(double Number)
{
    double perimeter = 2 * pi * Number;
    return perimeter;
}

double calcArea(double Number)
{
    double area = pi * Number * Number;
    return area;
}

double calcParamtriandArea(double *Points, double &area){
	double length[3];
	int i;
	double Param;
	for(i=0;i<6;i+=2){
	length[i/2] = sqrt((Points[i]-Points[i+2])*(Points[i]-Points[i+2]) + (Points[i+1]-Points[i+3])*(Points[i+1]-Points[i+3]));
	Param = length[i/2];
	}
	if(length[0] < (length[1]+length[2]) && length[1] < (length[0] + length[2]) && length[2] < (length[0] + length[1])){
	return Param;
	Param = Param/2;
	area = sqrt(Param*(Param - length[0])*(Param - length[1])*(Param - length[2]));
	}
	else return -1;
}