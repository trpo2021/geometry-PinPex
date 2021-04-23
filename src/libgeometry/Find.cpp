#include "libgeometry.h"
#include <cerrno>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int findPoints(string Object, double* Points)
{
    int i = 7;
    int j = i;
    if (Object[i - 1] == ')') {
        printf("Error at column %d : expected '('\n", i - 1);
        system("pause");
		return 101;
        exit(101);
    }
	if (Object[i-1] == ' ') {
        printf("Error at column %d : a few spaces for circle\n", i - 1);
        system("pause");
		return 202;
        exit(202);
    }
    while (Object[j] != ' ') {
        j += 1;
    }
	try{
    Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j] == ',') break;
		if(Object[j] == ' ') break;
    }
	if(Object[j] == ' '){
		printf("Error at column %d: a few spaces for circle\n", i);
        system("pause");
		return 202;
        exit(202);		
	}
    try{
    Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j]==')') break;
		if(Object[j]=='(') break;
		if(Object[j]==',') break;
		if(Object[j]==' ') break;
    }
	if(Object[j]==' ' || Object[j]==','){
		printf("Error at column %d: a few elements for circle\n", j);
        system("pause");
		return 404;
        exit(404);
	}
    try{
    Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    if (Object[j] == '(') {
        printf("Error at column %d : expected ')'\n", j);
        system("pause");
		return 505;
        exit(505);
    }
	i = Object.length()-1;
    if (Object[j] == ')' && (i!=j)) {
		j+=1;
        while (Object[j] == ' ') {
            j += 1;
        }
        printf("Error at column %d: unexpected token\n", j);
        system("pause");
		return 606;
        exit(606);
    }
	return 0;
}



int findvert(string Object, double* Points)
{
    int i, j;
    j = i = 9;
    if (Object[i-1] == ')') {
        printf("Error at column %d : expected '('\n", i - 1);
        system("pause");
		return 101;
        exit(101);
    }
	if (Object[i-1] == ' ') {
        printf("Error at column %d : a few spaces for triangle\n", i - 1);
        system("pause");
		return 202;
        exit(202);
    }
    while (Object[j] != ' ') {
        j += 1;
    }
	try{
    Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j] == ',') break;
		if(Object[j] == ' ') break;
    }
	if(Object[j] == ' '){
		printf("Error at column %d: a few spaces for triangle\n", i);
        system("pause");
		return 202;
        exit(202);		
	}
    try{
    Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    try{
    Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i);
        system("pause");
		return 303;
        exit(303);
	}
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j] == ',') break;
		if(Object[j] == ' ') break;
    }
	if(Object[j] == ' '){
		printf("Error at column %d: a few spaces for circle\n", i);
        system("pause");
		return 202;
        exit(202);		
	}
    try{
    Points[3] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
		return 303;
        exit(303);
	}
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    try{
    Points[4] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
		return 303;
        exit(303);
	}
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
		if(Object[j]==')') break;
		if(Object[j]=='(') break;
		if(Object[j]==',') break;
		if(Object[j]==' ') break;
    }
	if(Object[j]==' ' || Object[j]==','){
		printf("Error at column %d: a few elements for triangle\n", j);
        system("pause");
		return 404;
        exit(404);
	}
    try{
    Points[5] = strtod(Object.substr(i, j - 1).c_str(), NULL);
	}
	catch(const std::out_of_range& e){
		printf("Error at column %d: expected '<double>'\n", i - 1);
        system("pause");
		return 202;
        exit(202);
	}
    if (Object[j] == '(') {
        printf("Error at column %d : expected ')'\n", j);
        system("pause");
		return 505;
        exit(505);
    }
    i = Object.length()-1;
    if (Object[j] == ')' && (i!=j)) {
		j+=1;
        while (Object[j] == ' ') {
            j += 1;
        }
        printf("Error at column %d: unexpected token\n", j);
        system("pause");
		return 505;
        exit(606);
    }
	return 0;
}