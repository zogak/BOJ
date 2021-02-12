/*knight*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 300
using namespace std;

int t = 0, m = 0;
int v[MAX][MAX];
int startX = 0, startY = 0, endX = 0, endY = 0;
queue<pair<int, int>> q;
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int cnt = 0, sum = 0;

void bfs(int a, int b) {
	memset(v, 0, sizeof(v));
	sum = 0;
	q.push(make_pair(a, b));
	v[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == endX && y == endY) {
			sum = v[x][y] - 1;
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (int j = 0; j < 8; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= m || ny >= m)
				continue;
			if (v[nx][ny] == 0) {
				v[nx][ny] = v[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}	
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &m);
		scanf("%d %d", &startX, &startY);
		scanf("%d %d", &endX, &endY);
		bfs(startX, startY);
		printf("%d\n", sum);
	}
	return 0;
}