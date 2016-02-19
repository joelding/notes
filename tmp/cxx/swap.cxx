//#include <stdio.h>
#include <iostream>

//void swap(int *x, int *y)
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void swap(double &x, double &y)
{
	double tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int m = 5, n = 10;
	double p = 5.3, q = 10.6;

	swap(m, n);
	std::cout << "m=" << m << ", n=" << n << std::endl;
	swap(p, q);
	std::cout << "p=" << p << ", q=" << q << std::endl;

	return 0;
}
