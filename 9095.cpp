/*plus 1,2,3*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int t, n;
int dp[11];
void dynamic(int n) {
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}
int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	scanf("%d", &t);
	while (t) {
		scanf("%d", &n);
		dynamic(n);
		printf("%d\n", dp[n]);
		t--;
	}
}