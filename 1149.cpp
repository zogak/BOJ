/*RGB distance*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 1001
using namespace std;
int n, r, g, b, result;
int map[MAX][3];
void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		if (i == 1) {
			map[i][0] = r;
			map[i][1] = g;
			map[i][2] = b;
		}
		else {
			map[i][0] = r + min(map[i - 1][1], map[i - 1][2]);
			map[i][1] = g + min(map[i - 1][0], map[i - 1][2]);
			map[i][2] = b + min(map[i - 1][0], map[i - 1][1]);
		}
	}
}
int main() {
	input();
	result = min(map[n][2], min(map[n][0], map[n][1]));
	printf("%d", result);
	return 0;
}