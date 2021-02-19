/*pieces of wood*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int n, tmp;
int arr[6];
void print() {
	for (int i = 1; i <= 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	for (int i = 1; i <= 5; i++) {
		scanf("%d", &n);
		arr[i] = n;
	}
	while (1) {
		if (arr[1] == 1 && arr[2] == 2 && arr[3] == 3 && arr[4] == 4 && arr[5] == 5) {
			break;
		}
		if (arr[1] > arr[2]) {
			tmp = arr[2];
			arr[2] = arr[1];
			arr[1] = tmp;
			print();
		}
		if (arr[2] > arr[3]) {
			tmp = arr[3];
			arr[3] = arr[2];
			arr[2] = tmp;
			print();
		}
		if (arr[3] > arr[4]) {
			tmp = arr[4];
			arr[4] = arr[3];
			arr[3] = tmp;
			print();
		}
		if (arr[4] > arr[5]) {
			tmp = arr[5];
			arr[5] = arr[4];
			arr[4] = tmp;
			print();
		}
	}

	return 0;
}