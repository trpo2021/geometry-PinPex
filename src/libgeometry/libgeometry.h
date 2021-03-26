#ifndef IND_GEOMETRY
#define IND_GEOMETRY

#pragma once
#include <iostream>
#include <string.h>

using namespace std;

struct cir {
    string Ob;
    double p1;
    double p2;
    double r;
    double per;
    double ar;
};

struct tri {
    string Ob;
    double points[6];
};

string strtolower(string a);
int ind(string Object);

#endif