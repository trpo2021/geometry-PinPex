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

void ERROR_OUTPUT(int ERROR_NUMBER, int COLUMN_ERROR)
{
    cout << "Error at column " << COLUMN_ERROR << ": ";
    switch (ERROR_NUMBER) {
    case 101: {
        cout << "this triangle not existes" << endl;
        break;
    }
    case 202: {
        cout << "expected 'circle' or 'triangle'" << endl;
        break;
    }
    case 303: {
        cout << "expected '('" << endl;
        break;
    }
    case 4041: {
        cout << "a few spaces for circle" << endl;
        break;
    }
    case 4042: {
        cout << "a few spaces for triangle" << endl;
        break;
    }
    case 505: {
        cout << "expected '<double>'" << endl;
        break;
    }
    case 6061: {
        cout << "a few elements for circle" << endl;
        break;
    }
    case 6062: {
        cout << "a few elements for triangle" << endl;
        break;
    }
    case 707: {
        cout << "expected ')'" << endl;
        break;
    }
    case 808: {
        cout << "unexpected token" << endl;
        break;
    }
    }
}