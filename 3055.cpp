/*escape*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 50
using namespace std;

int r, c, obj;
int hr, hc;
int map[MAX][MAX], wv[MAX][MAX], hv[MAX][MAX];
queue <pair<int, int>> wq;
queue <pair<int, int>> hq;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int caveR, caveC;
void input() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %1c", &obj);
			if (obj == '.') { //empty
				map[i][j] = 0;
			}
			if (obj == '*') { //water
				map[i][j] = -1;
				wq.push({ i,j });
			}
			if (obj == 'X') { //rock
				map[i][j] = -2;
			}
			if (obj == 'D') { //cave
				map[i][j] = -3;
				caveR = i;
				caveC = j;
			}
			if (obj == 'S') { //hedgehog
				map[i][j] = 1;
				hq.push({ i,j });
			}
		}
	}
}
void hedgeBfs() {
	int hedgeSpot = hq.size();
	while (hedgeSpot != 0) {
		int x = hq.front().first;
		int y = hq.front().second;
		hq.pop();
		hv[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				continue;
			}
			if (hv[nx][ny] == 0 && (map[nx][ny] == 0 || map[nx][ny] == -3)) {
				map[nx][ny] = map[x][y] + 1;
				hv[nx][ny] = 1;
				hq.push({ nx,ny });
			}
		}
		hedgeSpot--;
	}
}
void waterBfs() {
	while (1) {
		if (map[caveR][caveC] != -3) {
			printf("%d", map[caveR][caveC] - 1);
			break;
		}
		if (hq.empty() && wq.empty()) {
			printf("KAKTUS");
			break;
		}
		int waterSpot = wq.size();
		while (waterSpot != 0) {
			int x = wq.front().first;
			int y = wq.front().second;
			wq.pop();
			wv[x][y] = 1;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
					continue;
				}
				if (wv[nx][ny] == 0 && map[nx][ny] == 0) {
					map[nx][ny] = -1;
					wv[nx][ny] = 1;
					wq.push({ nx,ny });
				}
			}
			waterSpot--;
		}
		hedgeBfs();	
	}
}
int main() {
	input();
	waterBfs();
	return 0;
}