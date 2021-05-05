#include "libgeometry.h"
#include <iostream>
#include <string.h>
using namespace std;
string strtolower(string a)
{
    for (int i = 0; i < 8; ++i)
        a[i] = tolower(a[i]);
    return a;
}
int ind(string Object)
{
    string Object1 = "circle";
    string Object2 = "triangle";
    string Object3 = "polygon";
    Object = strtolower(Object.substr(0, Object.find('(')));
    if (strcmp(Object1.c_str(), Object.c_str()) == 0) {
        return 1;
    }
    if (strcmp(Object2.c_str(), Object.c_str()) == 0) {
        return 2;
    }
    if (strcmp(Object3.c_str(), Object.c_str()) == 0) {
        return 3;
    }
    return 0;
}