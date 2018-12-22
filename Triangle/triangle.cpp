#include <iostream>
#include <cmath>

using namespace std;

// точка на плоскости
struct Point {
	double x;
	double y;
};

// тип треугольника
enum class TriangleType {
	acute, // остроугольный
	right, // прямоугольный
	obtuse // тупоугольный
};

// существует ли треугольник со сторонами a, b, c
bool isTriangle(double a, double b, double c) {
	return a + b > c && a + c > b && b + c > a;
}

// существует ли треугольник на точках a, b, c
bool isTriangle(Point a, Point b, Point c) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point ac = { c.x - a.x, c.y - a.y };

	return ab.x * ac.y - ab.y * ac.x != 0;
}

// определение типа треугольника по трём сторонам
TriangleType typeTriangle(double a, double b, double c) {
	// находим большую сторону треугольника
	if (b > a && b > c) {
		double tmp = a;
		a = b;
		b = tmp;
	}
	else if (c > a && c > b) {
		double tmp = a;
		a = c;
		c = tmp;
	}

	double v = a * a - b * b - c * c; // находим a^2 - (b^2 + c^2)

	if (v < 0)
		return TriangleType::acute; // остроугольный

	if (v > 0)
		return TriangleType::obtuse; // тупоугольный

	return TriangleType::right; // прямоугольный
}

// определение типа треугольника по трём точкам
TriangleType typeTriangle(Point a, Point b, Point c) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point ac = { c.x - a.x, c.y - a.y };
	Point bc = { c.x - b.x, c.y - b.y };

	// находим все три скалярных произведения
	double p1 = ab.x * ac.x + ab.y * ac.y;
	double p2 = ab.x * bc.x + ab.y * bc.y;
	double p3 = bc.x * ac.x + bc.y * ac.y;

	double p = p1 * p2 * p3;

	if (p < 0)
		return TriangleType::acute; // остроугольный

	if (p > 0)
		return TriangleType::obtuse; // тупоугольный

	return TriangleType::right; // прямоугольный
}

// площадь треугольника по трём сторонам
double squareTriangle(double a, double b, double c) {
	double p = (a + b + c) / 2; // полупериметр

	return sqrt(p * (p - a) * (p - b) * (p - c)); // формула Герона
}

// площадь треугольника по трём точкам
double squareTriangle(Point a, Point b, Point c) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point ac = { c.x - a.x, c.y - a.y };

	return fabs(ab.x * ac.y - ab.y * ac.x) / 2; // половина площади параллелограма
}

// центр вписанной окружности в треугольник
Point centerInscribedCircle(Point a, Point b, Point c) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point bc = { c.x - b.x, c.y - b.y };
	Point ca = { a.x - c.x, a.y - c.y };

	double lab = sqrt(ab.x * ab.x + ab.y * ab.y);
	double lbc = sqrt(bc.x * bc.x + bc.y * bc.y);
	double lca = sqrt(ca.x * ca.x + ca.y * ca.y);

	double len = 1 / (lab + lbc + lca);

	lab *= len;
	lbc *= len;
	lca *= len;

	Point o;

	o.x = a.x * lbc + b.x * lca + c.x * lab;
	o.y = a.y * lbc + b.y * lca + c.y * lab;

	return o;
}

// центр вписанной окружности в треугольник и радиус
Point centerInscribedCircle(Point a, Point b, Point c, double &r) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point bc = { c.x - b.x, c.y - b.y };
	Point ca = { a.x - c.x, a.y - c.y };

	double lab = sqrt(ab.x * ab.x + ab.y * ab.y);
	double lbc = sqrt(bc.x * bc.x + bc.y * bc.y);
	double lca = sqrt(ca.x * ca.x + ca.y * ca.y);

	double len = 1 / (lab + lbc + lca);

	lab *= len;
	lbc *= len;
	lca *= len;

	Point o;

	o.x = a.x * lbc + b.x * lca + c.x * lab;
	o.y = a.y * lbc + b.y * lca + c.y * lab;

	r = fabs(len * (ab.x * bc.y - ab.y * bc.x));

	return o;
}

// центр описанной окружности около треугольника
Point centerCircumscribedCircle(Point a, Point b, Point c) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point ac = { c.x - a.x, c.y - a.y };

	double d = 2 * (ab.x * ac.y - ab.y * ac.x);

	double sq_ab = ab.x * ab.x + ab.y * ab.y;
	double sq_ac = ac.x * ac.x + ac.y * ac.y;

	Point o;

	o.x = (ac.y * sq_ab - ab.y * sq_ac) / d;
	o.y = (ab.x * sq_ac - ac.x * sq_ab) / d;

	return o;
}

// центр описанной окружности около треугольника
Point centerCircumscribedCircle(Point a, Point b, Point c, double &R) {
	Point ab = { b.x - a.x, b.y - a.y };
	Point ac = { c.x - a.x, c.y - a.y };

	double d = 2 * (ab.x * ac.y - ab.y * ac.x);

	double sq_ab = ab.x * ab.x + ab.y * ab.y;
	double sq_ac = ac.x * ac.x + ac.y * ac.y;

	Point o;

	o.x = (ac.y * sq_ab - ab.y * sq_ac) / d;
	o.y = (ab.x * sq_ac - ac.x * sq_ab) / d;

	R = sqrt((a.x - o.x) * (a.x - o.x) + (a.y - o.y) * (a.y - o.y));

	return o;
}

int main() {
	Point a, b, c;

	cout << "Enter point a: ";
	cin >> a.x >> a.y;

	cout << "Enter point b: ";
	cin >> b.x >> b.y;

	cout << "Enter point c: ";
	cin >> c.x >> c.y;

	if (!isTriangle(a, b, c)) {
		cout << "It is not a triangle!" << endl;
	}
	else {
		TriangleType type = typeTriangle(a, b, c);

		cout << "    type: ";

		if (type == TriangleType::acute) {
			cout << "acute" << endl;
		}
		else if (type == TriangleType::right) {
			cout << "right" << endl;
		}
		else {
			cout << "obtuse" << endl;
		}

		cout << "    square: " << squareTriangle(a, b, c) << endl;

		double r, R;
		Point Cr = centerInscribedCircle(a, b, c, r);
		Point CR = centerCircumscribedCircle(a, b, c, R);

		cout << "    Cr: " << Cr.x << " " << Cr.y << endl;
		cout << "    CR: " << CR.x << " " << CR.y << endl;
		cout << "    r: " << r << endl;
		cout << "    R: " << R << endl;
	}
}