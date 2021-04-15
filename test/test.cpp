#include <ctest.h>
#include <cmath>
#include <iostream>
#include <libgeometry/libgeometry.h>
#include <string>

CTEST(Find_points, find)
{
    string str("circle(84621856.234841231 84621856.234841231, 84621856.234841231)");

    double Points[3];

    findPoints(str, Points);

    const double Point1[3] = {84621856.234841231, 84621856.234841231, 84621856.234841231};

    double temp1, temp2;
    temp1 = Point1[0];
    temp2 = Points[0];
    ASSERT_DBL_NEAR(temp1, temp2);
    temp1 = Point1[1];
    temp2 = Points[1];
    ASSERT_DBL_NEAR(temp1, temp2);
    temp1 = Point1[2];
    temp2 = Points[2];
    ASSERT_DBL_NEAR(temp1, temp2);
    system("pause");
}
CTEST(intersections, intersection)
{
    cir circles[2];

    circles[0].Ob = "1";
    circles[0].p1 = 1;
    circles[0].p2 = 1;
    circles[0].r = 1;

    circles[1].Ob = "1";
    circles[1].p1 = 1 + sqrt(2)/2;
    circles[1].p2 = 1 + sqrt(2)/2;
    circles[1].r = 1;

    const int n = 2;

    circles[0].intersec = new int[n];
    circles[1].intersec = new int[n];
    circles[0].inter = new string[n];
    circles[1].inter = new string[n];

    checkCircCirc(circles, n);

    int temp1 = circles[0].intersec[1], temp2 = circles[1].intersec[0];

    ASSERT_EQUAL(temp1, temp2);
	delete[] circles[0].intersec;
	delete[] circles[0].inter;
	delete[] circles[1].intersec;
	delete[] circles[1].inter;
    system("pause");
}
CTEST(intersection_and_find, intersection)
{
    cir circles[2];
    string str1("circle(1 1, 1)");
    string str2("circle(1.707106781186547524400844362105 1.707106781186547524400844362105, 1)");
    double Points[3];

    findPoints(str1, Points);
    circles[0].Ob = str1;
    circles[0].p1 = Points[0];
    circles[0].p2 = Points[1];
    circles[0].r = Points[2];

    findPoints(str2, Points);
    circles[1].Ob = str2;
    circles[1].p1 = Points[0];
    circles[1].p2 = Points[1];
    circles[1].r = Points[2];

    const int n = 2;
    circles[0].intersec = new int[n];
    circles[1].intersec = new int[n];
    circles[0].inter = new string[n];
    circles[1].inter = new string[n];

    checkCircCirc(circles, n);

    int temp1 = circles[0].intersec[1], temp2 = circles[1].intersec[0];

    ASSERT_EQUAL(temp1, temp2);
	delete[] circles[0].intersec;
	delete[] circles[0].inter;
	delete[] circles[1].intersec;
	delete[] circles[1].inter;
    system("pause");
}
CTEST(Calculating_circle, area_and_perimeter)
{
    const double Number = 1389.10256;
	ASSERT_DBL_NEAR(calcParam(Number), 8727.98879516);
	ASSERT_DBL_NEAR(calcArea(Number), 6062035.7895);
    system("pause");
}