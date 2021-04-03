#include <ctest.h>
#include <libgeometry/libgeometry.h>
#include <iostream>
#include <string>

CTEST(str_suite, find)
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
CTEST(to_check_done, end)
{
    ASSERT_TRUE(1);
    system("pause");
}
