#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)
#define n_dice 2

int main(int argc, char *argv[])
{
	int trials = 0, j, d1, d2;
	int outcomes[n_dice * SIDES] = {0};

	srand(clock());
	printf("\nEnter number of trials: ");
	scanf("%d", &trials);

	for (j = 0; j < trials; ++j) {
		outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++;
//		printf("d1 = %d, d2 = %d, sum = %d\n", d1, d2, d1 + d2);
	}

	for (j = 2; j < n_dice * SIDES + 1; ++j) {
		printf("j = %d, p = %lf\n", j, (double)outcomes[j] / trials);
	}

	return 0;
}
