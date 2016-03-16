/** josephus.c: Josephus Problem with k = 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 3
#define UPPER_BOUND 100

typedef struct _Que {
	unsigned head;
	unsigned tail;
	unsigned size;
	unsigned *array;
} Que;

int enqueue(Que *que, unsigned val)
{
	unsigned tmp = (que->tail + 1) % que->size;

	if (que->head == tmp) {
//		printf("Queue is full. size=%d\n", que->size);
		return -1;
	}
	
//	printf("enqueue [%d] val %d\n", que->tail, val);
	que->array[que->tail] = val;
	que->tail = tmp;

	return 0;
}

int dequeue(Que *que, unsigned *val)
{
	unsigned tmp = (que->head + 1) % que->size;

	if (que->head == que->tail) {
//		printf("Queue is empty\n");
		return -1;
	}

//	printf("dequeue [%d] val %d\n", que->head, que->array[que->head]);
	
	if (val) {
		*val = que->array[que->head];
	}
	
	que->head = tmp;

	return 0;
}

int josephus(Que *que, unsigned *idx)
{
	int ret = 0, i;
//	unsigned val;
	unsigned val[K - 1] = {0};

	while (1) {
//		ret = dequeue(que, &val);
		i = 0;
		do {
			ret = dequeue(que, &val[i++]);
			if (ret) {
				printf("Unexpected error\n");
//				break;
				return -1;
			}
		} while (i < (K - 1));

		ret = dequeue(que, NULL);
		if (ret) {
//			printf("Survivor: %d\n", val);
			if (idx) {
//				*idx = val;
				*idx = val[i - 1];
			}
			ret = 0;
			break;
		}

		i = 0;
		do {
//			ret = enqueue(que, val);
			ret = enqueue(que, val[i++]);
			if (ret) {
				printf("Unexpected error\n");
//				break;
				return -2;
			}
		} while (i < (K - 1));
	}

	return ret;
}

int main(int argc, char *argv[])
{
	Que *queue;
	int i, j;
	unsigned survivor;

	queue = (Que *) malloc(sizeof (struct _Que));
	if (!queue) {
		printf("Fail to malloc at line %d\n", __LINE__);
		return 1;
	}
	memset(queue, 0, sizeof(struct _Que));
	
	printf("Print a tabulated of Josephus Problem\n");

	queue->array = (unsigned *) malloc(UPPER_BOUND * sizeof(unsigned));
	if (!queue->array) {
		printf("Fail to malloc at line %d\n", __LINE__);
		return 1;
	}

	for (i = 1; i < 17; ++i) {
		/* init */
		queue->head = queue->tail = 0;
		queue->size = i + 1;
		j = 0;
		while(!enqueue(queue, ++j));

		if (!josephus(queue, &survivor)) {
			printf("%d; survivor: %d\n", i, survivor);
		}
	}	

	free(queue->array);
	free(queue);

	return 0;
}
