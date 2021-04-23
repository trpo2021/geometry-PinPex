#ifndef IND_GEOMETRY
#define IND_GEOMETRY

#include <iostream>
#include <string.h>

using namespace std;

const double pi = 3.141592653589793238463;

struct cir {
    string Ob;
    double p1;
    double p2;
    double r;
    double per;
    double ar;
    int* intersec;
    string* inter;
};

struct tri {
    string Ob;
    double ps[6];
    double per;
    double ar;
    int* intersec;
    string* inter;
};

string strtolower(string a);
int ind(string Object);

int input();
void output(cir* circles, tri* tr, int n);

void checkCircTri(cir* circles, tri* tr, int n);
void checkCircCirc(cir* circles, int n);

double calcArea(double Number);
double calcParam(double Number);
double calcParamtriandArea(double* Points, double* area);

int findPoints(string Object, double* Points);
int findvert(string Object, double* Points);

#endif