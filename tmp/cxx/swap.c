#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap_double(double *x, double *y)
{
	double tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int m = 5, n = 10;
	double p = 5.3, q = 10.6;

	swap(&m, &n);
	printf("m=%d, n=%d\n", m, n);
	swap_double(&p, &q);
	printf("p=%lf, q=%lf\n", p, q);

	return 0;
}
