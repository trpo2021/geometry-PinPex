#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

string strtolower(string a)
{
    for (int i = 0; i < 8; ++i)
        a[i] = tolower(a[i]);
    return a;
}

int ind(string Object)
{
    string Object1 = "cyrcle";
    string Object2 = "triangle";
    string Object3 = "polygon";
    Object = strtolower(Object);
    if (strcmp(Object1.c_str(), Object.c_str()) == 0)
        return 1;
    if (strcmp(Object2.c_str(), Object.c_str()) == 0)
        return 2;
    if (strcmp(Object3.c_str(), Object.c_str()) == 0)
        return 3;
}
int main()
{
    string Object;
    double Point1, Point2, Number;
    double perimeter, area;
    int i, j;
    getline(cin, Object);
    cout << Object << endl;
    switch (ind(Object)) {
    case (1): {
        i = 7;
        j = i;
        while (Object[j] != ' ')
            j += 1;
        j -= 1;
        Point1 = atoi(Object.substr(i, j).c_str());
        cout << "Point 1 = " << Point1 << endl;
        i = j + 1;
        while (Object[i] == ' ')
            i += 1;
        j = i;
        while (Object[j] != ',')
            j += 1;
        j -= 1;
        Point2 = atoi(Object.substr(i, j).c_str());
        j += 2;
        i = j;
        while (Object[i] == ' ')
            i += 1;
        j = i;
        while (Object[j] != ')')
            j += 1;
        Number = atoi(Object.substr(i, j).c_str());
        cout << "Point 2 = " << Point2 << endl;
        perimeter = 2 * pi * Number;
        cout << "Perimeter = " << perimeter << endl;
        area = pi * Number * Number;
        cout << "Area = " << area << endl;
        break;
    }
    case (2):
        cout << "triangle" << endl;
        break;
    case (3):
        cout << "polygon" << endl;
        break;
    }
    return 0;
}
