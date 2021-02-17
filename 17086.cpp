/*baby shark2*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 50
using namespace std;
int n, m, a, ans;
int map[MAX][MAX], v[MAX][MAX];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a);
			if (a == 0) {
				map[i][j] = MAX;
			}
			else {
				map[i][j] = 1;
			}
		}
	}
}
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	v[a][b] = 1;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}
			if (map[nx][ny] != 1 && v[nx][ny] == 0) {
				map[nx][ny] = min(map[nx][ny], map[x][y] + 1);
				v[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, map[i][j]);
		}
	}
	printf("%d", ans - 1);
}
int main() {
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				memset(v, 0, sizeof(v));
			}
		}
	}
	print();
	return 0;
}