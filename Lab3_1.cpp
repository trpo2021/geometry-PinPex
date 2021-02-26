#include <iostream>
#include <string>
using namespace std;
const double pi = 3.141592653589793238463;
int ind(string Object) {
	int i = 0;
	if (Object[i] == 'c' || Object[i] == 'C') {
		i += 1;
		if (Object[i] == 'i' || Object[i] == 'I') {
			i += 1;
			if (Object[i] == 'r' || Object[i] == 'R') {
				i += 1;
				if (Object[i] == 'c' || Object[i] == 'C') {
					i += 1;
					if (Object[i] == 'l' || Object[i] == 'L') {
						i += 1;
						if (Object[i] == 'e' || Object[i] == 'E') return 1;
					}
				}
			}
		}
	}
	else {
		cout << "Error, try again" << endl;
	}
	return 0;
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
		while (Object[j] != ' ') j += 1;
		j -= 1;
		Point1 = stof(Object.substr(i, j));
		cout << "Point 1 = " << Point1 << endl;
		i = j + 1;
		while (Object[i] == ' ') i += 1;
		j = i;
		while (Object[j] != ',') j += 1;
		j -= 1;
		Point2 = stof(Object.substr(i, j));
		j += 2;
		i = j;
		while (Object[i] == ' ') i += 1;
		j = i;
		while (Object[j] != ')') j += 1;
		Number = stof(Object.substr(i, j));
		cout << "Point 2 = " << Point2 << endl;
		perimeter = 2 * pi * Number;
		cout << "Perimeter = " << perimeter << endl;
		area = pi * Number * Number;
		cout << "Area = " << perimeter << endl;
		break; }
	case (2):
		cout << "triangle" << endl;
		break;
	case (3):
		cout << "polygon" << endl;
		break;
	}
}