#include <iostream>

using namespace std;

/*
	Принадлежность точки (x, y) прямой (Ax + By + C = 0)
	Входные данные: x, y, A, B, C
	Выходные данные: точка принадлежит или не принадлежит
*/

int main() {
	double x, y; // координаты проверяемой точки
	double a, b, c; // параметры прямой

	cout << "Enter x, y: ";
	cin >> x >> y; // вводим параметры точки
	cout << "Enter a, b, c: ";
	cin >> a >> b >> c; // вводим параметры прямой

	// если при подстановке точки в уравнение прямой получился ноль, то точка принадлежит
	if (a * x + b * y + c == 0) {
		cout << "point (" << x << ", " << y << ") belongs line " << endl;
	}
	else {
		cout << "point (" << x << ", " << y << ") does not belong line " << endl;
	}
}