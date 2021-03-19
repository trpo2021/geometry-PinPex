#include "libgeometry.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

void findPoints(string Object, double* Points)
{
    int i = 7;
    int j = i;
    while (Object[j] != ' ')
        j += 1;
    j -= 1;
    Points[0] = atof(Object.substr(i, j).c_str());
    i = j + 1;
    while (Object[i] == ' ')
        i += 1;
    j = i;
    while (Object[j] != ',')
        j += 1;
    j -= 1;
    Points[1] = atof(Object.substr(i, j).c_str());
    j += 2;
    i = j;
    while (Object[i] == ' ')
        i += 1;
    j = i;
    while (Object[j] != ')')
        j += 1;
    Points[2] = atof(Object.substr(i, j).c_str());
}