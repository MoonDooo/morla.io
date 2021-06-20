#include<stdio.h>	
int size, i = 0;

int partition(int a[], int begin, int end) {
	int pivot, l, r, t;
	int temp;
	l = begin;
	r = end;
	pivot = end;
	printf("\n[ %d단계 피봇 : %d ]\n", ++i, a[pivot]);
	while (l < r) {
		while ((a[l]) < a[pivot] && (l <= r)) l++;
		while ((a[r] > a[pivot]) && (l <= r)) r--;
		if (l < r) {
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			if (l == pivot)
				pivot = r;
		}
	}
	temp = a[pivot];
	a[pivot] = a[r];
	a[r] = temp;
	for (t = 0; t < size; t++)	printf("\t%d", a[t]);
	printf("\n");
	return r;
}
void quicksort(int a[], int begin, int end) {
	int p;
	if(begin < end) {
		p = partition(a, begin, end);
		quicksort(a, begin, p - 1);
		quicksort(a, p + 1, end);
	}
}
int main() {
	int sort[10];
	size = 10;
	for (int x = 0; x < 10; x++) {
		printf("입력 : ");
		scanf("%d", &sort[x]);
	}
	printf("초기상태\n");
	for (int q = 0; q < size; q++)printf(" %d", sort[q]);
	quicksort(sort, 0, size - 1);
	return 0;
}
