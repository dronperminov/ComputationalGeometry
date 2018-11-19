#include <iostream>
#include <cmath>

using namespace std;

/*
	Пересечение двух окружностей
	Входные данные: x1, y1, r1, x2, y2, r2
	Выходные данные: количество точек пересечения и точки пересечения
*/

int main() {
	double x1, y1, r1; // параметры первой окружности
	double x2, y2, r2; // параметры второй окружности

	cout << "Enter x1, y1, r1: ";
	cin >> x1 >> y1 >> r1; // считываем параметры первой окружности

	// обрабатываем некорректный ввод
	while (r1 <= 0) {
		cout << "r1 is incorrect! Try again: ";
		cin >> r1;
	}

	cout << "Enter x2, y2, r2: ";
	cin >> x2 >> y2 >> r2; // считываем параметры второй окружности

	// обрабатываем некорректный ввод
	while (r2 <= 0) {
		cout << "r2 is incorrect! Try again: ";
		cin >> r2;
	}

	// центр второй окружности, если бы первая окружность была в (0, 0)
	double Xp2 = x2 - x1;
	double Yp2 = y2 - y1;

	double c = (r2 * r2 - r1 * r1 - Xp2 * Xp2 - Yp2 * Yp2) / (-2);

	// если центры окружностей совпадают
	if (x1 == x2 && y1 == y2) {
		if (r1 == r2) { // если и радиусы совпадают
			cout << "infinity points!" << endl; // точек бесконечное число
		}
		else {
			cout << "no points!" << endl; // иначе окружности вписаны, пересечений нет
		}
	}
	else if (Xp2 != 0) {
		double a = Yp2 * Yp2 + Xp2 * Xp2;
		double b = -2 * Yp2 * c;
		double e = c*c - r1 * r1 * Xp2 * Xp2;

		double D = b * b - 4 * a * e; // вычисляем дискриминант

		// если он меньше 0, значит решений нет, как и точек
		if (D < 0) {
			cout << "no points" << endl;
		}
		else if (D == 0) { // если дискриминант равен нулю, то одна точка пересечения
			double y = -b / (2 * a) ;
			double x = (c - y * Yp2) / Xp2;
			cout << "1 point: (" << (x) << " " << (y) << ")" << endl;
		}
		else { // иначе две точки пересечения
			double y_1 = (-b - sqrt(D)) / (2 * a) ;
			double y_2 = (-b + sqrt(D)) / (2 * a);
			double x_1 = (c - y_1 * Yp2) / Xp2;
			double x_2 = (c - y_2 * Yp2) / Xp2;

			cout << "2 points: (" << (x_1 + x1) << " " << (y_1 + y1) << "), (" << (x_2 + x1) << " " << (y_2 + y1) << ")" << endl;
		}
	}
	else {
		double D = r1 * r1 - (c * c) / (Yp2 * Yp2); // если Xp2 = 0, то вычисляем дискриминант иначе

		// если он отрицательный
		if (D < 0) {
			cout << "no points" << endl; // точек нет
		}
		else if (D == 0) { // если нулевой, то одна точка
			double x = x1;
			double y = c / Yp2 + y1;

			cout << "1 point: (" << (x) << " " << (y) << ")" << endl;
		}
		else { // иначе две точки
			double y = c / Yp2;
			double x_1 = sqrt(D);
			double x_2 = -sqrt(D);

			cout << "2 points: (" << (x_1 + x1) << " " << (y + y1) << "), (" << (x_2 + x1) << " " << (y + y1) << ")" << endl;
		}
	}
}