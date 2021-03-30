#include "libgeometry.h"
#include <iostream>
#include <math.h>

void checkCircCirc(cir* circles, int n)
{
    double Length;
    int i, j;
    for (i = 0; i < n; ++i) {
        if (circles[i].Ob == " ")
            continue;
        for (j = 0; j < n; ++j) {
            if (circles[j].Ob == " ")
                continue;
            if (j == i)
                continue;
            Length
                    = sqrt((circles[i].p1 - circles[j].p1)
                                   * (circles[i].p1 - circles[j].p1)
                           + (circles[i].p2 - circles[j].p2)
                                   * (circles[i].p2 - circles[j].p2));
            cout << Length << endl;
            if ((Length - circles[i].r - circles[j].r) <= 0) {
                circles[i].intersec[j] = 1;
                circles[j].intersec[i] = 1;
                circles[i].inter[j] = "circle";
                circles[j].inter[i] = "circle";
            } else {
                circles[i].intersec[j] = 0;
                circles[j].intersec[i] = 0;
            }
        }
    }
}

void checkCircTri(cir* circles, tri* tr, int n)
{
    double X, Y, R, X1, Y1, D;
    for (int i = 0; i < n; ++i) {
        if (tr[i].Ob == " " || (tr[i].ar == 0 && tr[i].ar == 0))
            continue;
        for (int j = 0; j < n; ++j) {
            if (j == i)
                continue;
            if (circles[j].Ob == " ")
                continue;
            R = circles[j].r;
            for (int g = 0; g <= 4; g += 2) {
                if (g == 4) {
                    X1 = tr[i].ps[4] - circles[j].p1;
                    Y1 = tr[i].ps[5] - circles[j].p2;
                    X = tr[i].ps[0] - tr[i].ps[4];
                    Y = tr[i].ps[1] - tr[i].ps[5];
                    D = 16 * (X1 * X + Y1 * Y) * (X1 * X + Y1 * Y)
                            - 4 * (X * X + Y * Y) * (X1 * X1 + Y1 * Y1 - R * R);
                    if (D >= 0) {
                        circles[j].intersec[i] = 1;
                        tr[i].intersec[j] = 1;
                        circles[j].inter[i] = "triangle";
                        tr[i].inter[j] = "circle";
                    } else {
                        circles[j].intersec[i] = 0;
                        tr[i].intersec[j] = 0;
                    }
                } else {
                    X1 = tr[i].ps[g] - circles[j].p1;
                    Y1 = tr[i].ps[g + 1] - circles[j].p2;
                    X = tr[i].ps[g + 2] - tr[i].ps[g];
                    Y = tr[i].ps[g + 3] - tr[i].ps[g + 1];
                    D = 16 * (X1 * X + Y1 * Y) * (X1 * X + Y1 * Y)
                            - 4 * (X * X + Y * Y) * (X1 * X1 + Y1 * Y1 - R * R);
                    if (D >= 0) {
                        circles[j].intersec[i] = 1;
                        tr[i].intersec[j] = 1;
                        circles[j].inter[i] = "triangle";
                        tr[i].inter[j] = "circle";
                    } else {
                        circles[j].intersec[i] = 0;
                        tr[i].intersec[j] = 0;
                    }
                }
            }
        }
    }
}