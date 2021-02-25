/*finding a number*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;
int n, m;
int arr1[MAX], arr2[MAX], result[MAX];
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}
	sort(arr1, arr1 + n);
}
void binarySearch() {
	for (int i = 0; i < m; i++) {
		int target = arr2[i];
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target < arr1[mid]) {
				right = mid - 1;
			}
			if (target > arr1[mid]) {
				left = mid + 1;
			}
			if (target == arr1[mid]) {
				result[i] = 1;
				break;
			}
		}
	}
}
int main() {
	input();
	binarySearch();
	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}