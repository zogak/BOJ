/*global warming*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 10
using namespace std;
int r, c;
char map[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt, minRow, maxRow, minCol, maxCol;
void input() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
}
void bfs(int x, int y) {
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == '.' || nx < 0 || ny < 0 || nx >= r || ny >= c) {
			cnt++;
		}
	}
	if (cnt >= 3) {
		map[x][y] = 'S';
	}
}
void after50() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') {
				map[i][j] = '.';
			}
		}
	}
}
void print() {
	minRow = MAX;
	minCol = MAX;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X') {
				minRow = min(i, minRow);
				maxRow = max(i, maxRow);
				minCol = min(j, minCol);
				maxCol = max(j, maxCol);
			}
		}
	}
	for (int i = minRow; i <= maxRow; i++) {
		for (int j = minCol; j <= maxCol; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
int main() {
	input();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X') {
				bfs(i, j);
			}
		}
	}
	after50();
	print();
	return 0;
}