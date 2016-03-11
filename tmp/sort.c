/**
 * sort_insertion.c: insertion sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

static void array_print(const int *a, const unsigned size)
{
	unsigned i;

	for (i = 0; i < size; ++i)
		printf("%d ", a[i]);
	
	printf("\n");
}

static void help_print(char *f)
{
	if (!f) {
		return;
	}


	printf("Usage: %s <sample_size> <opt>\n", f);
	printf("opt: 1 insertion sort\n"
		"     2 merge sort\n"
		"     3 heap sort\n");
}

static int random_sample_get(int *a, const unsigned size)
{
	int ret = -1;
	int *s = NULL;
	unsigned s_size = size;
	unsigned i, j, s_idx;

	s = (int *)malloc(sizeof(int) * size);
	if (!s)	{
		printf("%s@%d Fail to malloc\n", __func__, __LINE__);
		return ret;
	}

	for (i = 0; i < size; ++i)
		s[i] = i + 1;

	srand(time(NULL));
	for (i = 0; i < size; ++i) {
		s_idx = rand() % s_size;
		a[i] = s[s_idx];
		for (j = s_idx + 1; j < s_size; ++j) {
			s[j - 1] = s[j];
		}
		--s_size;
	}

	free(s);

	return 0;
}

static int insertion_sort(int *a, const unsigned size)
{
	int i, j;
	int tmp;

	for (i = 1; i < size; ++i) {
		tmp = a[i];

		for (j = i - 1; j > -1; --j) {
			if (a[j] > tmp)	{
				a[j + 1] = a[j];
				a[j] = tmp;
			} else {
				break;
			}
		}
	}

	return 0;
}


static int merge(int *a, const unsigned s, const unsigned m, const unsigned e)
{
	int *left = NULL, *right = NULL;
	unsigned i, j, k;

	left = (int *)malloc(sizeof(int) * (m - s + 2));
	right = (int *)malloc(sizeof(int) * (e - m + 1));

	if (!left || !right) {
		return -1;
	}

	for (i = s; i <= m; ++i) {
		left[i - s] = a[i];
	}
	left[i - s] = INT_MAX;

	for (i = m + 1; i <= e; ++i) {
		right[i - (m + 1)] = a[i];
	}
	right[i - (m + 1)] = INT_MAX;

	j = k = 0;
	for (i = s; i <= e; ++i) {
		if (left[j] <= right[k])
			a[i] = left[j++];
		else /* left[j] > right[k] */
			a[i] = right[k++];
	}

	free(left);
	free(right);

	return 0;
}

static int merge_sort(int *a, const unsigned s, const unsigned e)
{
	unsigned middle = (s + e) / 2;
	
	if (s >= e) {
		return -1;
	}

	merge_sort(a, s, middle);
	merge_sort(a, middle + 1, e);
	merge(a, s, middle, e);
	
	return 0;
}

static int min_heapify(int *a, const unsigned size, const unsigned idx)
{
	unsigned left = (idx + 1) * 2 - 1;
	unsigned right = left + 1;
	unsigned smallest = idx;
	int tmp;

	if ((left < size) && (a[left] < a[idx])) {
		smallest = left;
	} 

	if ((right <size) && (a[right] < a[smallest])) {
		smallest = right;
	}

	if (smallest != idx) {
		tmp = a[idx];
		a[idx] = a[smallest];
		a[smallest] = tmp;
		min_heapify(a, size, smallest);
	}

	return 0;
}

static int heap_sort(int *a, const unsigned size)
{
	int i;
	int *tmp = NULL, idx = 0;
	
	tmp = (int *) malloc(size * sizeof(int));
	if (!tmp) {
		printf("Fail to malloc\n");
		return -1;
	}

	for (i = size - 1; i > -1; --i) {
		min_heapify(a, size, i);
	}
	
//	array_print(a, size);

	for (i = size - 1; i > -1; --i) {
		tmp[idx++] = a[0]; 
		if (idx == size) {
			break;
		}

		a[0] = a[i];

//		printf("move last:\n");
//		array_print(a, i);
		
		min_heapify(a, i, 0);
		
//		printf("min-heapify:\n");
//		array_print(a, i);
	}

//	array_print(tmp, size);
	memcpy(a, tmp, size * sizeof(int));
#if 0
	for (i = 0; i < size; ++i) {
		a[i] = tmp[i];
	}
#endif
	free(tmp);

	return 0;
}

int main(int argc, char *argv[])
{
	unsigned size = 0;
	int *array = NULL, opt, ret;

	if (argc < 3) {
		//printf("Usage: %s <sample_size> <opt>\n", argv[0]);
		help_print(argv[0]);
		return -1;
	}

	size = atoi(argv[1]);
	opt = atoi(argv[2]);
	array = (int *)malloc(sizeof(int) * size);
	if (!array) {
		printf("%s@%d Fail to malloc\n", __func__, __LINE__);
		return 1;
	}

	if (random_sample_get(array, size)) {
		printf("%s@%d error\n", __func__, __LINE__);
		return 2;
	}

	array_print(array, size);
#if 0
	if (!insertion_sort(array, size))
#elif 0 
	if (!merge_sort(array, 0, size - 1))	
#else
//	if (!heap_sort(array, size))
#endif

	switch (opt) {
		case 0:
			ret = insertion_sort(array, size);
			break;

		case 1:
			ret = merge_sort(array, 0, size - 1);	
			break;

		case 2:
			ret = heap_sort(array, size);
			break;

		default:
			printf("unknown opt %d\n", opt);
			break;
	}

	if (!ret) {
		array_print(array, size);
	}
	
	free(array);

	return 0;
}
