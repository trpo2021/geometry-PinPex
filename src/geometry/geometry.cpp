#include <conio.h>
#include <iostream>
#include <libgeometry/Calc.h>
#include <libgeometry/Find.h>
#include <libgeometry/Input.h>
#include <libgeometry/libgeometry.h>
#include <libgeometry/output.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const double pi = 3.141592653589793238463;



int main()
{
    int n, i, j;
    double Points[6];
    double perimeter, area;

	printf("How many objects you wish input?\n");
    n = input();
    printf("Input your objects\n");
	
	int** check = new int*[n];
    cir* circles = new cir[n];
	tri* tr = new tri[n];
    string Object;

    
    for (i = 0; i < n; i++) {
        getline(cin, Object);
        circles[i].Ob = Object;
        switch (ind(Object)) {
        case (1): {
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
        case (2):{
			findvert(Object, Points);
			tr[i].Ob = Object;
			perimeter = calcParamtriandArea(Points,area);
			if(perimeter == -1) cout << "This triangle not exists" << endl;
			tr[i].ar = 0;
			tr[i].per = 0;
			break;
			for(j=0;j<6;++j) tr[i].ps[j] = Points[j];
			tr[i].ar = area;
			tr[i].per = perimeter;
			
            break;
		}
        case (0): {
            cout << "Error" << endl;
            break;
        }
        }
    }

    for (i = 0; i < n; ++i) {
        cout << "Point 1 = " << circles[i].p1 << endl;
        cout << "Point 2 = " << circles[i].p2 << endl;
        cout << "Perimeter = " << circles[i].per << endl;
        cout << "Area = " << circles[i].ar << endl;
    }
	for (i = 0; i < n; ++i) {
		if(tr[i].per == 0 && tr[i].ar == 0) continue;
        for(j=0;j<n;++j) printf("Point[%d] = %f",j + 1, tr[i].ps[j]);
		printf("Perimeter[%d] = %f",i + 1, tr[i].per);
		printf("Area[%d] = %f",i + 1, tr[i].ar);
    }
	
    for (i = 0; i < n; ++i) {
        cout << check[i][0] << endl;
    }
    system("pause");
    return 0;
}