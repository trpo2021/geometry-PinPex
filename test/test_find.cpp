#include <ctest.h>
#include <iostream>
#include <libgeometry/libgeometry.h>
#include <string>

CTEST(Find_points, find)
{
    string str("circle(1.002 1.002, 1.002)");

    double Points[3];

    findPoints(str, Points);

    const double Point1[3] = {1.002, 1.002, 1.002};

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
CTEST(Find_points, to_check)
{
    ASSERT_TRUE(1);
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
    circles[1].p1 = 1.70711;
    circles[1].p2 = 1.70711;
    circles[1].r = 1;

    const int n = 2;

    circles[0].intersec = new int[n];
    circles[1].intersec = new int[n];
    circles[0].inter = new string[n];
    circles[1].inter = new string[n];

    checkCircCirc(circles, n);

    int temp1 = circles[0].intersec[1], temp2 = circles[1].intersec[0];

    ASSERT_EQUAL(temp1, temp2);

    system("pause");
}

CTEST(intersections, to_check)
{
    ASSERT_TRUE(1);
    system("pause");
}

CTEST(intersection_and_find, intersection)
{
    cir circles[2];
    string str1("circle(1 1, 1)");
    string str2("circle(1.70711 1.70711, 1)");
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

    system("pause");
}
CTEST(intersection_and_find, to_check)
{
    ASSERT_TRUE(1);
    system("pause");
}