/*It is Jelda who is wearing on green, isn't it?*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 125
#define INF 1e9
#define cluster pair<int, pair<int,int>>
using namespace std;
int t, n;
int graph[MAX][MAX], v[MAX][MAX], d[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dijkstra() {
	priority_queue <cluster, vector<cluster>, greater<cluster>> pq;
	pq.push({ graph[0][0], {0,0} });
	v[0][0] = 1;
	d[0][0] = graph[0][0];
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			int ncost = d[x][y] + graph[nx][ny];
			if (v[nx][ny] == 0 && d[nx][ny] > ncost) {
				d[nx][ny] = ncost;
				v[nx][ny] = 1;
				pq.push({ ncost, {nx,ny} });
			}
		}
	}

}
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		t++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &graph[i][j]);
				d[i][j] = INF;
			}
		}
		dijkstra();
		printf("Problem %d: %d\n", t, d[n - 1][n - 1]);
		memset(v, 0, sizeof(v));
	}
	return 0;
}