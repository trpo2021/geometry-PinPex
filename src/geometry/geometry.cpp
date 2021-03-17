#include <iostream>
#include <libgeometry/libgeometry.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

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
        Point1 = atof(Object.substr(i, j).c_str());
        cout << "Point 1 = " << Point1 << endl;
        i = j + 1;
        while (Object[i] == ' ')
            i += 1;
        j = i;
        while (Object[j] != ',')
            j += 1;
        j -= 1;
        Point2 = atof(Object.substr(i, j).c_str());
        j += 2;
        i = j;
        while (Object[i] == ' ')
            i += 1;
        j = i;
        while (Object[j] != ')')
            j += 1;
        Number = atof(Object.substr(i, j).c_str());
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
    case (0): {
        cout << "Error" << endl;
        break;
    }
    }
    system("pause");
    return 0;
}
