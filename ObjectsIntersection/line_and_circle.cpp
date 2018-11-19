#include <iostream>
#include <cmath>

using namespace std;

/*
	Пересечение прямой (Ax + By + C = 0) и окружности (x - x0)^2 + (y - y0)^2 = r^2
	Входные данные: a, b, c, x0, y0, r, 
	Выходные данные: количество точек пересечения и точки пересечения
*/

int main() {
	double a, b, c; // параметры прямой
	double x0, y0, r; // параметры окружности

	cout << "Enter a, b, c: ";
	cin >> a >> b >> c; // вводим параметры прямой

	cout << "Enter x0, y0, r: ";
	cin >> x0 >> y0 >> r; // вводим параметры окружности

	while (r <= 0) {
		cout << "r is incorrect! Try again: ";
		cin >> r;
	}

	// считая, что коружность в начале координат, сдвинем прямую, чтобы сохранить точки
	c += a * x0 + b * y0;

	// теперь есть окружность с центром в начале координат радиуса r и прямая ax + by + c = 0
	double x_0 = -a * c / (a * a + b * b) + x0;
	double y_0 = -b * c / (a * a + b * b) + y0;

	double d = r * r - c * c / (a * a + b * b);

	// если дискриминант отрицателен
	if (d < 0) {
		cout << "no points" << endl; // нет точек пересечения
	}
	else if (d == 0) { // если нулевой, то только одна точка пересечения
		double x1 = x_0;
		double y1 = y_0;

		cout << "1 point: (" << x1 << ", " << y1 << ")" << endl;
	}
	else { // иначе две точки пересечения
		d = sqrt(d / (a * a + b * b));

		double x1 = x_0 + b * d;
		double x2 = x_0 - b * d;

		double y1 = y_0 - a * d;
		double y2 = y_0 + a * d;

		cout << "2 points: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << endl;
	}
}