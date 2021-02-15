/*blackjack*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 101
using namespace std;
int n, m;
int card1, card2, card3;
int c[MAX];
int sum, result;
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
}
void pick() {
	for (int p = 1; p <= n - 2; p++) {
		card1 = c[p];
		for (int q = p + 1; q <= n - 1; q++) {
			card2 = c[q];
			for (int r = q + 1; r <= n; r++) {
				card3 = c[r];
				sum = card1 + card2 + card3;
				if (sum <= m) {
					result = max(result, sum);
				}
			}
		}
	}
}
int main() {
	input();
	pick();
	printf("%d", result);
	return 0;
}