#include <iostream>
#include <libgeometry/libgeometry.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

int main()
{
    int n, i, j;
    double Points[6];
    double perimeter, area;
    bool HaveCir = 0;
    bool HaveTri = 0;

    printf("How many objects you wish input?\n");
    n = input();
    printf("Input your objects\n");

    cir* circles = new cir[n];
    tri* tr = new tri[n];

    for (i = 0; i < n; ++i) {
        tr[i].intersec = new int[n];
        tr[i].inter = new string[n];
        circles[i].intersec = new int[n];
        circles[i].inter = new string[n];
    }
    string Object;

    for (i = 0; i < n; i++) {
        getline(cin, Object);
        switch (ind(Object)) {
        case (1): {
            HaveCir = 1;
            tr[i].Ob = " ";
            circles[i].Ob = Object;
            findPoints(Object, Points);
            perimeter = calcParam(Points[2]);
            area = calcArea(Points[2]);
            circles[i].p1 = Points[0];
            circles[i].p2 = Points[1];
            circles[i].r = Points[2];
            circles[i].per = perimeter;
            circles[i].ar = area;
            break;
        }
        case (2): {
            HaveTri = 1;
            circles[i].Ob = " ";
            findvert(Object, Points);
            tr[i].Ob = Object;
            perimeter = calcParamtriandArea(Points, &area);
            if (perimeter == -1) {
                cout << "This triangle not exists" << endl;
                tr[i].ar = 0;
                tr[i].per = 0;
                break;
            }
            for (j = 0; j < 6; ++j)
                tr[i].ps[j] = Points[j];
            tr[i].ar = area;
            tr[i].per = perimeter;

            break;
        }
        case (0): {
            cout << "Error at column 0: expected 'circle', 'triangle' or "
                    "'polygon'"
                 << endl;
            break;
        }
        }
    }

    if (HaveCir == 1)
        checkCircCirc(circles, n);
    if (HaveTri == 1)
        checkCircTri(circles, tr, n);
    output(circles, tr, n);
    system("pause");
    delete[] tr;
    delete[] circles;
    return 0;
}