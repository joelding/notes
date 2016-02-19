//#include <stdio.h>
#include <iostream>
#include <complex>

using namespace std;

template <class T>
//void myswap(int *x, int *y)
void myswap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int m = 5, n = 10;
	double p = 5.3, q = 10.6;
	complex<double> r(2.4, 3.5), s(3.4, 6.7);

	myswap(m, n);
	cout << "m=" << m << ", n=" << n << endl;
	myswap(p, q);
	cout << "p=" << p << ", q=" << q << endl;
	myswap(r, s);
	cout << "r=" << r << ", s=" << s << endl;

	return 0;
}
