#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_VERTICES 7
#define MAX 100

/**
 * Dijkstra Algorithm finding the shorted path
 */
static int dijkstra(int c[][N_VERTICES], const unsigned start)
{
	int dist[N_VERTICES];
	int prior[N_VERTICES];
	int decided[N_VERTICES] = {0};
	int i, j, idx0, idx = start, min;

	/* init */
	for (i = 0; i < N_VERTICES; ++i) {
		dist[i] = c[idx][i];
		prior[i] = start;
	}

	decided[idx] = 1;

	for (j = 0; j < N_VERTICES; ++j) {
#if 1
		for (i = 0; i < N_VERTICES; ++i)
			printf("%d, ", dist[i]);
		printf("\n");
		for (i = 0; i < N_VERTICES; ++i)
			printf("%d, ", prior[i]);
		printf("\n");
		for (i = 0; i < N_VERTICES; ++i)
			printf("%d, ", decided[i]);
		printf("\n-------------------------------\n");
#endif

		idx0 = idx;
		/* refresh dist[] */
		for (i = 0; i < N_VERTICES; ++i) {
			if (decided[i] == 1) {
				continue;
			}

				if ((dist[idx0] + c[idx][i]) < dist[i]) {
					dist[i] = dist[idx0] + c[idx][i];
					prior[i] = idx0;
				}
		}

		/* find minimum */
		min = MAX;
		for (i = 0; i < N_VERTICES; ++i) {
			if (decided[i] == 1) {
				continue;
			}

			if (dist[i] < min) {
				min = dist[i];
				idx = i;
			}
		}

//		prior[idx] = idx0;
		decided[idx] = 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int cost[N_VERTICES][N_VERTICES] = {
		{0, 1, 4, 5, MAX, MAX, MAX},
		{1, 0, MAX, 2, MAX, MAX, MAX},
		{4, MAX, 0, 4, MAX, 3, MAX},
		{5, 2, 4, 0, 5, 2, MAX},
		{MAX, MAX, MAX, 5, 0, MAX, 6},
		{MAX, MAX, 3, 2, MAX, 0, 4},
		{MAX, MAX, MAX, MAX, 6, 4, 0}
	};
	
	if (argc != 2) {
		printf("Usage: %s <start index>\n", argv[0]);
		return 0;
	}
	
	dijkstra(cost, atoi(argv[1]));

	return 0;
}
