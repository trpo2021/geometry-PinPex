#include "libgeometry.h"
#include <iostream>
#include <string.h>
using namespace std;

void output(cir* circles, tri* tr, int n)
{
    int i, j;
    for (i = 0; i < n; ++i) {
        if (circles[i].Ob == " ")
            continue;
        cout << circles[i].Ob << endl;
        cout << "Point 1 = " << circles[i].p1 << endl;
        cout << "Point 2 = " << circles[i].p2 << endl;
        cout << "Perimeter = " << circles[i].per << endl;
        cout << "Area = " << circles[i].ar << endl;
        cout << "intersections:" << endl;
        for (j = 0; j < n; ++j) {
            if (circles[i].intersec[j] == 1) {
                cout << j + 1 << "." << circles[i].inter[j] << endl;
            }
        }
    }
    for (i = 0; i < n; ++i) {
        if (tr[i].Ob == " " || (tr[i].ar == 0 && tr[i].ar == 0))
            continue;
        cout << tr[i].Ob << endl;
        for (j = 0; j < 6; ++j)
            printf("Point[%d] = %f\n", j + 1, tr[i].ps[j]);
        printf("Perimeter = %f\n", tr[i].per);
        printf("Area = %f\n", tr[i].ar);
        cout << "intersections:" << endl;
        for (j = 0; j < n; ++j) {
            if (tr[i].intersec[j] == 1) {
                cout << j + 1 << "." << tr[i].inter[j] << endl;
            }
        }
    }
}