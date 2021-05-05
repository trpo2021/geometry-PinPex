#include "libgeometry.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

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

double calcParamtriandArea(double* Points, double* area)
{
    double length[3];
    int i;
    double Param;
    for (i = 0; i < 6; i += 2) {
        if (i == 4) {
            length[i / 2]
                    = sqrt((Points[0] - Points[4]) * (Points[0] - Points[4])
                           + (Points[1] - Points[5]) * (Points[1] - Points[5]));
        } else
            length[i / 2] = sqrt(
                    (Points[i + 2] - Points[i]) * (Points[i + 2] - Points[i])
                    + (Points[i + 3] - Points[i + 1])
                            * (Points[i + 3] - Points[i + 1]));
    }
    for (i = 0; i < 3; ++i)
        Param += length[i];
    if (length[0] < (length[1] + length[2])
        && length[1] < (length[0] + length[2])
        && length[2] < (length[0] + length[1])) {
        *area
                = sqrt((Param / 2) * (Param / 2 - length[0])
                       * (Param / 2 - length[1]) * (Param / 2 - length[2]));
        return Param;
    } else
        return -1;
}