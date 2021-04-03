#include "libgeometry.h"
#include <cerrno>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

void findPoints(string Object, double* Points)
{
    int i = 7;
    int j = i;
    if (Object[i - 1] == ')') {
        printf("Error at column %d : expected '('\n", i - 1);
        system("pause");
        exit(0);
    }
    while (Object[j] != ' ') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && ((Object.substr(i, j - 1) != "0")
        || (Object.substr(i, j - 1) != "0.0"))) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ',') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j]==')') break;
		if(Object[j]=='(') break;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);

    if (Object[j] == '(') {
        printf("Error at column %d : expected ')'\n", j);
        system("pause");
        exit(0);
    }

    i = Object.length();
    if (i != j + 1) {
        while (Object[j] == ' ') {
            j += 1;
        }
        printf("Error at column %d: unexpected token\n", j);
        system("pause");
        exit(0);
    }
}



void findvert(string Object, double* Points)
{
    int i, j;
    j = i = 9;
    if (Object[i] == ')') {
        printf("Error at column %d : expected '('\n", i - 1);
        system("pause");
        exit(0);
    }
    while (Object[j] != ' ') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ',') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ',') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[3] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && (Object.substr(i, j - 1) != "0")
        && (Object.substr(i, j - 1) != "0.0")) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[4] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j]==')') break;
		if(Object[j]=='(') break;
    }
    if ((strtod(Object.substr(i, j - 1).c_str(), NULL) == 0)
        && ((Object.substr(i, j - 1) != "0")
        || (Object.substr(i, j - 1) != "0.0"))) {
        printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
        exit(0);
    }
    Points[5] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    if (Object[j] == '(') {
        printf("Error at column %d : expected ')'\n", j);
        system("pause");
        exit(0);
    }
    i = Object.length();
    if (i != j + 1) {
        while (Object[j] == ' ') {
            j += 1;
        }
        printf("Error at column %d: unexpected token\n", j);
        system("pause");
        exit(0);
    }
}