#include <iostream>
#include <libgeometry/Calc.h>
#include <libgeometry/Find.h>
#include <libgeometry/libgeometry.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;

int main()
{
    string Object;
    double Points[3];
    double perimeter, area;
    getline(cin, Object);
    cout << Object << endl;

    switch (ind(Object)) {
    case (1): {
        findPoints(Object, Points);
        perimeter = calcParam(Points[2]);
        area = calcArea(Points[2]);
        cout << "Point 1 = " << Points[0] << endl;
        cout << "Point 2 = " << Points[1] << endl;
        cout << "Perimeter = " << perimeter << endl;
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