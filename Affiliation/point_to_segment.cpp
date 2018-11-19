#include <iostream>

using namespace std;

/*
	Принадлежность точки (x, y) отрезку (x1, y1), (x2, y2)
	Входные данные: x, y, x1, y1, x2, y2
	Выходные данные: точка принадлежит или не принадлежит
*/

int main() {
	double x, y; // координаты проверяемой точки
	double x1, y1, x2, y2; // параметры прямой

	cout << "Enter x, y: ";
	cin >> x >> y; // вводим параметры точки
	cout << "Enter x1, y1, x2, y2: ";
	cin >> x1 >> y1 >> x2 >> y2; // вводим параметры отрезка

	while (x1 == x2 && y1 == y2) {
		cout << "Incorrect segment! Try again: ";
		cin >> x1 >> y1 >> x2 >> y2; // заново вводим параметры отрезка
	}

	double p;

	if (x1 == x2) {
		p = (y - y2) / (y1 - y2);

		if (p >= 0 && p <= 1 && x2 == x) {
			cout << "point belongs segment" << endl;
		}
		else {
			cout << "point does not belong segment" << endl;	
		}
	}
	else {
		p = (x - x2) / (x1 - x2);

		if (p >= 0 && p <= 1 && (p * (y1 - y2) + y2) == y) {
			cout << "point belongs segment" << endl;
		}
		else {
			cout << "point does not belong segment" << endl;	
		}
	}
}