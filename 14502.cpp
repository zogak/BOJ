/*laboratory*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 8
using namespace std;
int n, m;
int map[MAX][MAX], tmp[MAX][MAX];
bool v[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> air;
int w1row, w1col, w2row, w2col, w3row, w3col;
int cnt, result;

void virus();
void count();
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				air.push_back(make_pair(i, j));
			}
		}
	}
}
void build(int r1, int c1, int r2, int c2, int r3, int c3) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	memset(v, false, sizeof(v));
	tmp[r1][c1] = 1;
	tmp[r2][c2] = 1;
	tmp[r3][c3] = 1;
	virus();
}
void dfs(int x, int y) {
	tmp[x][y] = 2;
	v[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
			continue;
		}
		if (tmp[nx][ny] == 0 && v[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
void virus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2) {
				dfs(i, j);
			}
		}
	}
	count();
}
void count() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}
	result = max(result, cnt);
}
void pick() {
	int idx = air.size() - 1;
	for (int p = 0; p <= idx - 2; p++) {
		w1row = air[p].first;
		w1col = air[p].second;
		for (int q = p + 1; q <= idx - 1; q++) {
			w2row = air[q].first;
			w2col = air[q].second;
			for (int r = q + 1; r <= idx; r++) {
				w3row = air[r].first;
				w3col = air[r].second;
				build(w1row, w1col, w2row, w2col, w3row, w3col);
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