/*select the number*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 5000

using namespace std;
int num[MAX];
int result = 0;

int main() {
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num + n);

	for (int i = 0; i < k; i++) {
		result += num[n-1-i] - i;
	}

	printf("%d ", result);
	return 0;
}