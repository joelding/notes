//#include <stdio.h>
#include <iostream>
//#include <stdlib.h>
#include <cstdlib>
//#include <time.h>
#include <ctime>

//#define SIDES 6
const int SIDES = 6;
//#define R_SIDE (rand() % SIDES + 1)
inline int R_SIDE() { return (rand() % SIDES + 1); }
//#define n_dice 2

using namespace std;

int main(int argc, char *argv[])
{
	const int n_dice = 2;
	int trials = 0, d1, d2;
	int outcomes[n_dice * SIDES] = {0};

	srand(clock());
//	printf("\nEnter number of trials: ");
	cout << "\nEnter number of trials: ";
//	scanf("%d", &trials);
	cin >> trials;

	for (int j = 0; j < trials; ++j) {
		outcomes[(d1 = R_SIDE()) + (d2 = R_SIDE())]++;
//		printf("d1 = %d, d2 = %d, sum = %d\n", d1, d2, d1 + d2);
	}

	for (int j = 2; j < n_dice * SIDES + 1; ++j) {
//		printf("j = %d, p = %lf\n", j, (double)outcomes[j] / trials);
		cout << "j = " << j
			<< "p = " << static_cast<double>(outcomes[j]) / trials
			<< " " << endl;
	}

	cout << "sizeof(int) = " << sizeof(SIDES) << endl;
	return 0;
}
