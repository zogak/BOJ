/*the least number of coins with greedy algorithm*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0, k = 0; // n is sort of coins, k is total amount of coins
	int value = 0; //the value of each coin
	scanf("%d %d", &n, &k); //enter n and k

	int* p = malloc(sizeof(int) * n); // allocate dynamic memory with the size of(sizeof(int) * sizeof(n))
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		p[i] = value;
	}

	int count = 0; // how many coins
	int j = n - 1;
	while (k != 0) {
		if (k >= p[j]) {
			k = k - p[j];
			count++;
		}
		else j--;
	}
	free(p);

	printf("%d", count);
	return 0;
}