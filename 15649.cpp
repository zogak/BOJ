/*n&m*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 8
using namespace std;
int n, m;
int arr[MAX];
int result[MAX];
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
}
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			result[cnt] = arr[i];
			dfs(cnt + 1);
		}
	}
}
int main() {
	input();
	dfs(0);
	return 0;
}