#include <iostream>

using namespace std;
template <class T>
static T sum(T a[], int size, T initial = 0)
{
	T ret = initial;

	for (int i = 0; i < size; ++i)
		ret += a[i];

	return ret;
}

int main(int argc, char *argv[])
{
	cout << "template for sum()" << endl;
	int a[] = {1, 2, 3};
	double b[] = {2.1, 2.2, 2.3};
	cout << sum(a, 3) << endl;
	cout << sum(b, 3) << endl;

	return 0;
}
