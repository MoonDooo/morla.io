#include<stdio.h>
int i = 0; int size = 8;
int space_b = 0;
int space_e;

void print_space_no_b(int a[], int begin, int end) {
	for (int i = begin; i < end + 1; i++) {
		printf("%3d|", a[i]);
	}
	printf("\n");
	for (int i = begin; i < end + 1; i++) {
		if ((space_b == i) && (space_e == i)) {
			printf("%3s|", "be");
		}
		else if (space_b == i) {
			printf("%3c|", 'b');
		}
		else if (space_e == i) {
			printf("%3c|", 'e');
		}
		else {
			printf("%4c", '|');
		}
	}
}
int partition(int a[], int begin, int end) {
	space_e = end;
	space_b = begin;
	int temp;
	int b = begin;
	int e = end;
	int pivot = end;
	printf("\n<%d단계 최초 pivot은 sort[%d]=%d>", ++i, pivot, a[pivot]);
	printf("\n<파티션 sort[%d]부터 sort[%d]까지 분활>\n", begin, end);
	for (int i = begin; i < end + 1; i++) {
		printf("%3d|", a[i]);
	}
	while (b < e) {
		while ((b < e) && (a[b] < a[pivot])) {
			printf("\n%d는 %d보다 작으므로 b 한칸 이동.\n", a[b], a[pivot]);
			space_b++;
			b++;
			print_space_no_b(a, begin, end);
		}
		while ((b < e) && (a[e] >= a[pivot])) { 
			if (a[e] == a[pivot]) {
				printf("\n%d는 %d와 같으므로 e 한칸 이동.\n", a[e], a[pivot]);
			}
			else {
				printf("\n%d는 %d보다 크므로 e 한칸 이동.\n", a[e], a[pivot]);
			}
			space_e--;
			print_space_no_b(a, begin, end);
			e--; 
		}
		if (b == e) {
			printf("\nb가 e보다 큽니다.");
		}
		else {
			printf("\n\nsort[b] = %d와 sort[e] = %d교환\n", a[b], a[e]);
		}
		temp = a[b];
		a[b] = a[e];
		a[e] = temp;
		if (b == pivot) {
			pivot = e;
		}
	}
	printf("\nsort[pivot] = %d와 sort[e] = %d교환\n", a[pivot], a[e]);
	for (int i = begin; i < end + 1; i++) {
		printf("%3d|", a[i]);
	}
	temp = a[pivot];
	a[pivot] = a[e];
	a[e] = temp;
	printf("\n파티션 함수에서 반환한 값 sort[%d] = %d", e, a[e]);
	printf("\n<%d단계 마친 후 배열 (pivot은 %d)>\n",i, a[e]);
	for (int i = 0; i < 8; i++) {
		printf("%3d|", a[i]);
	}
	printf("\n\n");
	return e;
}
void quick(int a[], int begin, int end) {
	if (begin < end) {
		int q = partition(a, begin, end);
		quick(a, q + 1, end);
		quick(a, begin, q - 1);
	}
}
int main() {
	printf("b는 파티션의 시작지점(begin) e는 파티션의 끝지점(end)\npivot은 (b + e) /2 로 설정하였을때\nb가 e보다 커질때까지 파티션 함수를 실행하여 피봇 기준 왼쪽은 피봇이 가진 수 보다 작은 수가 오른쪽은 피봇이 가진 수 보다 큰 값을 갖고 함수가 마치면 오른쪽과 왼쪽을 서로 파티션을 나뉘어 위의 내용을 반복합니다.");
	int sort[8] = { 0, 1,2,3,4,5,6,7 };
	quick(sort, 0, size - 1);
	return 0;
}


