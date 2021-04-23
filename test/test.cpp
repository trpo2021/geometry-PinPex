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
CTEST(Find_points, checking_for_correctness){
	double Points[6];
	string circle1("circle( 1 1, 1)");
	string circle2("circle)1 1, 1)");
	string circle3("circle(1 1, 1 1, 1)");
	string circle4("circle(1 1, 1) 2124124");
	string circle5("circle(x x, 1)");
	string circle6("circle(1 1, 1(");
	if(findPoints(circle1,Points) == 202) ASSERT_TRUE(1);
	if(findPoints(circle2,Points) == 101) ASSERT_TRUE(1);
	if(findPoints(circle3,Points) == 404) ASSERT_TRUE(1);
	if(findPoints(circle4,Points) == 606) ASSERT_TRUE(1);
	if(findPoints(circle4,Points) == 505) ASSERT_TRUE(1);
}
CTEST(correctly_input, title)
{
	string str1circle("circle(1 1, 1)");
	string str2circle("crrcle(1 1, 1)");
	string str3circle("cir(1 1, 1)");
	string str4circle("rcle(1 1, 1)");
	string str5circle("cirrle(1 1, 1)");
	if(ind(str1circle)==1) ASSERT_TRUE(1);
	if(ind(str2circle)==0) ASSERT_TRUE(1);
	if(ind(str3circle)==0) ASSERT_TRUE(1);
	if(ind(str4circle)==0) ASSERT_TRUE(1);
	if(ind(str5circle)==0) ASSERT_TRUE(1);
	string str1triangle("triangle(1 1, 1 1, 1 1)");
	string str2triangle("trrangle(1 1, 1 1, 1 1)");
	string str3triangle("trrrngle(1 1, 1 1, 1 1)");
	string str4triangle("iangle(1 1, 1 1, 1 1)");
	string str5triangle("trian(1 1, 1 1, 1 1)");
	if(ind(str1triangle)==2) ASSERT_TRUE(1);
	if(ind(str2triangle)==0) ASSERT_TRUE(1);
	if(ind(str3triangle)==0) ASSERT_TRUE(1);
	if(ind(str4triangle)==0) ASSERT_TRUE(1);
	if(ind(str5triangle)==0) ASSERT_TRUE(1);
    system("pause");
}
CTEST(intersections, circles_without_find)
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
CTEST(intersection, circles_with_find)
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
CTEST(intersections, triangles_and_circles)
{
	string circle = "circle(1 1, 1)";
	string triangle = "triangle(6.82842712475 0, 0 6.82842712475, 6.82842712475 6.82842712475)";
	int i, j;
	const int n = 2;
    double Points[6];
    double perimeter, area;
    bool HaveCir = 0;
    bool HaveTri = 0;

    cir* circles = new cir[n];
    tri* tr = new tri[n];

    for (i = 0; i < n; ++i) {
        tr[i].intersec = new int[n];
        tr[i].inter = new string[n];
        circles[i].intersec = new int[n];
        circles[i].inter = new string[n];
    }
    string Object;

    for (i = 0; i < n; i++) {
		if(i==0)
        Object = circle;
		if(i==1)
		Object = triangle;
        switch (ind(Object)) {
        case (1): {
            HaveCir = 1;
            tr[i].Ob = " ";
            circles[i].Ob = Object;
            findPoints(Object, Points);
            perimeter = calcParam(Points[2]);
            area = calcArea(Points[2]);
            circles[i].p1 = Points[0];
            circles[i].p2 = Points[1];
            circles[i].r = Points[2];
            circles[i].per = perimeter;
            circles[i].ar = area;
            break;
        }
        case (2): {
            HaveTri = 1;
            circles[i].Ob = " ";
            findvert(Object, Points);
            tr[i].Ob = Object;
            perimeter = calcParamtriandArea(Points, &area);
            if (perimeter == -1) {
                cout << "This triangle not exists" << endl;
                tr[i].ar = 0;
                tr[i].per = 0;
                break;
            }
            for (j = 0; j < 6; ++j)
                tr[i].ps[j] = Points[j];
            tr[i].ar = area;
            tr[i].per = perimeter;

            break;
        }
        }
    }
    if (HaveCir == 1)
        checkCircCirc(circles, n);
    if (HaveTri == 1)
        checkCircTri(circles, tr, n);
	int temp1 = tr[1].intersec[0], temp2 = circles[0].intersec[1];
	ASSERT_EQUAL(temp1, temp2);
	delete[] circles;
	delete[] tr;
    system("pause");
}
CTEST(Calculating_circle, area_and_perimeter)
{
    const double Number = 1389.10256;
	ASSERT_DBL_NEAR(calcParam(Number), 8727.98879516);
	ASSERT_DBL_NEAR(calcArea(Number), 6062035.7895);
    system("pause");
}