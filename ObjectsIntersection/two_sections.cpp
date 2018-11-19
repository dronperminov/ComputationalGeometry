#include <iostream>
#include <cmath>

using namespace std;

/*
	Пересечение двух отрезков, заданных координатами концов
	Входные данные: x1, y1, x2, y2, x3, y3, x4, y4
	Выходные данные: точка пересечения, если есть
*/

int main() {
	double x1, y1, x2, y2; // параметры первого отрезка
	double x3, y3, x4, y4; // параметры второго отрезка

	cout << "Enter x1, y1, x2, y2: ";
	cin >> x1 >> y1 >> x2 >> y2; // считываем параметры первого отрезка

	cout << "Enter x3, y3, x4, y4: ";
	cin >> x3 >> y3 >> x4 >> y4; // считываем параметры второго отрезка

	if ((x1 == x3 && y1 == y3 && x2 == x4 && y2 == y4) || (x1 == x4 && y1 == y4 && x2 == x3 && y2 == y3)) {
		cout << "segments cincide" << endl;
	}
	else if ((x1 == x3 && y1 == y3) || (x1 == x4 && y1 == y4)) { // если первая точка первого отрезка совпадает с одной из точек второго отрезка
		cout << "touch: (" << x1 << ", " << y1 << ")" << endl;
	}
	else if ((x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4)) { // если вторая точка первого отрезка совпадает с одной из точек второго отрезка
		cout << "touch: (" << x2 << ", " << y2 << ")" << endl;
	}
	else {
		double AB_x = x2 - x1;
		double AB_y = y2 - y1;

		double AC_x = x3 - x1;
		double AC_y = y3 - y1;

		double AD_x = x4 - x1;
		double AD_y = y4 - y1;

		double z1 = AB_x * AC_y - AB_y * AC_x;
		double z2 = AB_x * AD_y - AB_y * AD_x;

		cout << "z1: " << z1 << ", z2: " << z2 << endl;

		if (z1 * z2 > 0 || z1 == 0 || z2 == 0) {
			cout << "no points" << endl;
		}
		else {
			double CD_x = x4 - x3;
			double CD_y = y4 - y3;

			double CA_x = x4 - x1;
			double CA_y = y4 - y1;

			double CB_x = x4 - x2;
			double CB_y = y4 - y2;

			z1 = CD_x * CA_y - CD_y * CA_x;
			z2 = CD_x * CB_y - CD_y * CB_x;

			cout << "z1: " << z1 << ", z2: " << z2 << endl;

			if (z1 * z2 > 0 || z1 == 0 || z2 == 0) {
				cout << "no points" << endl;
			}
			else {
				double x = x1 + (x2 - x1) * fabs(z1 / (z2 - z1));
				double y = y1 + (y2 - y1) * fabs(z1 / (z2 - z1));

				cout << "intersect: (" << x << ", " << y << ")" << endl;
			}
		}
	}
}