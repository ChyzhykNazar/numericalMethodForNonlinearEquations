/*TASK*/
/*To find solution of equation f(x) = (x - g * k)^2 + sin(x - g * k) = 0
(where g and k any numbers, start - begin of segment, end - end of segment, eps - precision) using bisection method, chord method, newton method*/
/*Знайти розв'язок рівняння f(x) = (x - g * k)^2 + sin(x - g * k) = 0
(де g і k будь-які цифри, start - початок відрізка, end - кінець відрізка, eps - точність) використовуючи метод половинного ділення, метод хорд, метод Ньютона*/

/*To find solution of equation f(x) = (10 * g + sin(x-(10 * g / k)) / k= 0
(where g and k any numbers, start - begin of segment, end - end of segment, eps - precision) using iteration method*/
/*Знайти розв'язок рівняння f(x) = (10 * g + sin(x-(10 * g / k)) / k = 0
(де g і k будь-які цифри, start - початок відрізка, end - кінець відрізка, eps - точність) використовуючи ітераційний метод*/


#include <iostream>
#include <math.h>

using namespace std;

float func1(float x, int g, int k) {
	return pow((x - g * k), 2.0) + sin(x - g * k);
}

float func2(float x, int g, int k) {
	return (10 * (float)g + sin(x - (10 * (float)g / (float)k))) / (float)k;

}

float df1(float x, int g, int k) {
	return 2 * x - 126 + cos(x - g * k);
}

float df2(float x, int g, int k) {
	return 2 - sin(x - g * k);
}

void bisection(float start, float end, int g, int k, float eps) {
	float c;
	cout << endl << "Bisection method" << endl;
	do
	{
		c = (start + end) / 2;
		if (func1(c, g, k) == 0) {
			break;
		}
		if (func1(c, g, k) * func1(start, g, k) < 0)
			end = c;
		else {
			start = c;

		}
	} while (abs(end - start) > eps);
	cout << "x=" << c << endl;
}

void chord(float start, float end, int g, int k, float eps) {
	cout << endl << "Chord method" << endl;
	float x1;
	float x2;
	x1 = start - ((func1(start, g, k) * (end - start)) / (func1(end, g, k) - func1(start, g, k)));
	if (func1(x1, g, k) == 0) {
		cout << "x = " << x1 << endl;
		return;
	}
	else if (func1(start, g, k) * func1(x1, g, k) < 0) {
		end = x1;
	}
	else if (func1(end, g, k) * func1(x1, g, k) > 0) {
		start = x1;
	}
	do {
		x2 = x1;
		x1 = start - ((func1(start, g, k) * (end - start)) / (func1(end, g, k) - func1(start, g, k)));
		if (func1(x1, g, k) == 0) {
			cout << "x = " << x1 << endl;
		}
		else if (func1(start, g, k) * func1(x1, g, k) < 0) {
			end = x1;
		}
		else if (func1(end, g, k) * func1(x1, g, k) > 0) {
			start = x1;
		}
	} while (fabs(x1 - x2) > eps);


	cout << "x = " << x1 << endl;
}

void newton(float start, float end, int g, int k, float eps) {
	cout << endl << "Newton method" << endl;
	float x0 = 0;
	float x1 = 0;
	if (func1(start, g, k) * df2(start, g, k) > 0) {
		x0 = start;
	}
	else if (func1(end, g, k) * df2(end, g, k) > 0) {
		x0 = end;
	}
	do {
		x1 = x0;
		x0 = x1 - (func1(x1, g, k) / df1(x1, g, k));
	} while (fabs(x0 - x1) > eps);
	cout << "x = " << x0 << endl << endl;
}

void iteration(float start, float end, int g, int k, float eps) {
	cout << "Itertation method" << endl;
	float x0 = (start + end) / 2;
	float x1;
	do
	{
		x1 = x0;
		x0 = func2(x1, g, k);
	} while (fabs(x0 - x1) > eps);
	cout << "x: " << x0 << endl;
}


int main()
{
	int g = 9;
	int k = 7;
	float start;
	float end;
	float eps = 0.01;
	cout << "Start =";
	cin >> start;
	cout << "End =";
	cin >> end;
	bisection(start, end, g, k, eps);
	chord(start, end, g, k, eps);
	newton(start, end, g, k, eps);
	cout << "Start =";
	cin >> start;
	cout << "End =";
	cin >> end;
	iteration(start, end, g, k, eps);
}