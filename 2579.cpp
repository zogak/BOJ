/*climbing stairs*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 301
using namespace std;

int s[MAX];
int dp[MAX];
int t, score;
void input() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &score);
		s[i] = score;
	}
}
int main() {
	input();
	dp[1] = s[1];
	dp[2] = s[1] + s[2];
	dp[3] = max(s[1] + s[3], s[2] + s[3]);

	for (int i = 4; i <= t; i++) {
		dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
	}
	printf("%d", dp[t]);
	return 0;
}