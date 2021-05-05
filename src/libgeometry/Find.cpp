#include "libgeometry.h"
#include <cerrno>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int findPoints(string Object, double* Points, int& COLUMN)
{
    int i = 7;
    int j = i;
    if (Object[i - 1] == ')') {
        COLUMN = i - 1;
        return 303;
    }
    if (Object[i - 1] == ' ') {
        COLUMN = i - 1;
        return 4041;
    }
    while (Object[j] != ' ') {
        j += 1;
    }
    try {
        Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
        if (Object[j] == ',')
            break;
        if (Object[j] == ' ')
            break;
    }
    if (Object[j] == ' ') {
        COLUMN = i;
        return 4041;
    }
    try {
        Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
        if (Object[j] == ')')
            break;
        if (Object[j] == '(')
            break;
        if (Object[j] == ',')
            break;
        if (Object[j] == ' ')
            break;
    }
    if (Object[j] == ' ' || Object[j] == ',') {
        COLUMN = j;
        return 6061;
    }
    try {
        Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    if (Object[j] == '(') {
        COLUMN = j;
        return 707;
    }
    i = Object.length() - 1;
    if (Object[j] == ')' && (i != j)) {
        j += 1;
        while (Object[j] == ' ') {
            j += 1;
        }
        COLUMN = j;
        return 808;
    }
    return 0;
}

int findvert(string Object, double* Points, int& COLUMN)
{
    int i, j;
    j = i = 9;
    if (Object[i - 1] == ')') {
        COLUMN = i - 1;
        return 303;
    }
    if (Object[i - 1] == ' ') {
        COLUMN = i - 1;
        return 4042;
    }
    while (Object[j] != ' ') {
        j += 1;
    }
    try {
        Points[0] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
        if (Object[j] == ',')
            break;
        if (Object[j] == ' ')
            break;
    }
    if (Object[j] == ' ') {
        COLUMN = i;
        return 4042;
    }
    try {
        Points[1] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    try {
        Points[2] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i;
        return 505;
    }
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
        if (Object[j] == ',')
            break;
        if (Object[j] == ' ')
            break;
    }
    if (Object[j] == ' ') {
        COLUMN = i;
        return 4042;
    }
    try {
        Points[3] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i - 1;
        return 505;
    }
    j += 1;
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (Object[j] != ' ') {
        j += 1;
    }
    try {
        Points[4] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i - 1;
        return 505;
    }
    while (Object[j] == ' ') {
        j += 1;
    }
    i = j;
    while (1) {
        j += 1;
        if (Object[j] == ')')
            break;
        if (Object[j] == '(')
            break;
        if (Object[j] == ',')
            break;
        if (Object[j] == ' ')
            break;
    }
    if (Object[j] == ' ' || Object[j] == ',') {
        COLUMN = j;
        return 6062;
    }
    try {
        Points[5] = strtod(Object.substr(i, j - 1).c_str(), NULL);
    } catch (const std::out_of_range& e) {
        COLUMN = i - 1;
        return 4042;
    }
    if (Object[j] == '(') {
        COLUMN = j;
        return 707;
    }
    i = Object.length() - 1;
    if (Object[j] == ')' && (i != j)) {
        j += 1;
        while (Object[j] == ' ') {
            j += 1;
        }
        COLUMN = j;
        return 808;
    }
    return 0;
}